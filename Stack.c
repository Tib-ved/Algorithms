/*
Kashyap Nasit
03/08/2018
Program for implement stack
*/
#include<stdio.h>
#define stkSize 100

struct Stack{
  int loc;
  int arr[stkSize];
};

typedef struct Stack Stack;

 void push(Stack *s,int n){
   if(s->loc == stkSize){
     printf("Stackoverflow: can not add more elements.");
   }
   else{
     s->arr[++s->loc] = n;
   }
 }

 int pop(Stack *s){
     //printf("%d",s->loc);
   if(s->loc<0){
     printf("Stackempty: can't POP element.");
     return;
   }
   else{
     return s->arr[s->loc--];
   }
 }

void displayStack(Stack s){
  int i;
  for(i=0;i<=s.loc;i++)
    printf("%d\n",s.arr[i]);
}

void main(){
  Stack s;
  s.loc=-1;
  printf("Push 0:\n");
  push(&s,0);
  printf("Push 1:\n");
  push(&s,1);
  printf("Display stack:");
  displayStack(s);
  printf("popped %d\n\n",pop(&s));
  displayStack(s);
}
