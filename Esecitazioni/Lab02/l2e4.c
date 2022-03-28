#include <stdio.h>

int main(void){

	int a=0, b=0;
	int c=0; //variabile contatore
	
	printf("\nInserisci un numero naturale maggiore di zero: ");
	scanf("%d",&a);
	printf("\nInserisci un secondo numero naturale maggiore di zero: ");
	scanf("%d",&b);
	
	//if controlla che né a né b siano <=0
	if(a<=0 || b<=0){
		printf("\nERRORE!\nAlmeno uno dei due numeri inseriti non è maggiore di zero!");
	}
	else{
		printf("Il m.c.d. di %d e %d e': ",a,b);
		
		 while (a != b){
		 	if (a > b){ 
		 		a = a-b;
			}
		 	else{
				b = b-a;
			}
			c++;
		}
		
		printf("%d\nOttenuto usando %d iterazioni\n",a,c);

		return 0;
	}
}
//Davide Marchesi
