#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int *result = (int*)malloc(2 * sizeof(int)); 

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            
            if (*(nums+i) + *(nums+j) == target)
            {
                result[0] = i;  
                result[1] = j;  
                *returnSize = 2;
                return result;  
            }
        }
    }
    
    *returnSize = 0;  
    return NULL;  
}
int main()
{
    int n,target,i,numSize,returnSize;
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
    printf("\nEnter a target: ");
    scanf("%d",&target);
    numSize = sizeof(nums) / sizeof(nums[0]);
    int* result = twoSum(nums,numSize,target,&returnSize);

    if(result != NULL && returnSize==2)
    {
        printf("Indicies: %d %d\n",result[0],result[1]);
        free(result);
    }
    else
    {
        printf("\nNo two number add to the target.\n");
    }
}