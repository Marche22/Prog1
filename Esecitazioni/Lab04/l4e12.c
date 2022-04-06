#include <stdio.h>

int main(void){

    int scambio = 1, dim = 5, counter = 0;
    double v[5] = {4,5,-1,0.5,12};
    double aux;


    printf("\n");

    for(int i=0; i<dim; i++)
        printf(" %f", v[i]);

    while(scambio){
        scambio = 0;
        for(int i=0; i<dim-1; i++){
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                scambio = 1;
                counter++;
            }
        }
    }

    printf("\n");

    for(int i=0; i<dim; i++)
        printf(" %f", v[i]);

    printf("\nIl vettore è stato ordinato con %d scambi; (dim^2)/2 = %f", counter, (float)dim*(float)dim/2);

    printf("\n");
    return 0;
}
