/* Generic hashmap by Andreas Pfohl (@apfohl) */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef HASHMAP_INITIAL_CAPACITY
#define HASHMAP_INITIAL_CAPACITY 32 ///< default hashmap init capacity
#endif

struct hashmap *clone_and_double(struct hashmap *);

/**
 * Hashmap entry structure
 */
struct hashmap_entry {
    char *key;
    void *value;
};

/**
 * Hashmap structure
 */
struct hashmap {
    int capacity;
    int size;
    struct hashmap_entry *values;
};

/**
 * @brief Dan Bernsteins DJB2 Hash Function
 * @detail http://www.cse.yorku.ca/~oz/hash.html
 * String must be terminated with a null-byte.
 */
unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

/**
 * Allocate new hashmap.
 */
struct hashmap *hashmap_alloc(int capacity)
{
    struct hashmap *new_table = malloc(sizeof(struct hashmap));
    new_table->capacity = capacity;
    new_table->size = 0;
    new_table->values = malloc(capacity * sizeof(struct hashmap_entry));

    for (int i = 0; i < new_table->capacity; i++) {
        new_table->values[i].key = NULL;
    }

    return new_table;
}

/**
 * Free hashmap.
 */
void hashmap_free(struct hashmap **table, void (*value_free)(void *ptr))
{
    if (!(*table)) {
        return;
    }

    for (int i = 0; i < (*table)->capacity; i++) {
        if ((*table)->values[i].key) {
            free((*table)->values[i].key);

            if (value_free) {
                value_free((*table)->values[i].value);
            }
        }
    }

    free((*table)->values);
    free(*table);
    *table = NULL;
}

/**
 * Insert new element into hashmap.
 */
void *hashmap_put(struct hashmap **table, const char *key, void *value)
{
    if (!key) {
        return NULL;
    }

    if (*table == NULL) {
        *table = hashmap_alloc(HASHMAP_INITIAL_CAPACITY);
    } else if ((*table)->size > 0.7 * (*table)->capacity) {
        struct hashmap *doubled_table = clone_and_double(*table);
        hashmap_free(table, NULL);
        *table = doubled_table;
    }

    unsigned long hashval = hash((char *)key);
    unsigned long position;
    unsigned char reassign = 0;
    int i = 1;

    do {
        // Quadratic probing
        position = hashval + ((int)(0.5 * i)) + ((int)(0.5 * i * i));
        position %= (*table)->capacity;
        i++;
    } while ((*table)->values[position].key
             && !(reassign =
                      strcmp((*table)->values[position].key, key) == 0));

    void *ret = value;

    if (!reassign) {
        (*table)->size++;
        (*table)->values[position].key = malloc(strlen(key) + 1);
        strcpy((*table)->values[position].key, key);
    } else {
        ret = (*table)->values[position].value;
    }

    (*table)->values[position].value = value;

    return ret;
}

/**
 * Resize hashmap.
 */
struct hashmap *clone_and_double(struct hashmap *table)
{
    struct hashmap *new_table;
    new_table = hashmap_alloc(2 * table->capacity);
    struct hashmap_entry *entry;

    for (int i = 0; i < table->capacity; i++) {
        entry = table->values + i;
        if (entry->key) {
            hashmap_put(&new_table, entry->key, entry->value);
        }
    }

    return new_table;
}

/**
 * Get element from hashmap.
 */
void *hashmap_get(struct hashmap *const *table, const char *key)
{
    void *value = NULL;

    if (table && *table) {
        unsigned long hashval = hash((char *)key);
        unsigned long position;
        int i = 1;

        do {
            // Quadratic probing
            position =
                hashval + ((int)(0.5 * i)) + ((int)(0.5 * i * i));
            position %= (*table)->capacity;
            i++;
        } while ((*table)->values[position].key &&
                 strcmp((*table)->values[position].key, key) != 0);

        if ((*table)->values[position].key) {
            value = (*table)->values[position].value;
        }
    }

    return value;
}

int main(int argc, char **argv)
{
    struct hashmap *hashmap = NULL;

    int *i = calloc(1, sizeof(int));
    *i = 42;

    hashmap_put(&hashmap, "sample", i);

    fprintf(stdout, "%d\n", *(int *)hashmap_get(&hashmap, "sample"));

    hashmap_free(&hashmap, free);
}
