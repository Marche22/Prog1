#include <stdio.h>

int main(void){

		double num1, num2;
		char scelta;

		printf("\n\t\tCALCOLATRICE\n");//titolo
		printf("\nInserire due numeri reali: ");//inserimento numero numeri
		scanf("%lf%lf", &num1, &num2);
		getchar();

	do{ //menù finchè l'utente non digita 5
		printf("\n\nCosa vuoi fare?\n1. Addizione.\n2. Sottrazione.\n3. Moltiplicazione.\n4. Divisione.\n5. Esci.\n>"); //menù
		scelta = getchar();
		getchar();
		switch (scelta) {
			case '1': //addizione
				printf("\n%f + %f= %f",num1, num2, num1+num2);
				break;
			case '2': //sottrazione
				printf("\n%f - %f= %f",num1, num2, num1-num2);
				break;
			case '3': //moltiplicazione
				printf("\n%f * %f= %f",num1, num2, num1*num2);
				break;
			case '4': //divisione
				if(!num2)
					printf("\nErrore! Il divisore non può essere zero!"); //errore
				else
					printf("\n%f / %f= %f",num1, num2, num1/num2);
				break;
			case '5': //uscita
				return 0;
			default: //altri casi
				printf("\nErrore! Hai inserito un'opzione inesistente"); //errore
				break;
		}
	}
	while(1);

	return 0;
}
//Davide Marchesi
