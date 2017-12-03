#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void Read(int S[MAX][MAX], int *size);
int MinRow(int S[MAX][MAX], int size, int row);
int MaxRow(int S[MAX][MAX], int size, int row);
int MinCol(int S[MAX][MAX],int size, int col);
int MaxCol(int S[MAX][MAX],int size, int col);
int HowMany(int S[MAX][MAX], int size);

int main()
{
    int S[MAX][MAX];
    int size;
    int ats;

    Read(S,&size);
    ats = HowMany(S,size);
    printf("Matricos balnu skaicius yra %d",ats);

    return 0;
}

void Read(int S[MAX][MAX], int *size)
{
    int y,x;
    scanf("%d",size);

    for(y = 0; y < *size; y++)
        for(x = 0; x < *size; x++)
            scanf("%d",&S[y][x]);
}

int MinRow(int S[MAX][MAX], int size, int row)
{
    int x;
    int min = S[row][0];

    for(x = 0; x < size; x++)
        if(min > S[row][x])
            min = S[row][x];

    return min;
}

int MaxRow(int S[MAX][MAX], int size, int row)
{
    int x;
    int max = S[row][0];

    for(x = 0; x < size; x++)
        if(max < S[row][x])
            max = S[row][x];

    return max;
}

int MinCol(int S[MAX][MAX],int size, int col)
{
    int min;
    int y;

    min = S[0][col];

    for(y = 0; y < size; y++)
    {
        if(min > S[y][col])
            min = S[y][col];
    }

    return min;
}

int MaxCol(int S[MAX][MAX],int size, int col)
{
    int max;
    int y;

    max = S[0][col];

    for(y = 0; y < size; y++)
    {
        if(max < S[y][col])
            max = S[y][col];
    }
    return max;
}

int HowMany(int S[MAX][MAX], int size)
{
    int y,x;
    int minRow,maxRow;
    int a = 0;

    for(y = 0; y < size; y++)
    {
        minRow = MinRow(S,size,y);
        maxRow = MaxRow(S,size,y);

        for(x = 0; x < size; x++)
        {
            if(minRow == MaxCol(S,size,x) || maxRow == MinCol(S,size,x))
                a++;
        }

    }
    return a;
}
