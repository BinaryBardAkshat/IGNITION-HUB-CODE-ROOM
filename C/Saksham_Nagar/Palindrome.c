#include<stdio.h>
#include<stdbool.h>
bool isPalindrome(long int x)
{
    if(x<0)
    return false;
    long int dup=x;
    int r;
    long int reverse=0;

    while(dup!=0)
    {
        r=dup%10;
        dup=dup/10;
        reverse = reverse*10 + r;
    }
    return reverse==x?true:false;
}
int main()
{
    long int number;

    printf("Enter a number to check if it's a palindrome: ");
    scanf("%ld", &number);

    if (isPalindrome(number))
        printf("%ld is a palindrome.\n", number);
    else
        printf("%ld is not a palindrome.\n", number);
    return 0;
}