/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>*/
//LB13
void del(int n, int k, int **a);
void change(int n,int i,int **b);
int main(void)
{
    int *p;
    int n,i1, i,k;
    scanf("%d", &n);
    p=(int*) malloc(n * sizeof(int));
    for(i1=0;i1<n;i1++)
    {
        scanf("%d",&p[i1]);
    }
    scanf("%d",&k);
    scanf("%d",&i);
    for(i1=1;i1<=n;i1++)
    {
        printf("%3d",i1);
    }
        printf("\n");
    for(i1=0;i1<n;i1++)
    {
        printf("%3d",p[i1]);
    }
    printf("\n\n");

    del(n,k,&p);
    change(n,i,&p);

    for(i1=1;i1<=(n-1);i1++)
    {
        printf("%3d",i1);
    }
    printf("\n");
    for(i1=0;i1<(n-1);i1++)
    {
        printf("%3d",p[i1]);
    }
    printf("\n");
free(p);
    return 0;
}
void del(int n, int k, int **a)
{
    int i1,N;
    int *q;
    N=k;
    if(k==n)
        q=realloc(*a,(n-1)*sizeof(int));
    else
    {
        for(i1=1;i1<=(n-k);i1++)
        {
            (*a)[N-1]=(*a)[N];
            N++;
        }
        q=realloc(*a,(n-1)*sizeof(int));
    }
    *a=q;
}
void change(int n,int i,int **b)
{
    int D;
    D=(*b)[i-1];
    (*b)[i-1]=(*b)[n-2];
    (*b)[n-2]=D;
}