#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int* string_to_int_array(char* string, int files, int* numbers);
int string_length(char* string);
void clean_int_array(int* array, int dim);
void bubblesort(int* array, int length);

int main(int argc, char *argv[]) {

    if (argc<2){
        printf("\nMancanza di argomenti!\n");
        return -1;
    }
    if (strcmp(argv[1], "lista_file_i.txt")){
        printf("\nErrore, la stringa inserita non e\' il nome del file necessario.");
        return -1;
    }

    FILE* starting_file = fopen(argv[1],"r");
    char string_from_starting_file [BUFSIZ];
    fgets(string_from_starting_file,BUFSIZ,starting_file);

    char number_file_names[100][BUFSIZ];
    int file_counter = 0;
    int index = 0;
    int i=0;
    for(i=0; *(string_from_starting_file+i)!='\0'; i++){
        if (*(string_from_starting_file+i)==';'){
            number_file_names[file_counter][index] = '\0';
            index = 0;
        file_counter++;
        }
        else{
            number_file_names[file_counter][index] = (*(string_from_starting_file+i));
            index++;
        }
    }

    fclose(starting_file);

    int numbers[1000];
    int* index_of_array = numbers;
    FILE* file_with_numbers[file_counter+1];

    for(i=0; i<file_counter+1; i++){
        file_with_numbers[i] = fopen(number_file_names[i],"r");
        char string_of_numbers[BUFSIZ*10];
        fgets(string_of_numbers, BUFSIZ*10, file_with_numbers[i]);
        index_of_array = string_to_int_array(string_of_numbers,i,index_of_array);
    }

    for(i=0; i<file_counter+1; i++)
        fclose(file_with_numbers[i]);

    for(i=0;*(numbers+i)!=0;i++);
    int length = i;
    bubblesort(numbers,length);

    FILE* output_file = fopen("sequenza_risultante.txt","w");
    for(i=0;i<length;i++){
        fprintf(output_file, "%d", *(numbers+i));
        if(i!=length-1)
            fprintf(output_file, " ");
    }
    fclose(output_file);
    printf("\nProcedimento completato.\n");
    return 0;
}

int string_length(char* string){
    int i=0;
    for(;*(string+i)!='\0';i++);
    return i;
}

void clean_int_array(int* array, int dim){
    for(int i=0; i<dim; i++){
        *(array+i) = 0;
    }
}

int* string_to_int_array(char* string, int files, int* numbers){

    int save_numbers[10];
    int temp = 0;
    int counter = 0;
    int num_length = 0;
    int length = string_length(string);
    *(string+length)=' ';
    *(string+length+1)='\0';

    for(int i=0; *(string+i)!='\0'; i++){
        if( (*(string+i))!=' ' ){
            save_numbers[num_length] = (*(string+i)-'0');
            num_length++;
        }
        else{
            for(int k=0; k<num_length; k++){
                temp += save_numbers[k]*(pow(10,num_length-1-k));
            }
            *(numbers+counter)=temp;
            counter++;
            clean_int_array(save_numbers,10);
            temp = 0;
            num_length = 0;
        }
    }
    return numbers+counter;
}

void bubblesort(int* array, int length){
    int swap = 1;
    int aux;
    while(swap){
        swap = 0;
        for(int i=0; i<length-1; i++){
            if(*(array+i)>(*(array+i+1))){
                aux = (*(array+i));
                (*(array+i)) = (*(array+i+1));
                (*(array+i+1)) = aux;
                swap = 1;
            }
        }
    }
}
