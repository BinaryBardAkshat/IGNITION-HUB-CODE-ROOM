#include<stdio.h>
int main()
{
    int i,j,n,temp;
    printf("Enter the number to be stored in a array: ");
    scanf("%d",&n);
    int a[n];

    printf("Enter the elements to be stored in a array: ");
    for(i=0;i<n;i++)
    {
        printf("Element %d: ",i);
        scanf("%d",&a[i]);
    }
    printf("\nArray\n");
    for(i=0;i<n;i++)
    {
        printf("%5d",a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-1)-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\n Sorted List \n");
    for(i=0;i<n;i++)
    {
        printf("%5d",a[i]);
    }
    return 0;
}