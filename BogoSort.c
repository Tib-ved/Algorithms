#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){
  int size, r, count = 0;
  int* data;
  int* cp;
  bool* num;
  bool sorted;
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

  while(!sorted){
    sorted = true;
    for(int i = 0; i<size-1; i++){ //Check if data is sorted
      if(*(data+i)>*(data+i+1)){
        sorted = false;
      }
    }
    if(!sorted){ //Randomly permutate data
      for(int i = 0; i<size; i++){ //Check all values as not copied yet
        *(num+i) = false;
      }
      count = 0;
      while(count<size){
        r = rand()%size;
        if(!*(num+r)){ //Check if random value is copied
          *(data+count) = *(cp+r); //Copy
          *(num+r) = true; //Check as copied
          count++;
        }
      }
    }
  }

  for(int i = 0; i<size; i++){ //Print sorted data
    printf("%d ",*(data+i));
  }
  printf("\n");

  free(data);
  free(num);
  free(cp);
  return 0;
}
