#include<stdio.h>
#include<math.h>
int aut(int n)
{
    int c=0;
    int dup=n;
    while(n!=0)
    {
        n=n/10;
        c++;
    }
    return c;
}
int main()
{
    
    int n=3;
    int sqr=n*n;
    int r= sqr%(int)pow(10,aut(n));
    if (r==n)
    printf("The number is an Automorphic");
    else 
    printf("The number is not an Autpmorphic");
}