#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) 
{
    int k = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        if (*(nums + i) != val) 
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;    
}

int main() 
{
    int numsSize,val,n,i;
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
    printf("\nEnter the value to be removed: ");
    scanf("%d",&val);
    numsSize = sizeof(nums) / sizeof(nums[0]);

    int newSize = removeElement(nums, numsSize, val);

    printf("Array after removing %d: ", val);
    for (int i = 0; i < newSize; i++) 
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
