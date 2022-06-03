#include <stdio.h>
#include <stdlib.h>

void read_array(double* array, int dim);
void bubble_sort(double* array, int dim);

int main(int argc, char *argv[]) {

    if(argc<3){
        printf("\nMancanza argomenti.\n");
        return -1;
    }

    FILE* file_to_read;
    FILE* file_output;

    file_to_read = fopen(argv[1],"r");
    file_output = fopen(argv[2],"w");
    if(file_to_read==NULL || file_output==NULL){
        printf("\nErrore lettura file.\n");
        return -1;
    }

    int check_fscanf = 0;

    double* array = malloc(sizeof (double));
    if(array==NULL){
        printf("\nErrore nell'allocazione di memoria.\n");
        return -1;
    }

    int dim = 0;
    double aux = 0;
    do{
        check_fscanf = fscanf(file_to_read,"%lf",&aux);
        if(check_fscanf!=EOF){
            dim++;
            double* temp = realloc(array,dim*(sizeof(double)));
            array = temp;
            *(array+dim-1) = aux;
        }
    } while(check_fscanf!=EOF);

    fclose(file_to_read);

    read_array(array,dim);
    bubble_sort(array,dim);

    for(int i=0; i<dim; i++)
        fprintf(file_output, "%.3f ", *(array+i));

    fclose(file_output);
    printf("\n");

    return 0;
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
