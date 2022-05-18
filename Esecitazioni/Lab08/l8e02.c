#include <stdio.h>

int main(int argc, char* argv[]) {

    if(argc<2){
        printf("\nErrore! Devi inserire come argomento un file.\n");
        return -1;
    }
    else{
        FILE* file_pointer = fopen(argv[1], "r");

        if(file_pointer==NULL){
            printf("\nIl file inserito non esiste!\n");
            return -1;
        }
        else{
        char string[BUFSIZ*10];

            while(fgets(string, BUFSIZ*10, file_pointer)!=NULL)
            printf("%s", string);

        fclose(file_pointer);

        return 0;
        }
    }
}
