#include<stdio.h>
#include<stdbool.h>
bool prime(int n)
{
    int c=0;
    for (int i=1;i<=n;i++)
        if(n%i==0)
          c++;
    return c==2?true:false;

}
bool diff(int x, int y)
{
    int z=(x>y)?x-y:y-x;
    return z==2?true:false;
}
int main()
{
    int x,y;
    printf("Enter two numbers: ");
    scanf("%d%d",&x,&y);
    if(prime(x) && prime(y) && diff(x,y))
    printf("The number are twin primes");
    else 
    printf("The numbers are not twin primes");
    return 0;
}