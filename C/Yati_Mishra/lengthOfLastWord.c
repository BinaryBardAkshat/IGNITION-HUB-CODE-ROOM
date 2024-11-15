#include <stdio.h>
int lengthOfLastWord(char* s) 
{
    int c = 0;  
    int i = 0;  
    int k = 0;  
    while (*(s + i) != '\0') 
    {
        if (*(s + i) != ' ') 
        {
            c++;
        } 
        else if (c > 0) 
        {
            k = c; 
            c = 0;  
        }
        i++;
    }
    if (c > 0) 
    {
        k = c; 
    }
    return k;
}
int main() 
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); 
    int result = lengthOfLastWord(str);
    printf("Length of the last word: %d\n", result);

    return 0;
}
