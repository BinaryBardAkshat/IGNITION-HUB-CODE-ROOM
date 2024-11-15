#include<stdio.h>
int reverse(int a[],int strt,int end)
{
    int temp;
    while(strt<=end)
    {
        temp=a[strt];
        a[strt]=a[end];
        a[end]=temp;
        strt++;
        end--;
    }   
}
void arr(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
    printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    arr(a,n);
    reverse(a,0,n-1);
    printf("Reversed array: ");
    
    return 0;
}