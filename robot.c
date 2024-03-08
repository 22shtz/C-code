#include <stdio.h>

#define n 4
int e = 5;

int plan[n][n] = { { 0 , 0 , 1 , 1} ,
                            {1 , 0 , 0 , 1} ,
                            {1 , 0 , 0 , 0} ,
                            {1 , 0 , 1 , 1} };

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
int pas = 2;
int Rx , Ry;

void afisare()
{
    printf("energie: %d\n" , e);
    int i , j;
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
            printf("%d " , plan[i][j]);
        printf("\n");
    }

}

void citireCoord()
{
    printf("coordonatele robotului:");
    scanf("%d" , &Rx);
    scanf("%d" , &Ry);

    if(plan[Rx][Ry] )
        printf("Pozitie invalida de inceput");
    else
        plan[Rx][Ry] = 2;

}

int ok(int x , int y)
{
    return(x>=0 && x<n && y>=0 && y<n && plan[x][y] == 0);
}

int solutie()
{
    return( (Rx == 0 || Rx == n-1 || Ry == 0 || Ry == n-1) && e > 1);
}

void backtr(int pas) {
    int k;
    if (solutie())
    {
        e--;
        afisare();
        e++;
    }
    else {
        for (k = 0; k < 4; k++) {
            int newRx = Rx + dx[k];
            int newRy = Ry + dy[k];
            if (ok(newRx , newRy)) {
                Rx = newRx;
                Ry = newRy;
                e--;
                plan[Rx][Ry] = pas;
                backtr(pas + 1);
                plan[Rx][Ry] = 0;
                e++;
                Rx = Rx - dx[k];
                Ry = Ry - dy[k];
            }
        }
    }
}

int main()
{
    citireCoord();
    backtr(pas+1);

    return 0;
}
