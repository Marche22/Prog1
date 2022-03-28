//
//			VERSIONE FACILE CON IF ANNIDATI
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

	if(c==1){
		printf("%.12g\n",a+b);
	}
	else{
		if(c==2){
			printf("%.12g\n",a-b);		
		}
		else{
			if(c==3){	
				printf("%.12g\n",a*b);
			}
			else{
				if(c==4){
					if(b==0){
						printf("\nERRORE! Il divisore è zero!\n");
					}
					else{
						printf("%.12g\n",a/b);
					}
				}
				else{
					printf("\nERRORE! Il numero inserito non corrisponde a nessuna operazione!\n");				
				}
			}
		}
	}
	
	return 0;
}
//Davide Marchesi
