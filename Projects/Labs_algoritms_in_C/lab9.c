/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
//LB18

int main(void)
{
    int n;
    scanf("%d",&n);
    struct Stud{
        char Surname[20];
        char Name[20];
        int Course;
        struct {
            int Math;
            int Phys;
            int Inf;
        } Marks;
    } A[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s",A[i].Surname);
        scanf("%s",A[i].Name);
        scanf("%d",&A[i].Course);
        scanf("%d",&A[i].Marks.Math);
        scanf("%d",&A[i].Marks.Phys);
        scanf("%d",&A[i].Marks.Inf);
    }
//printf("%s %s %d %d %d %d", A[0].Surname, A[0].Name, A[0].Course, A[0].Marks.Math, A[0].Marks.Phys, A[0].Marks.Inf);
int a[n], min=301;
for(i=0;i<n;i++)
{
    a[i]= A[i].Marks.Math + A[i].Marks.Phys + A[i].Marks.Inf;
}
for(i=0;i<n;i++)
{
    if(A[i].Course==2)
    {
        a[i]<min;
        min=i;
    }
}
printf("\n%s %s\n\n",A[min].Surname, A[min].Name);
for(i=0;i<n;i++)
{
    if(i!=min)
    {
        if(a[i]>=a[min])
        {
            printf("%s %s\n", A[i].Surname, A[i].Name);
        }
    }
}

    return 0;
}
    */