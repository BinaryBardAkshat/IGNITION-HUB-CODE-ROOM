#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) 
{
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    if(nlen == 0)
    {
        return 0;
    }
    for(int i = 0; i < hlen - nlen + 1; i++)
    {
        int j = 0;
        while(j < nlen && *(haystack + i + j) == *(needle + j))
        {
            j++;
        }
        if(j == nlen)
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
    char haystack[100], needle[100];
    printf("Enter the haystack string: ");
    fgets(haystack, sizeof(haystack), stdin);
    haystack[strcspn(haystack, "\n")] = '\0';
    printf("Enter the needle string: ");
    fgets(needle, sizeof(needle), stdin);
    needle[strcspn(needle, "\n")] = '\0';
    int result = strStr(haystack, needle);
    printf("Index of first occurrence: %d\n", result);
    return 0;
}
