#include <stdio.h>

int main(void){

    char str[BUFSIZ];
    char substr[BUFSIZ];
    int dim, counter;

    printf("\nInserisci una stringa: ");
    fgets(str, BUFSIZ, stdin);
    printf("\nInserisci un'altra stringa: ");
    fgets(substr, BUFSIZ, stdin);

    for(int i=0; i<BUFSIZ; i++){
        if(substr[i]=='\0'){
            dim = i-1;
            break;
        }
    }

    for(int j=0; j <BUFSIZ; j++){
        if(substr[0]==str[j]){
            counter = 1;
            for(int i=1; i<dim; i++){
                if(str[j+i]==substr[i]){
                    counter++;
                    if(counter==dim){
                        printf("\nLa seconda stringa e\' contenuta nella prima!\n");
                        return 0;
                    }
                }
                else
                    break;
                }
            }
        }


    if(counter!=dim)
        printf("\nLa seconda stringa non e\' contenuta nella prima!");


    printf("\n");
	return 0;
}
//Davide Marchesi
