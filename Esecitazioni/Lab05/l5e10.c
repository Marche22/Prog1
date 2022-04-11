//Davide Marchesi
#include <stdio.h>

int dim_matx(void); //funzione che chiede all'utente di inserire la dimensione di una matrice quadrata
void write_matx(int dim, double m[dim][dim]); //funzione che permette di inserire i numeri in una matrice di double
void print_matx(int dim, double m[dim][dim]); //funzione che stampa una matrice di double
void prod_matx(int dim, double m1[dim][dim], double m2[dim][dim], double m[dim][dim]); //funzione che fa il prodotto riga x colonna di due matx di double

int main (void){

	int n = dim_matx(); //dichiarazione dimensione

	double matx1[n][n]; //dichiarazione matrici
	double matx2[n][n];
	double matx_prod[n][n];

	printf("\nRiempimento della prima matrice:"); //riempimento prima matrice
	write_matx(n,matx1);
	printf("\nRiempimento della seconda matrice:"); //riempimento seconda matrice
	write_matx(n,matx2);

	printf("\nCalcolo in corso...\n");
	print_matx(n,matx1); //stampa matrice 1
	printf("\n\n\tX\n");
	print_matx(n,matx2); // stampa matrice 2
	printf("\n\n\t=\n");
	prod_matx(n,matx1,matx2,matx_prod); //prodotto riga x colonna
	print_matx(n,matx_prod); //stampa matrice prodotto
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

void prod_matx(int dim, double m1[dim][dim], double m2[dim][dim], double m[dim][dim]){

	for(int i=0; i<dim; i++){ //scorre le righe
		for(int j=0; j<dim; j++){ //scorre le colonne
			for(int k=0; k<dim; k++){ //per ogni cella della matrice prodotto i,j bisogna scorrere la riga i della matrice 1 e la colonna j della 2 per sommare e moltiplicare
				m[i][j]+=(m1[i][k]*m2[k][j]);
			}
		}
	}
}
