#include<stdio.h>
#include<math.h>
int s,n;
void kaprekar()
{
   int r,k,ri,c=0,l;
   printf("Enter a number: ");
   scanf("%d",&n);
   int dup=n;
   while(n!=0)
   {
    n=n/10;
    c++;
   }
   n=dup;
   int sqr=n*n;
       k=(float)pow(10,c);
       l=sqr%k;
       ri=sqr/10;
       s=l+ri;
}
void kap()
{
    if (s==n)
    {
        printf("The number is a Kaprekar");
    }
    else 
    {
        printf("The number is not a Kaprekar");
    }
}
int main()
{
   kaprekar();
   kap();
   return 0;
}
