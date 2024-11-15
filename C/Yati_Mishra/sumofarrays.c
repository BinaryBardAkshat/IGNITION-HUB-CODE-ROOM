#include<stdio.h>
#include<math.h>
int main()
{
    int a[]={10,20,30,40};
    int b[]={48,34,205,1};
    int sum[4];
    int i;
    for (i=0;i<4;i++)
    {
        sum[i]=a[i]+b[i]; 
    }
    printf("The sum of two arrays is: ");
    for (i=0;i<4;i++)
    {
        printf(" %d ",sum[i]);
    }
}