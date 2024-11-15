#include<stdio.h>
int main()
{
    int n=2,c=0;
    int a[]={3,2,2,5};
    for (int i=0;i<4;i++)
    {
        if(a[i]==n)
        c++;
    }
    printf("Frequensy of %d is %d",n,c);
} 