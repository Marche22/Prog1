#include <stdio.h>
#include <string.h>

int catalan(int n);

int main(void){

    int num;

    do{
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &num);
    } while(num<0);

    printf("\nQuesti sono i primi %d numeri di Catalan: ", num);
    printf("\n\tn\tC(n)\n");

    for(int i=0; i<=num; i++){
        printf("\t%d\t%d\n", i, catalan(i));
    }

    return 0;
}

int catalan(int n){
    if (!n){
        return 1;
    }
    else
        return 2*(2*n-1)*catalan(n-1)/(n+1);
}
