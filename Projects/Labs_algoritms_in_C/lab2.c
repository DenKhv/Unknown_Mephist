/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
SM11*/
void f1(int a[],int s);
void f2(int a[],int s);
void f3(int a[],int s,int f,int end);
void f4(int a[],int s);
int f5(int a[],int s);
float f6(int a[],int s,int *f,int *end );
int w[14];
int main(void)
{
    int m1[6],m2[7],m3[8];
    int s1=6, s2=7,s3=8;
    int a=12,b=25;
    int f, end;
    f2(m1,s1);
    f2(m2,s2);
    f2(m3,s3);
    scanf("%d %d", &f,&end);
    int min1,min2,min3;
    min1=f5(m1,s1);
    min2=f5(m2,s2);
    min3=f5(m3,s3);
    printf("%d ",min1);
    printf("%d ",min2);
    printf("%d\n",min3);
    float sum;
    sum=f6(m3,s3, &m3[f-1],&m3[end-1]);
    printf("%.1f\n", sum);
    f1(w,14);
    int i1,i2,i3,j;
    for(j=12;j<=25;j++)
    {
        for(i1=0;i1<s1;i1++)
        {
            if(m1[i1]==j)
            {
                w[j-12]+=1;
                break;
            }
        }
        for(i2=0;i2<s2;i2++)
        {
            if(m2[i2]==j)
            {
                w[j-12]+=1;
                break;
            }
        }
         for(i3=0;i3<s3;i3++)
        {
            if(m3[i3]==j)
            {
                w[j-12]+=1;
                break;
            }
        }

    }
    int i,p=0;
    for(i=0;i<=13;i++)
    {
        if(w[i]==0)
        {
            if(p!=0)
                printf(" ");
            printf("%d",i+12);
            p++;

        }
    }
printf("\n");
    return 0;
}
void f1(int a[],int s)
{
    int i;
    for(i=0;i<s;i++)
    a[i]=0;
}
void f2(int a[],int s)
{
    int i;
    for(i=0;i<s;i++)
    {
        scanf("%d", &a[i]);
    }
}
void f3(int a[],int s,int f,int end)
{
    int i;
    for(i=0;i<s;i++)
    {
        a[i]=(rand()%(end-f+1))+f;
    }
}
void f4(int a[],int s)
{
    int i;
    for(i=1;i<=s;i++)
        printf("%5d", i);
    printf("\n");
    for(i=0;i<s;i++)
        printf("%5d",a[i] );
    printf("\n");
}
int f5(int a[],int s)
{int i, min=123124;
for(i=0;i<s;i++)
{
    if(a[i]<min)
        min=a[i];
}
return min;
}
float f6(int a[],int s,int *f,int *end )
{
    int n;
    float sum=0;
    n=(end-f+1);
    //printf("%d\n", n);
    while (f<=end)
    {
        sum+= *f;
        f++;
    }
    sum=(float)sum/n;

    return sum;
}