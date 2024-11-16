#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) 
{
    int j = 1;
    for (int i = 1; i < numsSize; i++) 
    {
        if (nums[i] != nums[i - 1]) 
        {
            *(nums + j) = *(nums + i);
            j++;
        }
    }
    return j;
}

int main() 
{
    int numsSize,n,i;
    printf("Enter the number of elements to be stored in the array: ");
    scanf("%d",&n);
    int nums[n];
    for(i=0;i<n;i++)
    {
        printf("\nElement %d: ",i);
        scanf("%d",&nums[i]);
    }
    printf("\n\tArray\t\n");
    for(i=0;i<n;i++)
    printf("%5d",nums[i]);   

    int newSize = removeDuplicates(nums, numsSize);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) 
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}