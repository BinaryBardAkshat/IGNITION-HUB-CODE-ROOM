#include<stdio.h>
#include<math.h>
int a=0,b=1,c;
    int s=0;
void equal(int arr[10])
{
    for(int i=2;i<10;i++)
    {
        c=a+b;
        arr[i]=c;
        a=b;
        b=c;
    }
}
void sum(int arr[10])
{
    for(int k=0;k<10;k++)
    {
        printf("%d ",arr[k]);
        s=s+arr[k];
    }
}
int main()
{
    int arr[10];
    arr[0]=0;
    arr[1]=1;
    equal(arr);
    sum(arr);
    printf("=%d",s);
}