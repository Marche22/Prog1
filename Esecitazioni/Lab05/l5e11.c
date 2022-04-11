#include <stdio.h>

//funzione che chiede all'utente di inserire la dimensione di una matrice quadrata
int dim_matx(void);

//funzione che stampa il menù
void print_menu(void);

//funzione che permette di inserire i numeri in una matrice di double
void write_matx(int dim, double m[dim][dim]);

//funzione che stampa una matrice di double
void print_matx(int dim, double m[dim][dim]);

//funzione che date due matrici inserisce nella seconda la trasposta della prima
void trasp_matx(int dim, double m[dim][dim], double trasp[dim][dim]);

//funzione che date due matrici e uno scalare mette nella seconda il prodotto della prima per lo scalare
void scalar_prod_matx(int dim, double k, double m[dim][dim], double prod_scal[dim][dim]);

//funzione che somma 2 matrici e mette il risultato in una terza
void sum_matx(int dim, double m1[dim][dim], double m2[dim][dim], double somma[dim][dim]);

//funzione che fa il prodotto riga x colonna di due matx di double e lo mette in una terza matrice
void prod_matx(int dim, double m1[dim][dim], double m2[dim][dim], double m[dim][dim]);

//funzione che date due matrici le scambia
void swap_matx(int dim, double m1[dim][dim], double m2[dim][dim]);

int main (void){

	int dim = dim_matx(); //dichiarazione dimensione
	int scelta = 0;
	double r; //dichiarazione sca
	int check_a = 0, check_b=0, check_r=0; //dichiarazione variabili di controllo dell'inserimento degli operandi

	double a[dim][dim]; //dichiarazione matrici
	double b[dim][dim];
	double risultato[dim][dim];

	do{
		print_menu();
		scanf("%d", &scelta);

		switch (scelta) {
			case 1:
				printf("\nInserimento matrice A...");
				write_matx(dim, a);
				check_a=1;
				break;
			case 2:
				printf("\nInserimento matrice B...");
				write_matx(dim, b);
				check_b=1;
				break;
			case 3:
				printf("\nInserimento dello scalare r...");
				scanf("%lf", &r);
				getchar();
				check_r=1;
				break;
			case 4:
				printf("\nVisualizzazione dei dati inseriti...");
				if(check_a){ //stampa A solo se è stata inserita
					printf("\nA = ");
					print_matx(dim, a);
				}
				if(check_b){ //stampa B solo se è stata inserita
					printf("\nB = ");
					print_matx(dim, b);
				}
				if(check_r) //stampa r solo se è stato inserito
					printf("\nr = %f", r);
				break;
			case 5:
				if(check_a){
					printf("\nLa trasposta di A e\':");
					trasp_matx(dim, a, risultato);
					print_matx(dim, risultato);
				}
				else
					printf("\nNon hai inserito A!");
				break;
			case 6:
				if(check_a&&check_r){
					printf("\nIl prodotto scalare tra A ed r e\':");
					scalar_prod_matx(dim, r, a, risultato);
					print_matx(dim, risultato);
				}
				else
					printf("\nNon hai inserito A o r!");
				break;
			case 7:
				if(check_a&&check_b){
					printf("\nLa somma tra A e B e\':");
					sum_matx(dim, a, b, risultato);
					print_matx(dim, risultato);
				}
				else
					printf("\nNon hai inserito A o B!");
				break;
			case 8:
				if(check_a&&check_b){
					printf("\nIl prodotto riga per colonna tra A e B e\':");
					prod_matx(dim, a, b, risultato);
					print_matx(dim, risultato);
				}
				else
					printf("\nNon hai inserito A o B!");
				break;
			case 9:
				if(check_a&&check_b){
					printf("\nScambio di A e B in corso...\nFatto!");
					swap_matx(dim, a, b);
				}
				else
					printf("\nNon hai inserito A o B!");
				break;
			case 10:
				return 0;
			default:
				break;
		}

	} while(1);

	return 0;
}

int dim_matx(void){
	int n;
	do{
		printf("\nInserisci la dimensione delle matrici quadrate: ");
		scanf("%d", &n);
		getchar();
	} while(n<1);
	return n;
}

void print_menu(){
	printf("\n\n\tMENU\'\t");
	printf("\n1. Inserisci operando A.\n2. Inserisci operando B.\n3. Inserisci operando scalare r.\n4. Visualizza A, B ed r.\n5. Trasposta di A.\n6. rA.\n7. A+B.\n8. AB.\n9. Scambia A e B.\n10. Esci.");
	printf("\n(A e B sono matrici reali, r è uno scalare reale)\n\nScegli un opzione: ");
}

void write_matx(int dim, double m[dim][dim]){

	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			printf("\nInserisci il valore nella riga %d e colonna %d: ", i, j);
			scanf("%lf",&m[i][j]);
			getchar();
		}
	}
}

void print_matx(int dim, double m[dim][dim]){

	for(int i=0; i<dim; i++){
		printf("\n|");
		for(int j=0; j<dim; j++){
			if(j)
				printf("\t");
			printf("%.3f",m[i][j]);
		}
		printf("|");
	}
}

void trasp_matx(int dim, double m[dim][dim], double trasp[dim][dim]){
	for(int i=0; i<dim; i++){ //scorro solo la triangolare superiore
		for(int j=i; j<dim; j++){
			trasp[i][j] = m[j][i];
			trasp[j][i] = m[i][j];
		}
	}
}

void scalar_prod_matx(int dim, double k, double m[dim][dim], double prod_scal[dim][dim]){
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			prod_scal[i][j] = m[i][j]*k;
		}
	}
}

void sum_matx(int dim, double m1[dim][dim], double m2[dim][dim], double somma[dim][dim]){
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			somma[i][j] = m1[i][j]+m2[i][j];
		}
	}
}

void prod_matx(int dim, double m1[dim][dim], double m2[dim][dim], double m[dim][dim]){
	for(int i=0; i<dim; i++){ //scorre le righe
		for(int j=0; j<dim; j++){ //scorre le colonne
			for(int k=0; k<dim; k++){ //per ogni cella della matrice prodotto i,j bisogna scorrere la riga i della matrice 1 e la colonna j della 2 per sommare e moltiplicare
				m[i][j]+=(m1[i][k]*m2[k][j]);
			}
		}
	}
}

void swap_matx(int dim, double m1[dim][dim], double m2[dim][dim]){
	double temp;
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			temp = m1[i][j];
			m1[i][j] = m2[i][j];
			m2[i][j] = temp;
		}
	}
}
