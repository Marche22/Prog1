#include <stdio.h>
#include <ctype.h>

int main(void){

    char str[BUFSIZ] = " ";

    printf("\nInserisci una stringa: ");
    fgets(str, BUFSIZ, stdin);
    for(int i=0; i<BUFSIZ; i++){
        if(str[i]=='\0')
            break;
        else
            str[i]=toupper(str[i]);
    }

    printf("\nLa stringa in maiuscolo e\': %s", str);
    printf("\n");

	return 0;
}
//Davide Marchesi
