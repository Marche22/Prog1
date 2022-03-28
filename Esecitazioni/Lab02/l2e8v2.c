//
//	VERSIONE BELLA CON SWITCH CASE
//

#include <stdio.h>

int main(void){
	
	double a,b;
	int c;

	do{
		printf("\n\tCALCOLATRICE\n");
		printf("Inserisci un numero reale: \n");
		scanf("%lg",&a);
		printf("Inserisci un numero reale: \n");
		scanf("%lg",&b);
		
		//scelta operazione
		
		do{
			printf("\nScegli l'operazione da eseguire: inserisci 1 per sommare, 2 per sottrarre, 3 per moltiplicare, 4 per dividere e 0 per uscire dal programma:\n");
			scanf("%d",&c);	

			switch(c){
				case 0:
					break;

				case 1:
					printf("\nIl risultato dell'operazione scelta è: %.12g\n",a+b);
					break;

				case 2:
					printf("\nIl risultato dell'operazione scelta è: %.12g\n",a-b);
					break;

				case 3:
					printf("\nIl risultato dell'operazione scelta è: %.12g\n",a*b);
					break;

				case 4:
					if(!b){
						printf("\nERRORE!\tNon si può dividere per 0\n");
						break;
					}
					printf("\nIl risultato dell'operazione scelta è: %.12g\n",a/b);
					break;

				default:
					printf("\nERRORE!\tHai inserito un numero che non corrisponde a nessuna operazione!\n");
					break;
			}	
		}
		while((c<0 || c>4)||(c==4 && b==0));
	}
	while(c!=0);

	return 0;
}
//Davide Marchesi
