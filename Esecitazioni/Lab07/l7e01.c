#include <stdio.h>
#include <string.h>

void delete_new_line(char* string);
int lung(char* string);

int main(void){

    char string [BUFSIZ];

    printf("\nInserisci una stringa: ");
    fgets(string, BUFSIZ, stdin);

    delete_new_line(string); //elimino /n

    printf("La stringa inserita ha lunghezza %d\n", lung(string));

    return 0;
}

void delete_new_line(char* string){ //funzione che elimina /n
	int i=0;
	for (;string[i]!='\n';i++);
	string[i]='\0';
}

int lung(char* string){
    if (string==NULL)
        return -1;
    else if (*string=='\0')
        return 0;
    else
        return 1+lung(++string);
}
