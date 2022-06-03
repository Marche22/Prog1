#include <stdio.h>
#include <stdlib.h>

void read_array(double* array, int dim);
void bubble_sort(double* array, int dim);

int main(void) {

    int dim;
    do{
        printf("\nQuanti numeri vuoi inserire?\n");
        scanf("%d",&dim);
        getchar();
    }while(dim<2);

    double* array = calloc(dim,sizeof(double));

    if(array==NULL){
        printf("\nErrore allocamento!\n");
        return -1;
    }

    for(int i=0; i<dim; i++){
        printf("\nInserisci un numero: ");
        scanf("%lf",array+i);
    }

    read_array(array,dim);
    bubble_sort(array,dim);
    read_array(array,dim);

    free(array);

    printf("\n");

    return 0;
}

void read_array(double* array, int dim){
    printf("\n");
    for(int i=0; i<dim; i++)
        printf(" %.3f", *(array+i));
}


void bubble_sort(double* array, int dim){
    int swap = 1;
    while(swap){
        swap = 0;
        for(int i=0; i<dim-1; i++){
            if(*(array+i)>*(array+i+1)){
                double aux = *(array+i);
                *(array+i) = *(array+i+1);
                *(array+i+1) = aux;
                swap = 1;
            }
        }
    }
}
