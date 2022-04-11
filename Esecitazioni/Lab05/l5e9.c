//Davide Marchesi
#include <stdio.h>

int dim_matx(void); //funzione che chiede all'utente di inserire la dimensione di una matrice quadrata
void print_matx(int dim, double m[dim][dim]); //funzione che stampa una matrice di double
void write_matx(int dim, double m[dim][dim]); //funzione che permette di inserire i numeri in una matrice di double

int main(void){

	int n = dim_matx(); //inserimento dimensione della matrice
	double k; //dichiarazione scalare
	double matx[n][n]; //dichiarazione matrice

	write_matx(n, matx); //riempimento matrice

	printf("\nInserirsci uno scalare reale: ");
	scanf("%lf", &k);
	getchar();

	printf("\n\t%f *\t\n", k); //	 k*
	print_matx(n, matx); //stampa matrice inserita

	for(int i=0; i<n; i++){ //moltiplicazione matrice
		for(int j=0; j<n; j++){
			matx[i][j] *= k;
		}
	}

	printf("\n\t=\t\n");// 		=
	print_matx(n, matx); //stampa matrice prodotto

	printf("\n");
	return 0;
}

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
