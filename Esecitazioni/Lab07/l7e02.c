#include <stdio.h>
#include <string.h>

int occ(char* string, char c);

int main(void){

    char string [BUFSIZ];

    printf("\nInserisci una stringa: ");
    fgets(string, BUFSIZ, stdin);
    printf("\nInserisci un carattere da cercare: ");
    char c = getchar();
    getchar();

    printf("Il carattere inserito compare %d volte nella stringa\n", occ(string,c));

    return 0;
}

int occ(char* string, char c){
    int i=0;
    if (string==NULL)
        return -1;
    else
        for(;*(string+i)!='\0';i++){ //scorro la stringa
            if (*(string+i)==c) //se trovo il carattere richiamo la funzione partendo dalla posizione dopo
                return 1+occ(string+i+1,c);
        }
        return 0; //se esco dal for significa che non ha mai trovato il carattere
}
