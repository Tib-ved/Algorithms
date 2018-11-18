#include<stdio.h>

int main()
{
   int choose, a, b, c, i, result, base, exp;


while(1){
   printf("(This program is only for integer)Type number to choose the algorithm \n 1. + \n 2. - \n 3. *\n 4. / \n 5. ^ \n 6.Exit\n  Choice: ");
   scanf("%d", &choose);

   switch(choose){
   case(1): //addition
       printf("Enter First Number: ");
       scanf("%d", &a);
       printf("Enter Second Number: ");
       scanf("%d", &b);
       c = a + b;
       printf("%d + %d = %d\n",a , b, c);
       break;
   case(2): //subtraction
       printf("Enter Minuend: ");
       scanf("%d", &a);
       printf("Enter subtrahend: ");
       scanf("%d", &b);
       c = a - b;
       printf("%d - %d = %d\n",a ,b, c);
       break;
   case(3): //multiplication
       printf("Enter First Number: ");
       scanf("%d", &a);
       printf("Enter Second Number: ");
       scanf("%d", &b);
       c = a * b;
       printf("%d * %d = %d\n",a ,b, c);
       break;
   case(4): //division
       printf("Enter Dividend: ");
       scanf("%d", &a);
       printf("Enter Divisor: ");
       scanf("%d", &b);
       if (b != 0){
           c = a / b;
           printf("%d / %d = %d\n",a ,b, c);
       }
       else{
            printf("Divisor can not be 0.");
       }
       break;
   case(5)://exponentiation
       result = 1;
       printf("Enter Base: ");
       scanf("%d", &base);
       printf("Enter Exponent: ");
       scanf("%d", &exp);
     //  if (exp != 0)
         for(i = 0; i < exp;i++){
            result *= base;
         }
       printf("%d ^ %d = %d\n",base ,exp, result);
       break;
   case(6):
       printf("Good bye!");
       break;

   default:
       printf("Invalid number, please choose again.");
   }

}
   return 0;
}
