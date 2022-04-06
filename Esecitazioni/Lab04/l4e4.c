#include <stdio.h>

int main(void){

	int dim = 1024; 	//dimensione max della stringa
	char str[dim];

	printf("Inserisci una frase, poi vai a capo: ");
	fgets(str,dim,stdin);

	for(int i=0; i<dim; i++){	//quando trova il carattere /0 siamo nella i-esiam cella
		if(str[i]=='\0'){ 		//\0 è nella cella i, quindi \n nella cella i-1, e l'ultimo vero carattere in i-2
			printf("\nLa stringa inserita ha lunghezza %d (senza contare invio)",i-1); //la lunghezza è i-1 perché parto da 0, quindi i-2+1
			break; //esce dal for
		}
	}

	printf("\n");

	return 0;
}
//Davide Marchesi
