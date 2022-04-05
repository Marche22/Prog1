#include <stdio.h>
#include <ctype.h>

int main(void){

	int dim = 1024;
	char s[dim];

	printf("\nInserisci un nome di persona: ");
	fgets(s,dim,stdin);

	for(int i=0; i<dim; i++){
		if(s[i]=='\0'){ 	//quando trova /0
			if(isalpha(s[i-2])){ 	//controlla due celle prima, se è un carattere alfabetico
				if(s[i-2]=='a'||s[i-2]=='e') //se finisce con a o e
					printf("\nIl nome inserito è femmminile");
				else if(s[i-2]=='o'||s[i-2]=='i') //se finisce con i o o
					printf("\nIl nome inserito è maschile");
				else //altrimenti
					printf("\nNon so dedurre il genere del nome, mi arrendo :(");
			}
			else //se non è alfabetico da errore
				printf("\nIl nome inserito non è valido!");
			break; //esce dal for
		}
	}

	printf("\n");

	return 0;
}
//Davide Marchesi
