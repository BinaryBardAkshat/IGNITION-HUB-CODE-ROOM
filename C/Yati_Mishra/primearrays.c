#include<stdio.h>
int main()
{
    int a[]={1,2,3,4,5,13,14,15,17,11};
    int i,j;
    int n;
    int c=0,k=0;
    for (i=0;i<10;i++)
    {
        n=a[i];
        c=0;
        for (j=1;j<=n;j++)
        {
            if (n%j==0)
            c++;
        }
         if (c==2)
            k++;
    }
    printf(" %d ",k);
}