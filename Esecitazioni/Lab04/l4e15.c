#include <stdio.h>

int main(void){

    char str[BUFSIZ] = " ";
    int max = 0;

    do{
        printf("\nInserisci una stringa: ");
        fgets(str, BUFSIZ, stdin);
        for(int i=0; i<BUFSIZ; i++){
            if(str[i]=='\0'){
                if(max<(i-1))
                    max = i-1;
                break;
            }
        }
    }
    while(str[0]!='\n');

    printf("\nLa stringa piu\' lunga ha lunghezza: %d", max);
    printf("\n");

	return 0;
}
//Davide Marchesi
