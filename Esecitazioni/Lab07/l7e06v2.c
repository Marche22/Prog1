#include <stdio.h>
#include <string.h>

int tab[1000][1000];

int delannoy(int n, int m);
int read_matx(int rows, int coloumns);

int main(void){

    int n, m;

    do{
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &n);
        printf("Inserisci un numero secondo intero maggiore o uguale a zero: ");
        scanf("%d", &m);
    } while(n<0 || m<0);

    printf("\nQuesti sono i numeri di Delannoy fino a %d;%d:\n\n", n,m);

    delannoy(n,m);
    read_matx(n+1,m+1);

    return 0;
}

int read_matx(int rows, int coloumns){
    for(int i=0; i<rows; i++){
        printf("\n");
        for(int j=0; j<coloumns; j++)
            printf("\t%d", tab[i][j]);
    }
}

int delannoy(int n, int m){

    if (!n || !m){
        tab[n][m] = 1;
        return 1;
    }
    else{
        int d = delannoy(n-1,m)+delannoy(n,m-1)+delannoy(n-1,m-1);
        tab[n][m] = d;
        return d;
    }
}
