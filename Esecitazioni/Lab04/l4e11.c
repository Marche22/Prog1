#include <stdio.h>

int main(void){

    int scambio = 1;
    double v[5] = {4,5,-1,0.5,12};
    double aux;

    printf("\n");

    for(int i=0; i<5; i++)
        printf(" %f", v[i]);

    while(scambio){
        scambio = 0;
        for(int i=0; i<5-1; i++){
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                scambio = 1;
            }
        }
    }

    printf("\n");

    for(int i=0; i<5; i++)
        printf(" %f", v[i]);

    printf("\n");
    return 0;
}
