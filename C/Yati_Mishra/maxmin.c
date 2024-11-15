#include<stdio.h>
int main()
{
    int a[]={4,51,6,1};
    int max=a[0];
    int min=a[0];
    for (int i=0;i<4;i++)
    {
        if (max<a[i])
        {
            max=a[i];
        }
        if (min>a[i])
        {
            min=a[i];
        }
    }
    printf("Maximum no %d\n",max);
    printf("Minimum no %d",min);
}