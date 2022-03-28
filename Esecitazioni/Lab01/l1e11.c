#include <stdio.h>

int main(void){
	
	//dichiarazione delle variabili
	double a,b;
	double sum, diff, prod, quot;

	//richiesta e inserimento dati dell'utente
	printf("Inserire un numero (anche decimale): \n");
	scanf("%lg",&a);
	printf("Inserire un numero (anche decimale): \n");
	scanf("%lg",&b);
	
	//svolgimento calcoli
	sum = a+b;
	diff = a-b;
	prod = a*b;
	quot = a/b;

	printf("\n");	
	
	//stampa a video dei risultati
	printf("La somma tra numeri inseriti è: %g\n", sum);
	printf("La differenza tra numeri inseriti è: %g\n", diff);	
	printf("Il prodotto dei numeri inseriti è: %g\n", prod);
	printf("Il risultato della divisione tra i numeri inseriti è: %g\n", quot);
	printf("Il resto della divisione non è un'operazione lecita per variabili double.\n");
	
	return 0;
}
//Davide Marchesi
