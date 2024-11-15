#include<stdio.h>
#include<math.h>
int findfac(int n)
{
    int i,fact=1;
    for(i=1;i<=n;i++)
        fact=fact*i;
    return fact;
}
int main()
{
    int i,j,a=1;
    float s=0;
    for (i=1;i<5;i++)
    {
        s=s+pow(a,i)/findfac(i);
    }
    printf("%f",s);
}
