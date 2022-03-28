#include <stdio.h>
#include <ctype.h>

int main(void){
	
	char c;
	
	printf("\nInserire un carattere: ");
	c = getchar();
	getchar();
	
	if(!isalpha(c)){
		printf("\nIl carattere \'%c\' non è alfabetico.\n",c);	
	}
	else{
		if(isupper(c)){
			printf("\nIl carattere \'%c\' è una lettera maiuscola\n",c);	
		}
		else{
			printf("\nIl carattere \'%c\' è una lettera minuscola\n",c);
		}
	}

	return 0;
}
//Davide Marchesi
