#include<stdio.h>
int arr[30];
int *fib()
{
    int x=0,y=1,z,c;
    arr[0]=0;
    arr[1]=1;
    c=2;
    while(c<30)
    {
       
        z=x+y;
        arr[c]=z;
        x=y;
        y=z;
        c++;
    }
    return arr;
}
int main()
{
    int *arr=fib(arr);
    for (int i=0;i<30;i++)
    {
        printf(" %d ",arr[i]);
    }
    return 0;
}