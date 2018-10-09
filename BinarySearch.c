//Chitranshu Srivastava
//Program to implement Binary Search

#include<stdio.h>

int bin(int a[], int low, int high, int n){
  if(high>low){
    int mid= low + (high-low)/2;
    if(a[mid]==n){
        return mid;
    }
    if(a[0]==n){
      return 0;
    }
    if(a[mid]>n){
      return bin(a,0,mid,n);
    }
    else if(a[mid]<n){
      return bin(a,mid,high,n);
    }
  }

  else return -1;
}

void main(){
  int i, n, size;
  printf("Enter size of array: ");
  scanf("%d",&size);
  int a[size];
  printf("Enter sorted array elements: ");
  for(i=0; i<size; i++){
    scanf("%d", &a[i]);
  }
  printf("Enter the value of n: ");
  scanf("%d",&n);
  int index=bin(a,0,size-1,n);
  if(index== -1){
    printf("%d not Found in array", n);
  }
  else{
    printf("\n %d was found at index %d", n, index);
  }
}
