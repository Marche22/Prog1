#include <stdio.h>

int main(int argc, char* argv[]) {

    if(argc<3){
        printf("\nErrore! Non ci sono tutti gli argomenti necessari.\n");
        return -1;
    }
    else{
        FILE* copy_from = fopen(argv[1], "r");
        FILE* copy_on;

        if(copy_from==NULL){
            printf("\nIl file da cui copiare non esiste!\n");
            return -1;
        }
        if (fopen(argv[2], "r")!=NULL){
            char overwrite;
            do{
                printf("\nIl file su cui vuoi copiare esiste già e contiene qualcosa, vuoi sovrascriverlo? Y/N: ");
                overwrite = getchar();
                getchar();
            } while(overwrite!='Y' && overwrite!='N');

            if (overwrite=='N')
                return -1;
        }

        copy_on = fopen(argv[2], "w");

        char c;
        while((c = getc(copy_from))!=EOF)
            putc(c, copy_on);

        printf("\nCopia avvenuta!\n");

        fclose(copy_from);
        fclose(copy_on);

        return 0;
        }
}
