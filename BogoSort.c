#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){
  int size;
  int* data;
  int* cp;
  bool* num;
  srand(time(NULL));

  printf("How many numbers to sort?\n");
  scanf("%d", &size);
  data = calloc(size, sizeof(int)); //Allocate memory for data array
  cp = calloc(size, sizeof(int)); //Copy of data
  num = calloc(size, sizeof(bool)); //Array of bools to check if value already added

  for(int t, i = 0; i<size; i++){ //Get data
    printf("Number no. %d: ", i+1);
    scanf("%d", &t);
    *(data+i) = t;
  }
  for(int i = 0; i<size; i++){ //Copy data
    *(cp+i) = *(data+i);
  }

  bool sorted = false;
  while(!sorted){
    sorted = true;
    for(int i = 0; i<size-1; i++){ //Check if data is sorted
      if(*(data+i)>*(data+i+1)){
        sorted = false;
      }
    }
    if(!sorted){ //Randomly permutate data
      for(int i = 0; i<size; i++){
        *(num+i) = false;
      }
      for(int r, i = 0; i<size; i++){
        r = rand()%(size-i);
        if(*(num+i)){
          *(data+i) = *(cp+i);
          printf("%d ", *(data+i));
          *(num+i) = true;
        }
      }
    }
  }

  for(int i = 0; i<size; i++){
    printf("%d\n",*(data+i));
  }

  free(data);
  free(num);
  free(cp);
  return 0;
}
