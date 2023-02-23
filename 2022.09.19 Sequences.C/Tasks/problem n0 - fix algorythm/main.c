#include <stdio.h>

int main()
{
   int x, flag=0, sum=0;
   do {
         if (x == 0) flag = 1;
         
         scanf("%d", &x);

         if (x != 0 && flag == 1) flag = 0;
         // how about 2 scanf?

         sum += x;

   }  while (!flag);
   return 0;
}
