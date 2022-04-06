#include <stdio.h>

int main(void){

	int a;
	int b;
	int temp = 0;
	
	printf("\n\tALGORITMO EUCLIDEO\n");	
	
	printf("\nInserisci un numero intero non nullo: ");
	scanf("%d",&a);
	printf("\nInserisci un altro numero intero non nullo: ");
	scanf("%d",&b);
	
	printf("\nIl mcd tra %d e %d e\': ", a, b);
	
	while(b){
		temp = b;
		b = a%b;
		a = temp;
	}	

	printf("%d\n", a);

	return 0;
}
//Davide Marchesi
