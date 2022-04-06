#include <stdio.h>

int main(void){

	int n;
	int temp = 0;
	int counter = 0;
	
	printf("Inserisci un numero intero non nullo: ");
	scanf("%d",&n);
	printf("\nI due minimi interi per cui l'algoritmo euclideo fa %d divisioni sono: ",n);
	
	int f_i=1, f_prec=1;

 	for (int i=3; i<=n+2; i++){ 			
 		int aux=f_i; 				
 		f_i += f_prec;				
 		f_prec=aux; 				
 	}
 	
 	printf("%d e %d\nInfatti, applico l'algoritmo euclideo...", f_i, f_prec);
	
	printf("\nIl mcd tra %d e %d e\': ", f_i, f_prec);

	while(f_prec){
		temp = f_prec;
		f_prec = f_i%f_prec;
		f_i = temp;
		counter++;
	}
	printf("%d, calcolato con %d divisioni", f_i, counter);
	
 	return 0;
}
//Davide Marchesi