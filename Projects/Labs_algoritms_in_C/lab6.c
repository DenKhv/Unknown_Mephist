/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>*/
void func(int **a,int n,int N);
int main(void)
{
    int N,n,*a,i;
    scanf("%d",&N);
    scanf("%d",&n);
   a=(int*)malloc(sizeof(int)*N);
   for(i=0;i<N;i++)
   {
       scanf("%d",&a[i]);
   }
   func(&a,n,N);
   for(i=0;i<N;i++)
   {
       printf("%3d",i+1);
   }
   printf("\n");
   for(i=0;i<N;i++)
   {
       printf("%3d",a[i]);
   }
   printf("\n");



    return 0;
}
void func(int **a,int n,int N)
{
    int *b;
    b= (int*)malloc(sizeof(int)*N);
    int i,m;
    m=2*n-1;
    for(i=0;i<=(n-1);i++)
    {
        b[m]=(*a)[i];
        m--;
    }
    m=0;
    for(i=n;i<=(2*n-1);i++)
    {
        b[m]=(*a)[i];
        m++;
    }
    if(2*n<N)
    {
        for(i=2*n;i<=(N-1);i++)
        {
            b[i]=(*a)[i];
        }
    }
    *a=b;

}