#include <stdio.h>

int main(void){

	int dim = 1024;
	char s[dim];
	char c;

	printf("\nInserisci una stringa e premi invio: ");
	fgets(s,dim,stdin);
	printf("\nInserisci un carattere: ");
	c = getchar();
	getchar();

	printf("\nIl carattere inserito corrisponde all'ultimo della stringa?");

	for(int i=0; i<dim; i++){
		if(s[i]=='\0'){ //quando trova la cella  che contiene /0
			if(s[i-2]==c) //controlla due celle precedenti, dove c'è l'ultimo vero carattere
				printf("\nsi\'");
			else
				printf("\nno");
			break; //esce dal for
		}
	}

	printf("\n");

	return 0;
}
//Davide Marchesi
