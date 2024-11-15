#include<stdio.h>
int hcf;
int findhcf(int a,int b)
{
    for(int i = 1; i <= a || i <= b; i++)
   {
      if( a%i == 0 && b%i == 0 )
      hcf = i;
   }
   return hcf;
}
int main()
{
    printf("HCF = %d", findhcf(24,56));  
    return 0;
}