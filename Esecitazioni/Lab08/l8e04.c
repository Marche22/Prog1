#include <stdio.h>

int main(int argc, char const *argv[]) {

    if (argc<2){
        printf("\nManca il file come argomento!\n");
        return -1;
    }

    if(fopen(argv[1], "r")!=NULL){
        char overwrite;
        do{
            printf("\nIl file su cui vuoi copiare esiste già, vuoi sovrascriverlo? Y/N: ");
            overwrite = getchar();
            getchar();
        } while(overwrite!='Y' && overwrite!='N');

        if (overwrite=='N')
            return -1;
    }

    FILE* file_pointer = fopen(argv[1], "w");
    char string[BUFSIZ*10];
    printf("\nTutto cio\' che scrivi da ora verra\' memorizzato sul file (premi ctrl+D Linux/Mac o ctrl+z Windows per terminare):\n");
    while(fgets(string, BUFSIZ*10, stdin)!=NULL)
        fputs(string, file_pointer);

    fclose(file_pointer);
    printf("\nProcesso avvenuto correttamente!\n");

    return 0;
}
