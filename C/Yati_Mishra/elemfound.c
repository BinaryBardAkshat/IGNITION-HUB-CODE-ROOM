#include<stdio.h>
int arr(int a[])
{
    int s=50,j=0;
    for(int i=0;i<2;i++)
    {
        if (a[i]==s)
        {

            printf("Element is found at index %d",i);
            j=1;
            break;
        }
    }
    if(!j)
    printf("Element is not found in the array",s);
}
int main()
{
    int a[]={10,20,30};
    arr(a);
}