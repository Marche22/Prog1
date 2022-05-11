#include <stdio.h>
#include <string.h>

int catalan(int n);

int main(void){

    int num;
    
    do{
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &num);
    } while(num<0);

    printf("Il %d-esimo numero di Catalan e\': %d\n", num, catalan(num));

    return 0;
}

int catalan(int n){
    if (!n){
        return 1;
    }
    else
        return 2*(2*n-1)*catalan(n-1)/(n+1);
}
