#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
//SR18
void PassingScore( int a1[], int a2[], int a3[], int nP, int nM, int nB, int Nf, int *pr1, int *pr2, int *pr3);
void Received(char* q1[], char* q2[], char* q3[], int Nf);
void OutofMoscow(int Nin);
void Cities(char *C[]);
int main(void)
{
    int n, i;
    scanf("%d",&n);
    struct abitur
    {
        char  Surname[20];
        char Name[20];
        struct
        {
            char city[20];
            char street[20];
            int Nhome;
            int Nflat;
        } address;
        char Faculty[20];
        int Points;
    } A[n];



    for(i=0;i<n;i++)
    {
        scanf("%s",A[i].Surname);
        scanf("%s",A[i].Name);
        scanf("%s", A[i].address.city);
        scanf("%s", A[i].address.street);
        scanf("%d", &A[i].address.Nhome);
        scanf("%d", &A[i].address.Nflat);
        scanf("%s",A[i].Faculty);
        scanf("%d",&A[i].Points);
    }
    int Nf;
    scanf("%d", &Nf);
    //1
    int nP=0, nM=0, nB=0;
    for(i=0;i<n;i++)
    {
        if(A[i].Faculty[0]=='P')
            nP++;
        if(A[i].Faculty[0]=='M')
            nM++;
        if(A[i].Faculty[0]=='B')
            nB++;
    }
    int a1[nP], a2[nM], a3[nB];
    int i1=0;
    for(i=0;i<n;i++)
    {
        if(A[i].Faculty[0]=='P')
        {
            a1[i1]=A[i].Points;
            i1++;
        }
    }
    i1=0;

     for(i=0;i<n;i++)
    {
        if(A[i].Faculty[0]=='M')
        {
            a2[i1]=A[i].Points;
            i1++;
        }
    }
    i1=0;

     for(i=0;i<n;i++)
    {
        if(A[i].Faculty[0]=='B')
        {
            a3[i1]=A[i].Points;
            i1++;
        }
    }
    int pr1, pr2, pr3;
 PassingScore (a1,a2,a3, nP, nM, nB,Nf,&pr1,&pr2,&pr3);
 printf("\n");

 //2
 char *q1[nP], *q2[nM],*q3[nB];
 int i2=0,i3=0;
 i1=0;
 for(i=0;i<n;i++)
 {
     if((A[i].Faculty[0]=='P' )&&(A[i].Points>=pr1))
     {
         q1[i1]=&A[i].Surname[0];
         i1++;
     }

      if((A[i].Faculty[0]=='M' )&&(A[i].Points>=pr2))
     {
         q2[i2]=&A[i].Surname[0];
         i2++;
     }

      if((A[i].Faculty[0]=='B' )&&(A[i].Points>=pr3))
     {
         q3[i3]=&A[i].Surname[0];
         i3++;
     }
 }
 Received(q1,q2,q3,Nf);
 //3
 int Nin=0;
for(i=0;i<n;i++)
{
    if(A[i].address.city[0]!='M')
        Nin++;
}
OutofMoscow(Nin);
//4
char *C[8];
int c[8];
for(i=0;i<8;i++)
{
    c[i]=0;
}
for(i=0;i<n;i++)
{
    if(A[i].address.city[0]=='M')
        c[0]++;
    if(A[i].address.city[0]=='V')
        c[1]++;
    if(A[i].address.city[0]=='T')
        c[2]++;
    if(A[i].address.city[0]=='S')
        c[3]++;
    if(A[i].address.city[0]=='O')
        c[4]++;
    if(A[i].address.city[0]=='P')
        c[5]++;
    if(A[i].address.city[0]=='K')
        c[6]++;
    if(A[i].address.city[0]=='I')
        c[7]++;
}
    C[0]=&A[0].address.city;
    C[1]=&A[1].address.city;
    C[2]=&A[24].address.city;
    C[3]=&A[2].address.city;
    C[4]=&A[6].address.city;
    C[5]=&A[4].address.city;
    C[6]=&A[12].address.city;
    C[7]=&A[14].address.city;

Cities(C);
printf("\n");



        /*for(i=0;i<n;i++)
        {
            fprintf("fp,%s",A[i].Surname);
            fprintf("fp,%s",A[i].Name);
            fprintf("fp,%s", A[i].address.city);
            fprintf("fp,%s", A[i].address.street);
            fprintf("fp,%d", A[i].address.Nhome);
            fprintf("fp,%d", A[i].address.Nflat);
            fprintf("fp,%s",A[i].Faculty);
            fprintf("fp,%d\n",A[i].Points);
        }*/
   /* FILE *fp;
    fp = fopen("myfile001.txt","w");

     for(i=0;i<n;i++)
        {
            fprintf(fp, "%s",A[i].Surname);
            fprintf(fp, " %s",A[i].Name);
            fprintf(fp, " %s", A[i].address.city);
            fprintf(fp, " %s", A[i].address.street);
            fprintf(fp, " %d", A[i].address.Nhome);
            fprintf(fp, " %d", A[i].address.Nflat);
            fprintf(fp, " %s",A[i].Faculty);
            fprintf(fp, " %d\n",A[i].Points);
        }


    fclose(fp);

    fp = fopen("myfile001.txt","r");
    int ch;
    while ((ch = getc(fp)) != EOF)
       putchar(ch);
    fclose(fp);
*/
    return 0;
}
void PassingScore( int a1[], int a2[], int a3[], int nP, int nM, int nB, int Nf, int *pr1, int *pr2, int *pr3)
{
    int Q,min, i1,i2;

     for(i1=0;i1<(nP-1);i1++)
    {
        min=a1[i1];
        Q=i1;
        for(i2=(i1+1);i2<nP;i2++)
        {
            if(a1[i2]<min)
            {
                min=a1[i2];
                Q=i2;
            }
        }
        min=a1[Q];
        a1[Q]=a1[i1];
        a1[i1]=min;
    }

         for(i1=0;i1<(nM-1);i1++)
    {
        min=a2[i1];
        Q=i1;
        for(i2=(i1+1);i2<nM;i2++)
        {
            if(a2[i2]<min)
            {
                min=a2[i2];
                Q=i2;
            }
        }
        min=a2[Q];
        a2[Q]=a2[i1];
        a2[i1]=min;
    }

         for(i1=0;i1<(nB-1);i1++)
    {
        min=a3[i1];
        Q=i1;
        for(i2=(i1+1);i2<nB;i2++)
        {
            if(a3[i2]<min)
            {
                min=a3[i2];
                Q=i2;
            }
        }
        min=a3[Q];
        a3[Q]=a3[i1];
        a3[i1]=min;
    }
    *pr1=a1[nP-Nf];
    *pr2=a2[nM-Nf];
    *pr3=a3[nB-Nf];

    printf("Physics %d\n", a1[nP-Nf]);
    printf("Math %d\n", a2[nM-Nf]);
    printf("Biology %d\n", a3[nB-Nf]);
}
void Received(char* q1[], char* q2[], char* q3[], int Nf)
{
    int i,i1;
     i1=0;
 printf("Physics\n");
 for(i=0;i<Nf;i++)
 {
     while(isalnum(*(q1[i]+i1)))
     {
         printf("%c",*(q1[i]+i1));
         i1++;
     }
     i1=0;
     printf("\n");
 }

 i1=0;
 printf("Math\n");
 for(i=0;i<Nf;i++)
 {
     while(isalnum(*(q2[i]+i1)))
     {
         printf("%c",*(q2[i]+i1));
         i1++;
     }
     i1=0;
     printf("\n");
 }

 i1=0;
 printf("Biology\n");
 for(i=0;i<Nf;i++)
 {
     while(isalnum(*(q3[i]+i1)))
     {
         printf("%c",*(q3[i]+i1));
         i1++;
     }
     i1=0;
     printf("\n");
 }
 printf("\n");

}
void OutofMoscow(int Nin)
{
    printf("%d\n\n",Nin);

}

void Cities(char *C[])
{
    int i,i1=0;
    for(i=0;i<8;i++)
 {
     while(isalnum(*(C[i]+i1)))
     {
         printf("%c",*(C[i]+i1));
         i1++;
     }
     i1=0;
     printf(" ");
 }

}

/*25
Petrov Evgeny Moscow Proletarsky 2 10 Physics 291
Samoilov Petr Vologda Kalinina 4 45 Math 300
Shitkov Victor Tula RedProsp 31 1 Biology 275
Dmitrienko Egor Moscow Kantemirovskaya 21 74 Math 265
Petrenko Igor Sochi Pionerskaya 13 17 Math 273
Demidova Nina Moscow Teatralnaya 23 87 Physics 285
Kegelik Andrew Omsk Frunze 12 34 Physics 273
Rebrov Artem Pskov Sovetskaya 15 25 Math 278
Osipova Maria Vologda Sovetskaya 31 12 Biology 290
Lopotov Gleb Pskov Sadovaya 12 96 Math 287
Fedorenko Vladislav Moscow Mohovaya 54 10 Biology 300
Golovin Aleksandr Moscow Nikolskaya 23 14 Biology 279
Travin Sergey Kaliningrad Sovetskaya 65 12 Biology 265
Utemova Maria Vologda PrMira 2 34 Physics 293
Maslova Tina Irkutsk Lenina 54 3 Biology 278
Leskov Fedor Moskow Kantemirovskaya 43 12 Math 269
Ternieva Arina Moscow OhotnyRyad 34 12 Physics 289
Gernikov Rassul Pskov UlSentyabrya 3 4 Biology 270
Garayev Aidar Tula Sovetskaya 43 12 Physics 290
Bedinikov Aleksandr Moscow Moscvorechie 34 12 Math 300
Ryazanova Olga Omsk Frunze 21 90 Biology 284
Ulaev Roman Moscow Nikolskaya 12 65 Physics 281
Todarenko Aleksandra Vologda Kalinina 12 1 Math 269
Darnaev Dmitry Moscow Proletarsky 12 34 Biology 299
Holetsky Anton Pskov Sovetskaya 1 23 Physics 276
5*/
