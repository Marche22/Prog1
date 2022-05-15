#include <stdio.h>
#include <string.h>

int tab[1000][1000];
int counter = 0;

int delannoy(int n, int m);
int read_matx(int rows, int coloumns);
int clean_matx(int rows, int coloumns, int matx[1000][1000]);

int main(void){

    int n, m;

    do{
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &n);
        printf("Inserisci un numero secondo intero maggiore o uguale a zero: ");
        scanf("%d", &m);
    } while(n<0 || m<0);

    printf("\nQuesti sono i numeri di Delannoy fino a %d;%d:\n\n", n,m);

    clean_matx(n, m, tab);
    delannoy(n,m);
    read_matx(n,m);
    printf("\n\nChiamate funzione = %d\n", counter);

    return 0;
}

int clean_matx(int rows, int coloumns, int matx[1000][1000]){
    for(int i=0; i<=rows; i++){
        for(int j=0; j<=coloumns; j++)
            tab[i][j] = 0;
    }
}

int read_matx(int rows, int coloumns){
    for(int i=0; i<=rows; i++){
        printf("\n");
        for(int j=0; j<=coloumns; j++)
            printf("\t%d", tab[i][j]);
    }
}

int delannoy(int n, int m){
    counter ++;
    if (!n || !m){
        tab[n][m] = 1;
        tab[m][n] = 1;
        return 1;
    }
    else{
        int d1, d2, d3 = 0;
        if(tab[n][m]!=0 || tab[n][m]!=0){ //se è già stato calcolato
            if(tab[n][m]!=0){
                tab[m][n]=tab[n][m];
                return tab[n][m];
            }
            else{
                tab[n][m]=tab[m][n];
                return tab[n][m];
            }
        }
        else{
            if(tab[n-1][m]!=0 || tab[m][n-1]!=0){ //se n-1,m è già stato calcolato (o il simm)
                if(tab[n-1][m]!=0){
                    tab[m][n-1]=tab[n-1][m];
                    d1 = tab[n-1][m];
                }
                else{
                    tab[n-1][m]=tab[m][n-1];
                    d1 = tab[n-1][m];
                }
            }
            else
                d1 = delannoy(n-1,m);

            if(tab[n][m-1]!=0 || tab[m-1][n]!=0){ //se n,m-1 è già stato calcolato (o il simm)
                if(tab[n][m-1]!=0){
                    tab[m-1][n]=tab[n][m-1];
                    d2 = tab[n][m-1];
                }
                else{
                    tab[n][m-1]=tab[m-1][n];
                    d2 = tab[n][m-1];
                }
            }
            else
                d2 = delannoy(n,m-1);

            if(tab[n-1][m-1]!=0 || tab[m-1][n-1]!=0){ //se n-1,m-1 è già stato calcolato (o il simm)
                if(tab[n-1][m-1]!=0){
                    tab[m-1][n-1]=tab[n-1][m-1];
                    d3 = tab[n-1][m-1];
                }
                else{
                    tab[n-1][m-1]=tab[m-1][n-1];
                    d3 = tab[n-1][m-1];
                }
            }
            else
                d3 = delannoy(n-1,m-1);

            int d = d1+d2+d3;
            tab[n][m] = d;
            tab[m][n] = d;
            return d;
        }
    }
}
