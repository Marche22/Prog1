#include <stdio.h>

int main(void){

	char str[1024];

	printf("Inserisci una frase, poi vai a capo: ");
	fgets(str,1024,stdin);

	printf("\n%s",str);

	return 0;
}
//Davide Marchesi
