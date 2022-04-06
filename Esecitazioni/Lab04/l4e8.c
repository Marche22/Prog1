#include <stdio.h>

int main(void) {

    int dim = 5;
    double numbers[dim];
    double somma = 0;

    for(int i=0; i<dim; i++){
        printf("\nInserisci un numero reale: ");
        scanf("%lf",&numbers[i]);
        getchar();
        somma+=numbers[i]; //aggiorna la somma aggiungendo il numero appena inserito
    }

    printf("\nLa media aritmetica dei numeri inseriti e\': %f", somma/dim);
    printf("\n");
    return 0;
}
//Davide Marchesi
