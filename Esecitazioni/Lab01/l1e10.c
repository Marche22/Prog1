#include <stdio.h>

int main(void){
	
	//dichiarazione delle variabili
	int a,b;
	int sum, diff, prod, quot, mod;

	//richiesta e inserimento dati dell'utente
	printf("Inserire un numero intero: \n");
	scanf("%d",&a);
	printf("Inserire un numero intero: \n");
	scanf("%d",&b);
	
	//svolgimento calcoli
	sum = a+b;
	diff = a-b;
	prod = a*b;
	quot = a/b;
	mod = a%b;

	printf("\n");	
	
	//stampa a video dei risultati
	printf("La somma tra numeri inseriti è: %d\n", sum);
	printf("La differenza tra numeri inseriti è: %d\n", diff);	
	printf("Il prodotto dei numeri inseriti è: %d\n", prod);
	printf("Il risultato della divisione tra i numeri inseriti è: %d\n", quot);
	printf("Il resto della divisione tra i numeri inseriti è: %d\n", mod);
	
	return 0;
}
//Davide Marchesi
