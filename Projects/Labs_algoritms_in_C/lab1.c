/*#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>*/
void zapoln (int q[], int s, int a, int b);
void print (int *f, int *end);


int main(void)
{
    int m[10],n[12];
    int s1=10, s2=12;
    int a1,a2,b1,b2;
    scanf("%d %d",&a1,&b1);
    scanf("%d %d",&a2,&b2);
    zapoln(m, s1, a1, b1);
    zapoln(n, s2, a2, b2);
    print(m,m+s1);
    printf("\n");
    print(n,n+s2);
    return 0;
}
void zapoln (int q[], int s, int a, int b)
{
    int i;
    for(i=0;i<s;i++)
        q[i]= a*i+b;
}
void print (int *f, int *end)
{
    int stop = end-f;
    int i;
    for(i=1; i<=stop;i++)
    {
        printf("%5d", i);
    }
    printf("\n");
    while(f<end)
    {
        printf("%5d", *f);
        f++;
    }
     printf("\n");
}