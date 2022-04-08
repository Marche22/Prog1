#include <stdio.h>
#include <math.h>

int main(void) {

    int dim = 0, scambio;
    double media = 0, varianza = 0, mediana = 0, aux;

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
        media+=numbers[i];
    }
    media = media/dim;

    for(int i=0;i<dim;i++){
        varianza+=((numbers[i]-media)*(numbers[i]-media));
    }
    varianza = varianza/dim;

    while(scambio){
    scambio = 0;
        for(int i=0; i<dim-1; i++){
            if(numbers[i]>numbers[i+1]){
                aux = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = aux;
                scambio = 1;
            }
        }
    }

    if(!(dim%2))
        mediana = ((numbers[dim/2])+(numbers[(dim/2)-1]))/2;    
    else
        mediana = numbers[((dim+1)/2)-1];

    printf("\nLa media aritmetica dei numeri inseriti e\': %f", media);
    printf("\nLa varianza e\': %f\nLo scarto quadratico medio e\': %f", varianza, sqrt(varianza));
    printf("\nLa mediana e\': %f", mediana);
    printf("\n");
    return 0;
}
//Davide Marchesi
