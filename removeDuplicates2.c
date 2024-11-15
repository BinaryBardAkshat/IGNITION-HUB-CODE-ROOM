#include <stdio.h>

void rem(int* nums, int pos, int numsSize) 
{
    for (int i = pos; i < numsSize - 1; i++) 
    {
        *(nums + i) = *(nums + (i + 1));
    }
}

int removeDuplicates(int* nums, int numsSize) 
{
    for (int i = 0; i < numsSize - 2; i++) 
    {
        if (*(nums + i) == *(nums + i + 1) && *(nums + i + 1) == *(nums + i + 2)) 
        {
            rem(nums, i + 2, numsSize);
            numsSize--;
            i--;
        }
    }
    return numsSize;
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

    printf("Array after removing extra duplicates: ");
    for (int i = 0; i < newSize; i++) 
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
