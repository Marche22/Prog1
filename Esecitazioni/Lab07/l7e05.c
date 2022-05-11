#include <stdio.h>
#include <string.h>

int delannoy(int n, int m);

int main(void){

    int n, m;

    do{
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &n);
        printf("Inserisci un numero secondo intero maggiore o uguale a zero: ");
        scanf("%d", &m);
    } while(n<0 || m<0);

    printf("Il numero di Delannnoy %d;%d e\': %d\n", n, m, delannoy(n,m));

    return 0;
}

int delannoy(int n, int m){
    if (!n || !m){
        return 1;
    }
    else
        return delannoy(m-1,n)+delannoy(m,n-1)+delannoy(m-1,n-1);
}
