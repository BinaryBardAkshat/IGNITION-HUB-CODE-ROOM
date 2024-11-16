#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int merged[totalSize];
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    while (i < nums1Size) {
        merged[k++] = nums1[i++];
    }

    while (j < nums2Size) {
        merged[k++] = nums2[j++];
    }

    if (totalSize % 2 == 0) {
        return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
    } else {
        return merged[totalSize / 2];
    }
}

int main() {
    int nums1Size, nums2Size;

    printf("Enter the size of the first array: ");
    scanf("%d", &nums1Size);
    int nums1[nums1Size];
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < nums1Size; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &nums2Size);
    int nums2[nums2Size];
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < nums2Size; i++) {
        scanf("%d", &nums2[i]);
    }

    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("Median of the two sorted arrays: %.1f\n", median);

    return 0;
}