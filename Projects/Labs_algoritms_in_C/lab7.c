/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
Lb14*/

int main(void)
{
    int n,i,i1=0,i2=0,i3=0,min=23413;
    int sr=0,pr=0,N=0;
    scanf("%d",&n);
    int *a;
    a=(int*) malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i3=1;i3<=n;i3++)
      printf("%3d",i3);
    printf("\n");
    for(i3=0;i3<n;i3++)
      printf("%3d",a[i3]);
    printf("\n\n");


    for(i1=0;i1<(n-1);i1++)
    {
        min=a[i1];
        N=i1;
        for(i2=(i1+1);i2<n;i2++)
        {
            sr++;
            if(a[i2]<min)
            {
                min=a[i2];
                N=i2;
            }
        }
        min=a[N];//1
        a[N]=a[i1];//2
        a[i1]=min;//3
        pr+=3;

        for(i3=1;i3<=n;i3++)
          printf("%3d",i3);
        printf("\n");
        for(i3=0;i3<n;i3++)
          printf("%3d",a[i3]);
        printf("\n");
        if(i1!=(n-2))
          printf("\n");
    }
printf("%d %d\n",pr,sr);

    return 0;
}