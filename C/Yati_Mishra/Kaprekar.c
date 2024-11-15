#include<stdio.h>
#include<math.h>
int main()
{
    int n,k,l,ri,c=0,s;
    printf("Enter the number: ");
    scanf("%d",&n);
    int dup=n;
    while (n!=0)
    {
        n=n/10;
        c++;
    }
    n=dup;
    int sqr=n*n;
        k=(float)pow(10,c);
        l=sqr%k;
        ri=sqr/k;
        s=l+ri;
    if (s==n)
    {
        printf("The number is a Kaprekar");
    }
    else 
    {
        printf("The number is not a Kaprekar");
    }
}