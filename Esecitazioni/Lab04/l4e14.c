#include <stdio.h>

int main(void){

    char str[BUFSIZ] = " ";
    int dims[BUFSIZ];
    int counter = 0, size = 0;
    double somma = 0;

    do{
        printf("\nInserisci una stringa: ");
        fgets(str, BUFSIZ, stdin);
        for(int i=0; i<BUFSIZ; i++){
            if(str[i]=='\0'){
                dims[counter]=i-1;
                break;
            }
        }
        counter++;
    }
    while(str[0]!='\n');

    for(int i=0; i<(counter-1); i++){
        somma+=dims[i];
    }

    printf("\nLa media delle lunghezze delle stringhe e\': %f", somma/(counter-1));//-1 perché non deve contare l'ultima stringa che contiene sono \n

	return 0;
}
//Davide Marchesi
