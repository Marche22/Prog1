#include <stdio.h>

//funzione che chiede all'utente di inserire la dimensione di una matrice quadrata
int dim_matx(void);

//funzione che permette di inserire i numeri in una matrice di double
void write_matx(int dim, double m[dim][dim]);

//funzione che stampa una matrice di double
void print_matx(int dim, double m[dim][dim]);

//funzione che fa il prodotto riga x colonna di due matx di double e lo mette in una terza matrice
void prod_matx(int dim, double m1[dim][dim], double m2[dim][dim], double m[dim][dim]);

int main (void){

	int dim = dim_matx(); //dichiarazione dimensione
	int m;
	double matx[dim][dim]; //matrice da moltiplicare
	double aux[dim][dim]; //matrice ausiliaria che verrà inizializzata come identità
	double temp[dim][dim]; //matrice ausiliaria

	printf("\nCaricamento della matrice: ");
	write_matx(dim, matx);
	do{
		printf("\nScegli l'esponente per cui elevare la matrice: ");
		scanf("%d", &m);
		getchar();
	} while(m<0);

	for(int i=0; i<dim; i++){ //inizializzo aux come l'identità
		for(int j=0; j<dim; j++){
			if(i==j)
				aux[i][j]=1;
			else
				aux[i][j]=0;
		}
	}

	printf("\nLa matrice");
	print_matx(dim, matx);
	printf("\nelevata alla %d e\' la matrice:\n", m);

	for(int k=1; k<=m; k++){
		prod_matx(dim, aux, matx, temp);

		for(int i=0; i<dim; i++){
			for(int j=0; j<dim; j++){
				aux[i][j] = temp [i][j]; //aux = temp per il prossimo ciclo di k
				temp[i][j] = 0; //pulisco temp
			}
		}
	}
	print_matx(dim, aux);

	printf("\n");
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
