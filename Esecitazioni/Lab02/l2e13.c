#include <stdio.h>
#include <ctype.h>

int main(void){
	
	char c;
	int s;

	printf("\nInserire un carattere: \n");
	c = getchar();
	getchar();

	if(!isalpha(c)){
		printf("\nERRORE!\tIl carattere inserito non è alfabetico!\n");
	}
	else{

		printf("\nInserire '1' per convertire in maiuscolo o un altro numero intero per convertire in minuscolo\n");
		scanf("%d",&s);

		if(s==1){
			printf("\nConversione, se possibile, da minuscola a maiuscola... %c\n",toupper(c));
		}
		else{
			printf("\nConversione, se possibile, da maiuscola a minuscola... %c\n",tolower(c));
		}
	}

	return 0;
}
//Davide Marchesi
