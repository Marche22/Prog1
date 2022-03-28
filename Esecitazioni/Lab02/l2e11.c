#include <stdio.h>
#include <ctype.h>

int main(void){
	
	char c;

	printf("\nInserire un carattere: \n");
	c = getchar();
	getchar();
	
	printf("Conversione, se possibile, da minuscola a maiuscola... %c\n",toupper(c));
	
	return 0;
}
//Davide Marchesi
