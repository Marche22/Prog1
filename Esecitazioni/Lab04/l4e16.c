#include <stdio.h>

int main(void){

    char str[BUFSIZ] = " ";
    char c = '0';
    int counter = 0;
    double dim;

    printf("\nInserisci una stringa: ");
    fgets(str, BUFSIZ, stdin);
    printf("Inserisci un carattere: ");
    scanf("%c",&c);
    getchar();

    if(c=='\n')
        return 0;

    for(int i=0; i<BUFSIZ; i++){
        if(str[i]=='\0'){
            dim = i-1;
            break;
        }
        else if(str[i]==c){
            counter++;
        }
    }

    printf("\nLa frequenza del carattere \'%c\' e\': %d/%d=%f",c , counter, (int) dim, counter/dim);
    printf("\n");

	return 0;
}
//Davide Marchesi
