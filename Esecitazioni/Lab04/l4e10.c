#include <stdio.h>
#include <math.h>

int main(void) {

    int dim = 0;
    double media = 0, varianza = 0;

    do{
        printf("\nInserisci il numero di dati di cui calcolare la media: ");
        scanf("%d", &dim);
    }
    while(dim<1);

    double numbers[dim];

    for(int i=0; i<dim; i++){
        printf("\nInserisci un numero reale: ");
        scanf("%lf",&numbers[i]);
        getchar();
        media+=numbers[i];
    }
    media = media/dim;

    for(int i=0;i<dim;i++){
        varianza+=((numbers[i]-media)*(numbers[i]-media));
    }
    varianza = varianza/dim;

    printf("\nLa media aritmetica dei numeri inseriti e\': %f", media);
    printf("\nLa varianza e\': %f\nLo scarto quadratico medio e\': %f", varianza, sqrt(varianza));
    printf("\n");
    return 0;
}
//Davide Marchesi
