#include <stdio.h>
#include <windows.h>
#include <TXLib.h>

int next(int a, int b, int c, int d, int e, int f, int g, int h, int p);

int main()
{
    int i, j, N=30, M=30, a, n=15, num_of_steps = 1000000;
    int t[N][M], k[N][M];

    FILE *fin;
    fin=fopen("life1.txt ", "r");

    if(fin == NULL)
    {
        printf("Проверь название файла");
        return 1;
    }

    fscanf(fin, "%d %d", &N, &M);

    for(j=0; j<N; j++)
        for(i=0; i<M; i++)
            fscanf(fin, "%d", &k[i][j]);

    fclose(fin);

    txCreateWindow(N*n+n/2, M*n+n/2);

    for(a=0; a<num_of_steps; a++)
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                t[i][j]=next(k[(N+i-1)%N][(M+j-1)%M], k[i][(M+j-1)%M], k[(i+1)%N][(M+j-1)%M],k[(N+i-1)%N][j], k[i][j], k[(i+1)%N][j], k[(N+i-1)%N][(j+1)%M], k[i][(j+1)%M], k[(i+1)%N][(j+1)%M]);
            }
        }

        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                if(k[i][j]==1)
                {
                    txSetFillColor (TX_LIGHTGREEN);
                    txSetColor (TX_LIGHTGREEN);
                    txCircle((i+1)*n, (j+1)*n, n/2);
                }
                else
                {
                    txSetFillColor (TX_BLACK);
                    txSetColor (TX_BLACK);
                    txCircle((i+1)*n, (j+1)*n, n/2);
                }
                k[i][j]=t[i][j];
            }
            printf ("\n");
        }

        Sleep(50);
        system("cls");
    }

    FILE *fout;
    fout = fopen("life2.txt", "w");


    if(fout == NULL)
    {
        printf("Проверь название файла");
        return 1;
    }

    for(j=0; j<N; j++)
    {
        for(i=0; i<M; i++)
        {
            fprintf(fout, "%d ", t[i][j]);
        }
        fprintf(fout,"\n");
    }

    fclose(fout);

    return 0;

}

int next(int a, int b, int c, int d, int e, int f, int g, int h, int p)
{
    if(e==1 && ((a+b+c+d+f+g+h+p==2)||(a+b+c+d+f+g+h+p==3)))
        e=1;
    else
    {
        if(e==0 && (a+b+c+d+f+g+h+p==3))
            e=1;
        else
            e=0;
    }
    return e;
}

