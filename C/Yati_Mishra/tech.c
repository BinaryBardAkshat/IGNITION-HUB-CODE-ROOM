#include<stdio.h>
#include<math.h>
int main()
{
    int n,k,n1,n2,s=0,c=0;
    printf("Enter the number: ");
    scanf("%d",&n);
    int dup=n;
    while (n!=0)
    {
        n=n/10;
        c++;
    }
    if (c%2!=0)
    {
        printf("The no does not contain even number of digits\n");
    }
    n=dup;
    k=(float)pow(10,c/2);
    n1=n/k;
    n2=n%k;
    s=n1+n2;
    if (s*s==n)
    {
        printf("The number is a tech");
    }
    else if (s*s!=n)
    {
        printf("The number is not a tech");
    }
}