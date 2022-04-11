//Davide Marchesi
#include <stdio.h>

int dim_matx(void); //funzione che chiede all'utente di inserire la dimensione di una matrice quadrata
void print_matx(int dim, double m[dim][dim]); //funzione che stampa una matrice di double
void write_matx(int dim, double m[dim][dim]); //funzione che permette di inserire i numeri in una matrice di double

int main(void){

	int n = dim_matx(); //inserimento dimensione della matrice

	double matx1[n][n]; //dichiarazione matrici
	double matx2[n][n];
	double matx_somma[n][n];

	printf("\nRiempimento prima matrice: \n");
	write_matx(n, matx1); //riempimento matrice 1
	printf("\nRiempimento seconda matrice: \n");
	write_matx(n, matx2); //riempimento matrice 2

	for(int i=0; i<n; i++){ //riempimento matrice somma
		for(int j=0; j<n; j++){
			matx_somma[i][j] = matx1[i][j] + matx2[i][j];
		}
	}

	print_matx(n, matx1); //stampa matrice 1
	printf("\n\t+\t\n"); //		+
	print_matx(n, matx2); //stampa matrice 2
	printf("\n\t=\t\n");// 		=
	print_matx(n, matx_somma); //stampa matrice somma

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
