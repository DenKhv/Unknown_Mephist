/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
SM12*/
void RandZapoln(int ***a, int fst, int end, int n, int m);//1)
void PrintfMatrix(int ***a, int n, int m);//2)
void FileWork(int ***a, int n, int m);//3)
void TranspMatrix(int ***a, int n, int m);//4)
void SumMatrix(int ***a, int ***SL, int ***Res, int n, int m);//5)
void UmnozhMAtrix(int ***a, int ***Mnl, int ***Res1, int n, int m, int nMnl, int mMnl);//6)
void StMatrix(int ***a, int ***Res2, int n, int St);//7)
int  main()
{

    /*int fst, end;                                            //для функции 1 задают интервал случайных чисел
    scanf("%d %d",&fst, &end);


    RandZapoln(&a, fst, end, n, m);*/                          //Вызов 1)

    /*TranspMatrix(&a,n,m);*/                                  //Вызов4)

    /* PrintfMatrix(&a,n,m);*/                                 //Вызов 2)
    /*FileWork(&a,n,m);*/                                      //Вызов 3)

    /*int **SL, *vSL;                                            //Инициализация Слагаемого для 5)
    vSL=(int*)malloc(sizeof(int)*m);
    SL=(int**) malloc(n*sizeof(int*)+n*m*sizeof(int));
    for (i=0; i<n; ++i)
    SL[i] = (int*)(SL+n) + i*m;
    for(i=0;i<n;i++)
    {
            for(i1=0;i1<m;i1++)
                scanf("%d",&SL[i][i1]);
    }


    int **Res, *vRes;                                          //Инициализация матрицы результата 5)
    vRes=(int*)malloc(sizeof(int)*m);
    Res=(int**) malloc(n*sizeof(int*)+n*m*sizeof(int));
    for (i=0; i<n; ++i)
    Res[i] = (int*)(Res+n) + i*m;

    SumMatrix(&a,&SL,&Res,n,m);                                //Вызов 5)

    PrintfMatrix(&Res,n,m);*/

    /*int **Mnl, *vMnl;                                           //Инициализация матрицы-множителя 6)
    int nMnl, mMnl;
    scanf("%d %d",&nMnl,&mMnl);
    vMnl=(int*)malloc(sizeof(int)*mMnl);
    Mnl=(int**) malloc(nMnl*sizeof(int*)+nMnl*mMnl*sizeof(int));
    for (i=0; i<nMnl; ++i)
    Mnl[i] = (int*)(Mnl+nMnl) + i*mMnl;
     for(i=0;i<nMnl;i++)
    {
            for(i1=0;i1<mMnl;i1++)
                scanf("%d",&Mnl[i][i1]);
    }

    int **Res1, *vRes1;                                          //Инициализация матрицы-результата 6)
    vRes1=(int*)malloc(sizeof(int)*mMnl);
    Res1=(int**) malloc(n*sizeof(int*)+n*mMnl*sizeof(int));
    for (i=0; i<n; ++i)
    Res1[i] = (int*)(Res1+n) + i*mMnl;
    for(i=0;i<n;i++)
    {
        for(i1=0;i1<mMnl;i1++)
        {
            Res1[i][i1]=0;
        }
    }


    UmnozhMAtrix(&a,&Mnl,&Res1, n, m, nMnl, mMnl);

    PrintfMatrix(&Res1,n,mMnl);*/

    /*int **Res2, *vRes2;                                          //Инициализация матрицы-результата 7)
    vRes2=(int*)malloc(sizeof(int)*n);
    Res2=(int**) malloc(n*sizeof(int*)+n*n*sizeof(int));
    for (i=0; i<n; ++i)
    Res2[i] = (int*)(Res2+n) + i*n;

    for(i=0;i<n;i++)
    {
        for(i1=0;i1<n;i1++)
        {
            Res2[i][i1]=0;
        }
    }
    int St;                                                      //Ввод степени, в которую возводится матрица
    scanf("%d", &St);

    StMatrix(&a,&Res2, n, St);

    PrintfMatrix(&Res2,n,n);*/

    int **a,*b;
    int i,i1;
    int n, m;
    scanf("%d %d",&n, &m);
    b=(int*)malloc(sizeof(int)*n);
    a=(int**) malloc(n*sizeof(int*)+n*n*sizeof(int));
    for (i=0; i<n; ++i)
    a[i] = (int*)(a+n) + i*n;
     for(i=0;i<n;i++)
    {
            for(i1=0;i1<n;i1++)
                scanf("%d",&a[i][i1]);
    }

    int **res1,**res2,**res3;
    int *vres1,*vres2,*vres3;

    vres1=(int*)malloc(sizeof(int)*n);
    res1=(int**) malloc(n*sizeof(int*)+n*n*sizeof(int));//Значение А^T
    for (i=0; i<n; ++i)
    res1[i] = (int*)(res1+n) + i*n;

    for(i=0;i<n;i++)
    {
        for(i1=0;i1<n;i1++)
        {
            res1[i][i1]=a[i][i1];
        }
    }

    vres2=(int*)malloc(sizeof(int)*n);
    res2=(int**) malloc(n*sizeof(int*)+n*n*sizeof(int));//Значение A^T * A
    for (i=0; i<n; ++i)
    res2[i] = (int*)(res2+n) + i*n;

    for(i=0;i<n;i++)
    {
        for(i1=0;i1<n;i1++)
        {
            res2[i][i1]=0;
        }
    }

    vres3=(int*)malloc(sizeof(int)*n);
    res3=(int**) malloc(n*sizeof(int*)+n*n*sizeof(int));//Конечный результат
    for (i=0; i<n; ++i)
    res3[i] = (int*)(res2+n) + i*n;

    TranspMatrix(&res1,n,n);

    /*PrintfMatrix(&res1,n,n);*/

    UmnozhMAtrix(&res1,&a,&res2, n, n, n, n);

   /* PrintfMatrix(&res2,n,n);*/

    StMatrix(&res2,&res3, n, 2);

    PrintfMatrix(&res3,n,n);









    return 0;
}

void RandZapoln(int ***a, int fst, int end, int n, int m)
{
    int i1, i2;
    for(i1=0;i1<(n*m);i1++)
    {
        *((*(*a))+i1)=((rand()%(end-fst))+fst);
    }

}

void PrintfMatrix(int ***a, int n, int m)
{
    int i1,i2;
    for(i1=0;i1<n;i1++)
    {
        for(i2=0;i2<m;i2++)
            printf("%6d", *((*((*a)+i1))+i2));
        printf("\n");
    }
}

/*void FileWork(int ***a, int n, int m)
{
    FILE *fp;
    fp = fopen("myfile001.txt","w");

    int i1,i2;
    for(i1=0;i1<n;i1++)
    {
        for(i2=0;i2<m;i2++)
            fprintf(fp, "%6d", *((*((*a)+i1))+i2));
        fprintf(fp, "\n");
    }
    fclose(fp);

    fp = fopen("myfile001.txt","r");
    int ch;
    while ((ch = getc(fp)) != EOF)
       putchar(ch);
    fclose(fp);
}

void TranspMatrix(int ***a, int n, int m)
{
    int **c,*d;
    int i,i1;

    d=(int*)malloc(sizeof(int)*n);
    c=(int**) malloc(m*sizeof(int*)+m*n*sizeof(int));
    for (i=0; i<m; ++i)
    c[i] = (int*)(c+m) + i*n;

    for(i=0;i<m;i++)
    {
        for(i1=0;i1<n;i1++)
        {
            c[i][i1]=*(*((*a)+i1)+i);
        }
    }

    *a=c;
}

void SumMatrix(int ***a, int ***SL, int ***Res, int n, int m)
{
    int i1,i2;
    for(i1=0;i1<n;i1++)
    {
        for(i2=0;i2<m;i2++)
            *(*((*Res)+i1)+i2)= *(*((*a)+i1)+i2) + *(*((*SL)+i1)+i2);
    }
}

void UmnozhMAtrix(int ***a, int ***Mnl, int ***Res1, int n, int m, int nMnl, int mMnl)
{
    int i1=0,i2=0,i3=0;
    for(i1=0;i1<n;i1++)
    {
        for(i2=0;i2<mMnl;i2++)
        {
            for(i3=0;i3<m;i3++)
            {
                *(*((*Res1)+i1)+i2) += (*(*((*a)+i1)+i3)) * (*(*((*Mnl)+i3)+i2));
            }
        }
    }
}

void StMatrix(int ***a, int ***Res2, int n, int St)
{
    int i,i1, i2,i3,i4,i5, i6;

    int **Res3, *vRes3;
    vRes3=(int*)malloc(sizeof(int)*n);
    Res3=(int**) malloc(n*sizeof(int*)+n*n*sizeof(int));
    for (i=0; i<n; ++i)
    Res3[i] = (int*)(Res3+n) + i*n;

   for(i5=0;i5<n;i5++)
   {
       for(i6=0;i6<n;i6++)
       {
           Res3[i5][i6]=0;
       }
   }
   for(i4=2;i4<=St;i4++)
   {
       if(i4==2)
       {
           for(i1=0;i1<n;i1++)
    {
        for(i2=0;i2<n;i2++)
        {
            for(i3=0;i3<n;i3++)
            {
                Res3[i1][i2] += (*(*((*a)+i1)+i3)) * (*(*((*a)+i3)+i2));
            }
        }
    }

    for(i5=0;i5<n;i5++)
   {
       for(i6=0;i6<n;i6++)
       {
           *(*((*Res2)+i5)+i6)=Res3[i5][i6];
       }
   }
       }
       else
       {

           for(i5=0;i5<n;i5++)
   {
       for(i6=0;i6<n;i6++)
       {
           Res3[i5][i6]=*(*((*Res2)+i5)+i6);
       }
   }

           for(i5=0;i5<n;i5++)
   {
       for(i6=0;i6<n;i6++)
       {
           *(*((*Res2)+i5)+i6)=0;
       }
   }

           for(i1=0;i1<n;i1++)
    {
        for(i2=0;i2<n;i2++)
        {
            for(i3=0;i3<n;i3++)
            {
                *(*((*Res2)+i1)+i2) += Res3[i1][i3] * (*(*((*a)+i3)+i2));
            }
        }
       }
   }

}}
   */