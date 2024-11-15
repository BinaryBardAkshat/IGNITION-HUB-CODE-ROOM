#include<stdio.h>
int fac(int);
int sum();
int main()
{
    printf("%d",sum(14));
}
int sum(int n)
{
    int s=0,r;
    while(n!=0)
    {
        r=n%10;
        n=n/10;
        s=s+fac(r);
    }
    return s;
}
int fac(int n)
{
    int i,fact=1;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    return fact;
}