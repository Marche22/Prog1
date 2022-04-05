#include <stdio.h>
#include <ctype.h>

int main(void){

	int dim = 1024;
	char s[dim];
	s[0]='0';
	int counter = 0;

	do{
		printf("\nInserisci una stringa e premi invio (premi solo invio per uscire): ");
		fgets(s,dim,stdin);
		if(s[0]!='\n'){ //se la stringa non è solo un invio
			printf("\nHai inserito: %s",s); //stampa
			for(int i=0;i<dim; i++){
				if(s[i]=='\0'){ //quando trova /0
					counter+=(i-1); //somma la lunghezza della stringa senza contare /n al contatore
					break; //esce dal for
				}
			}
		}
	}
	while(s[0]!='\n'); //il do while continua finché la stringa non è solo uno \n

	printf("\nHai inserito %d caratteri totali (senza contare gli invii)\n", counter);

	return 0;
}
//Davide Marchesi
