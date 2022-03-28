#include <stdio.h>
#include <ctype.h>

int main(void){
	
	char c;
	do{
		printf("\nInserire un carattere: ");
		c = getchar();
		getchar();
		
		if(c=='\n'){
			break;
		}
		else{
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
		}
	}
	while(c!='\n');
	
	return 0;
}
//Davide Marchesi
