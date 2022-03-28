#include <stdio.h>

int main(void){
	
	//int
	int n1;
	printf("Inserire un numero intero: \n");
	scanf("%d",&n1);
	printf("E\' stato inserito il numero %d\n", n1);
	
	printf("\n");

	//double
	double n2;	
	printf("Inserire un numero decimale: \n");
	scanf("%lg",&n2);
	printf("E\' stato inserito il numero %.10g\n", n2); //.10 indica che terrà 10 cifre		


	return 0;
}
//Davide Marchesi
