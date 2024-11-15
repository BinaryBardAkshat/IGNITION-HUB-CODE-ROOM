#include<stdio.h>
int main()
{
    int a=0,b=1,c;
    int arr[30],i;
    arr[0]=0;
    arr[1]=1;
    for(i=2;i<30;i++)
    {
        c=a+b;
        arr[i]=c;
        a=b;
        b=c;
    }
    int s=0;
    for(int k=0;k<i;k++)
    {
      printf("%d  ",arr[k]);
      s=s+arr[k];
    }
    printf("=%d",s);
}