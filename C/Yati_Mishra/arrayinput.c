#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter the elements to be stored in the array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("\nElement %d: ",i);
        scanf("%5d",&a[i]);
    }
    printf("\n\tArray\t\n");
    for(i=0;i<n;i++)
    printf("%5d",a[i]);
    
    return 0;
}