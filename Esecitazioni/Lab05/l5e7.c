//Davide Marchesi
#include <stdio.h>

int dim_matx(void); //funzione che chiede all'utente di inserire la dimensione di una matrice quadrata
void print_matx(int dim, double m[dim][dim]); //funzione che stampa una matrice di double
void write_matx(int dim, double m[dim][dim]); //funzione che permette di inserire i numeri in una matrice di double
void trasposta(int dim, double m[dim][dim]); //funzione che data una matrice la trasforma nella sua trasposta

int main(void){

	int n = dim_matx(); //inserimento dimensione della matrice

	double matx[n][n]; //dichiarazione matrice

	write_matx(n, matx); //riempimento matrice
	print_matx(n, matx); //stampa matrice inserita
	trasposta(n, matx); //trasformazione in trasposta
	print_matx(n, matx); //stampa matrice trasformata

	printf("\n");
	return 0;
}
//Davide Marchesi

int dim_matx(void){
	int n;
	do{
		printf("\nInserisci la dimensione della matrice quadrata: ");
		scanf("%d", &n);
		getchar();
	} while(n<1);
	return n;
}

void print_matx(int dim, double m[dim][dim]){
	for (int i=0; i<dim; i++){
		printf("\n");
		for (int j=0; j<dim; j++){
			printf(" %f ", m[i][j]);
		}
	}
	printf("\n");
}

void write_matx(int dim, double m[dim][dim]){
	for (int i=0; i<dim; i++){
		for (int j=0; j<dim; j++){
			printf("\nInserisci il valore della cella di indice %d %d : ", i, j);
			scanf("%lf", &m[i][j]);
			getchar();
		}
	}
}

void trasposta(int dim, double m[dim][dim]){
 	double temp; //variabile temporanea per lo scambio
	for (int i=0; i<dim; i++){
		for (int j=i; j<dim; j++){ //mi basta scorrere la triangolare superiore per scambiare
			if(i!=j){
				temp = m[i][j];
				m[i][j] = m[j][i];
				m[j][i] = temp;
			}
		}
	}
}
