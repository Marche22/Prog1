//
//	VERSIONE BELLA CON SWITCH CASE
//

#include <stdio.h>

int main(void){
	
	double a,b;
	int c = 0;

	while(1){
		printf("\n\tCALCOLATRICE\n");
		printf("Inserisci un numero reale: \n");
		scanf("%lg",&a);
		printf("Inserisci un numero reale: \n");
		scanf("%lg",&b);
		
		//scelta operazione
		
		do{
			printf("\nScegli l'operazione da eseguire: inserisci 1 per sommare, 2 per sottrarre, 3 per moltiplicare, 4 per dividere:\n");
			scanf("%d",&c);
			
			printf("\nIl risultato dell'operazione scelta Ã¨: ");	

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
					if(!b){
						printf("\nERRORE!\tNon si puÃ² dividere per 0\n");
						break;
					}
					printf("%.12g\n",a/b);
					break;

				default:
					printf("\nERRORE!\tHai inserito un numero che non corrisponde a nessuna operazione!\n");
					break;
			}	
		}
		while((c<1 || c>4)||(c==4 && b==0));
	}

	return 0;
}
//Davide Marchesi
