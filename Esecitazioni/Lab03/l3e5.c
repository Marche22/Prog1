#include <stdio.h>

int main(void){

	int a = 100;
	int b = 46;
	int temp = 0;
	
	printf("\n\tALGORITMO EUCLIDEO\n");
	printf("Il mcd tra %d e %d e\': ", a, b);
	
	while(b){
		temp = b;
		b = a%b;
		a = temp;
	}	

	printf("%d\n", a);

	return 0;
}
//Davide Marchesi
