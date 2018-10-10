//Vedant Tibrewal
//N Queens problem

#include<stdio.h>
#include<math.h>
 
int board[20],count;
 
int main()
{
 int n,i,j;
 void queen(int row,int n);
 
 printf(" - N Queens Problem Using Backtracking -");
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 queen(1,n);
 return 0;
}
 
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
 }
 
 return 1; 
}
 
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column;
   if(row==n)
    print(n);
   else 
    queen(row+1,n);
  }
 }
}
