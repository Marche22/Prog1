#include <stdio.h>
#include <stdlib.h>

void read_array(double* array, int dim);
void bubble_sort(double* array, int dim);
int menu(void);
double* set_dim_array(int* dim);
void fill_array(double* array, int dim);

int main(void) {

    int dim;
    int array_exist = 0;
    double* array = NULL;
    int choice;

    do{
        switch (choice=menu()) {
            case 1:
                if(array_exist){
                    free(array);
                }
                set_dim_array(&dim);
                if(array==NULL)
                    break;
                fill_array(array,dim);
                array_exist = 1;
                break;
            case 2:
                if(!array_exist)
                    printf("\nNon hai inserito alcun array da ordinare, inseriscilo tramite l'opzione 1.\n");
                else
                    bubble_sort(array,dim);
                break;
            case 3:
                if(!array_exist)
                    printf("\nNon hai inserito alcun array da ordinare, inseriscilo tramite l'opzione 1.\n");
                else
                    read_array(array,dim);
                break;
            case 4:
                free(array);
                return 0;
                break;
            default:
                break;
            }
    } while(choice!=4);

    printf("\n");

    return 0;
}

int menu(void){
    int choice;
    printf("\n\tMENU'\n");
    printf("\n1. Inserisci elenco di double.\n2. Ordina elenco.\n3. Visualizza elenco.\n4. Termina.\n");
    do{
        printf("\nScegli un'opzione: ");
        scanf("%d", &choice);
        getchar();
    }while(choice>4 || choice<1);
    return choice;
}

double* set_dim_array(int* dim){
    do{
        printf("\nQuanti numeri vuoi inserire?\n");
        scanf("%d",dim);
        getchar();
        if(*dim<2)
            printf("\nReinserisci il numero in modo che sia maggiore di 2\n");
    }while(*dim<2);

    double* array = calloc(*dim,sizeof(double));

    if(array==NULL){
        printf("\nErrore allocazione!\n");
        return NULL;
    }
    return array;
}

void fill_array(double* array, int dim){
    for(int i=0; i<dim; i++){
        printf("\nInserisci un numero: ");
        scanf("%lf",array+i);
    }
}

void read_array(double* array, int dim){
    printf("\n");
    for(int i=0; i<dim; i++)
        printf("%.3f ", *(array+i));
    printf("\n");
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
