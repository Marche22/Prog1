#include <stdio.h>

void print_menu();
double somma(double a, double b);
double differenza(double a, double b);
double prodotto(double a, double b);
double divisione(double a, double b);

int main(void){

		double num1, num2;
		char scelta;
		int check_operandi = 0; //serve per sapere se l'utente ha già inserito gli operandi

		printf("\n\t\tCALCOLATRICE\n");//titolo

	do{ //menù finchè l'utente non digita 5
		print_menu(); //stampa menù
		scelta = getchar();
		getchar();

		if(!check_operandi && (scelta=='1'||scelta=='2'||scelta=='3'||scelta=='4')){ //se non sono stati ancora inseriti gli operandi ma l'utente digita un'operazione
			printf("\nErrore,non puoi selezionare un'operazione senza prima aver inserito i due operandi!");
			scelta = 'X'; //rendendo scelta un carattere qualsiasi lo switch farà ripartire il menù
		}

		switch (scelta) {
			case '0': //inserimento operandi
				printf("\nInserire due numeri reali: ");//inserimento numero numeri
				scanf("%lf%lf", &num1, &num2);
				getchar();
				check_operandi=1;; //gli operandi sono stati inseriti
				break;
			case '1': //addizione
				printf("\n%f + %f= %f",num1, num2, somma(num1,num2));
				break;
			case '2': //sottrazione
				printf("\n%f - %f= %f",num1, num2, differenza(num1,num2));
				break;
			case '3': //moltiplicazione
				printf("\n%f * %f= %f",num1, num2, prodotto(num1,num2));
				break;
			case '4': //divisione
				if(!num2)
					printf("\nErrore! Il divisore non può essere zero!"); //errore
				else
					printf("\n%f / %f= %f",num1, num2, divisione(num1,num2));
				break;
			case '5': //uscita
				return 0;
			default: //altri casi
				if(scelta!='X')
					printf("\nErrore! Hai inserito un'opzione inesistente"); //errore
				break;
		}
	}
	while(1);

	return 0;
}
//Davide Marchesi

void print_menu(){
	printf("\n\nCosa vuoi fare?\n0. Inserisci operandi.\n1. Addizione.\n2. Sottrazione.\n3. Moltiplicazione.\n4. Divisione.\n5. Esci.\n>"); //menù
}

double somma(double a, double b){
	return a+b;
}

double differenza(double a, double b){
	return a-b;
}

double prodotto(double a, double b){
	return a*b;
}

double divisione(double a, double b){
	if(b!=0)
		return a/b;
}
