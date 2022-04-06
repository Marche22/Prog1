#include <stdio.h>

int main(void){

	int a;
	int b;
	int temp = 0;
	int counter = 0;
	
	printf("\n\tALGORITMO EUCLIDEO\n");	
	
	printf("\nInserisci un numero intero non nullo: ");
	scanf("%d",&a);
	printf("\nInserisci un altro numero intero non nullo: ");
	scanf("%d",&b);
	
	if(a<1 || b<1){
		return -1;
	}
	
	printf("\nIl mcd tra %d e %d e\': ", a, b);
	
	while(b){
		temp = b;
		b = a%b;
		a = temp;
		counter++;
	}	

	printf("%d\nE\' stato calcolato con %d divisioni dell'algoritmo euclideo\n", a, counter);

	return 0;
}
//Davide Marchesi
