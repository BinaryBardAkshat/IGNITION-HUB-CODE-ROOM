#include<stdio.h>
#include<math.h>
int fact()
{
    int i,fac=1;
    for(i=1;i<=5;i++)
    {
        fac=fac*1;
    }
    return fac;
}
int main()
{
    int i,a=1,j,fac;
    float s=0;
    for(i=1;i<=5;i++)
    {
        fac=1;
        for(j=1;j<=i;j++)
        {
            fac=fac*j;
        }
        s=s+(float)pow(a,i)/fac;
    }
    printf("%f",s);
}