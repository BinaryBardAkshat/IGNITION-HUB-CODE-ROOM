#include<stdio.h>
int main()
{
    int n,r,s=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    int sqr=n*n;
    while(sqr!=0)
    {
        r=sqr%10;
        sqr=sqr/10;
        s=s+r;
    }
    if (n==s)
        printf("Successful");
    else
        printf("Unsuccessful");
    return 0;   
}