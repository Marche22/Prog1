#include <stdio.h>

int main(void){

	int n, sum = 0;
	
	do{
		printf("\nInserisci un numero intero n maggiore di zero per calcolare la somma dei primi n numeri: ");
		scanf("%d",&n);
	}
	while(n<1);
	
	printf("\nCalcolo con la formula: %d\n", (n*(n+1))/2);
	
	for(int i=1; i<n+1; i++){
		sum+=i;
	}
	
	printf("Calcolo con un ciclo for: %d\n",sum);

	return 0;
}
//Davide Marchesi
