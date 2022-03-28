#include <stdio.h>

int main(void){

	int a=0, b=0;
	
	printf("\nInserisci un numero naturale maggiore di zero: ");
	scanf("%d",&a);
	printf("\nInserisci un secondo numero naturale maggiore di zero: ");
	scanf("%d",&b);

	 printf("Il m.c.d. di %d e %d e': ",a,b);
	
	 while (a != b){
	 	if (a > b){ 
	 		a = a-b;
		}
	 	else{
			b = b-a;
		}
	}
	
	printf("%d\n",a);

	return 0;
}
//Davide Marchesi
