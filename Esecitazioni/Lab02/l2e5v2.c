//
//	VERSIONE BELLA CON SWITCH CASE
//


#include <stdio.h>

int main(void){
	
	double a,b;
	
	printf("Inserisci un numero reale: \n");
	scanf("%lg",&a);
	printf("Inserisci un numero reale: \n");
	scanf("%lg",&b);
	
	//scelta operazione
	int c = 0;

	printf("\nScegli l'operazione da eseguire: inserisci 1 per sommare, 2 per sottrarre, 3 per moltiplicare, 4 per dividere:\n");
	scanf("%d",&c);
	
	printf("Il risultato dell'operazione scelta è: ");	

	switch(c){
		case 1:
			printf("%.12g\n",a+b);
			break;

		case 2:
			printf("%.12g\n",a-b);
			break;

		case 3:
			printf("%.12g\n",a*b);
			break;

		case 4:
			printf("%.12g\n",a/b);
			break;

		default:
			break;
	}	
	
	return 0;
}
//Davide Marchesi
