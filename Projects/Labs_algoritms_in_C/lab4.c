/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
SM12
*/
int  main()
{
    /*FILE *fp;
    char b;
    fp=fopen("file002.txt","w");
    int i3;
    for(i3=1;i3<=(rand()%4 + 1);i3++)
    {
        while((b=getchar())!='\n')
        {
            putc(b,fp);
        }
        putc(b,fp);
    }
printf("\n");
*/
    int m[31];
    char c;
    int i1=1,i2=0,N=0,N5=0;
    int max=-1, f=0;
    for(i2=0;i2<=30;i2++)
    {
        m[i2]=0;
    }

    for(i1=1;;i1++)
    {
       while((c = getchar()) != '\n')
       {
           N++;
           if(!(isspace(c)))
           {
               N5++;
           }
           else
           {
               if(N5==5)
                m[i1]++;
               N5=0;
           }
       }
       if(N5==5)
       {
          m[i1]++;
       }
       N5=0;

        if(N==0)
        break;
        N=0;
    }
    printf("\n");
    for(i1=1;i1<=30;i1++)
    {
        if(m[i1]>max)
        {
            max=m[i1];
        }
    }

    for(i1=1;i1<=30;i1++)
    {
        if(m[i1]==max)
        {
            if(f!=0)
                printf(" ");
            printf("%d",i1);
            f=1;
        }
    }
    printf("\n");
    /////
    /*fclose(fp);
    fp=fopen("file002.txt","r");
    int ch;
    N5=0;
    i1=1;
        for(i2=0;i2<=30;i2++)
    {
        m[i2]=0;
    }
    while ((ch = getc(fp)) != EOF)
    {
        if(ch=='\n')
        {
            i1++;
            if(N5==5)
           {
               m[i1]++;

           N5=0;
           }
        }

        if(!isspace(ch))
        {
            N5++;
        }
        else
        {
           if(N5==5)
           {
               m[i1]++;
           }
           N5=0;
        }
    }
    if(N5==5)
           {
               m[i1]++;
           }

    printf("\n");
    for(i1=1;i1<=30;i1++)
    {
        if(m[i1]>max)
        {
            max=m[i1];
        }
    }

    for(i1=1;i1<=30;i1++)
    {
        if(m[i1]==max)
        {
            if(f!=0)
                printf(" ");
            printf("%d",i1);
            f=1;
        }
    }
    printf("\n");*/




    return 0;
}
