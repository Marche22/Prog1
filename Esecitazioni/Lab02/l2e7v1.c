//
//			VERSIONE FACILE CON IF ANNIDATI
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
			
			printf("Il risultato dell'operazione scelta Ã¨: ");	

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
								printf("\nERRORE! Il divisore Ã¨ zero!\n");
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
		}
		while((c<1 || c>4)||(c==4 && b==0));
	}
	return 0;
}
//Davide Marchesi
