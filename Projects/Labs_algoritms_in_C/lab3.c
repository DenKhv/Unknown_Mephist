/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
Lb12*/

int main(void)
{
    /*FILE *fp;
    fp = fopen("myfile_001.txt", "w");*/
    int N=0,min=123, state=0,i=0;
    char c,mins,vsp;
    char smin[100], stek[100];
    while ((c = getchar()) != '\n') /* сочетание двух действий */
        if(!(isspace(c)))
        {
            state=1;
            stek[N]=c;
            N++;
            putchar(c);
            /*putc(c,fp);*/
        }
        else
        {
            if(N<min&&N!=0)
            {
                 min=N;
                 for(i=0;i<=(min-1);i++)
                    smin[i]=stek[i];
            }
            if(state==1)
            {
                N=0;
                printf("\n");
                /*fprintf(fp,"\n");*/
            }
            state=0;
        }

        /*fclose(fp);*/

           if(state==1)
            printf("\n");
            putchar(c);

            //printf("\n%d  %d\n", N, min);
            if(N!=0&&N<min)
            {
                for(i=0;i<N;i++)
                    printf("%c",stek[i]);
            }
            else
                for(i=0;i<min;i++)
                    printf("%c",smin[i]);

printf("\n");
    return 0;
}
