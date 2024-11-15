#include<stdio.h>
char arr(char a[])
{
    for(int i=0;i<12;i++)
    {
        if (a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U')
           printf("%c",a[i]);
    }
   
}
int main()
{
    char a[]={'U','N','D','E','R','S','T','A','N','D','I','N','G'};
    arr(a);
}