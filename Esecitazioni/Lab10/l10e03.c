#include <stdio.h>
#include <stdlib.h>

void read_array(double* array, int dim);
void bubble_sort(double* array, int dim);
int menu(void);
double* set_dim_array(double* array, int* dim);
void fill_array(double* array,int start, int dim);

int main(void) {

    int dim = 0;
    int array_exist = 0;
    double* array = NULL;
    int choice;

    do{
        switch (choice=menu()) {
            case 1:
                if(array_exist){
                    free(array);
                }
                array = set_dim_array(array,&dim);
                if(array==NULL)
                    break;
                fill_array(array,0,dim);
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
                if(!array_exist)
                    printf("\nNon hai inserito alcun array da ordinare, inseriscilo tramite l'opzione 1.\n");
                else{
                    int start = dim;
                    array = set_dim_array(array,&dim);
                    fill_array(array,start,dim);
                }
                break;
            case 5:
                free(array);
                break;
            default:
                break;
            }
    } while(choice!=5);

    printf("\n");

    return 0;
}

int menu(void){
    int choice;
    printf("\n\tMENU'\n");
    printf("\n1. Inserisci elenco di double.\n2. Ordina elenco.\n3. Visualizza elenco.\n4. Aggiungi elementi.\n5. Termina.\n");
    do{
        printf("\nScegli un'opzione: ");
        scanf("%d", &choice);
        getchar();
    }while(choice>4 || choice<1);
    return choice;
}

double* set_dim_array(double* array, int* dim){
    int dim_min = (*dim);
        dim_min = 2;
    do{
        printf("\nInserisci la dimensione dell'array: \n");
        scanf("%d",dim);
        getchar();
        if(*dim<=dim_min)
            printf("\nReinserisci il numero in modo che sia maggiore di %d\n",dim_min-1);
    }while(*dim<=dim_min);

    if(array==NULL){
        array = calloc(*dim,sizeof(double));
    }
    else{
        double* temp = realloc(array, (*dim)*(sizeof (double)));
        array = temp;
    }

    if(array==NULL){
        printf("\nErrore di allocazione della memoria.\n");
        return NULL;
    }
    return array;
}

void fill_array(double* array, int start, int dim){
    for(int i=start; i<dim; i++){
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
