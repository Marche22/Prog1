#include <stdio.h>

int main(void) {

    int dim = 0;
    double somma = 0;

    do{
        printf("\nInserisci il numero di dati di cui calcolare la media: ");
        scanf("%d", &dim);
        getchar();
    }
    while(dim<1);

    double numbers[dim];

    for(int i=0; i<dim; i++){
        printf("\nInserisci un numero reale: ");
        scanf("%lf",&numbers[i]);
        getchar();
        somma+=numbers[i];
    }

    printf("\nLa media aritmetica dei numeri inseriti e\': %f", somma/dim);
    printf("\n");
    return 0;
}
//Davide Marchesi
