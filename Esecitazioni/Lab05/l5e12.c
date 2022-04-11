#include <stdio.h>

//funzione che chiede all'utente di inserire la dimensione di una matrice quadrata
int dim_matx(void);

//funzione che permette di inserire i numeri in una matrice di double
void write_matx(int dim, double m[dim][dim]);

//funzione che stampa una matrice di double
void print_matx(int dim, double m[dim][dim]);

//funzione che pulisce una matrice riempiendola di zeri
void clean_matx(int dim, double m[dim][dim]);

//funzione che trasforma una matrice nella sua trasposta
void trasp_matx(int dim, double m[dim][dim]);

//funzione che date due matrici e uno scalare mette nella seconda il prodotto della prima per lo scalare
void scalar_prod_matx(int dim, double k, double m[dim][dim], double prod_scal[dim][dim]);

//funzione che somma 2 matrici e mette il risultato in una terza
void sum_matx(int dim, double m1[dim][dim], double m2[dim][dim], double somma[dim][dim]);

//funzione che fa il prodotto riga x colonna di due matx di double e lo mette in una terza matrice
void prod_matx(int dim, double m1[dim][dim], double m2[dim][dim], double m[dim][dim]);


int main (void){

	int dim = dim_matx(); //dichiarazione dimensione
	double r; //dichiarazione scalare

	double a[dim][dim]; //dichiarazione matrici
	double b[dim][dim];
	double c[dim][dim];
	double aux1[dim][dim]; //matrici ausiliarie per salvare i risultati intermedi
	double aux2[dim][dim];

	printf("\nCaricamento della matrice A...");
	write_matx(dim, a);
	printf("\nCaricamento della matrice B...");
	write_matx(dim, b);
	printf("\nCaricamento della matrice C...");
	write_matx(dim, c);
	printf("\nInserisci uno scalare reale r: ");
	scanf("%lf", &r);
	getchar();

	//identità 1
	printf("\n\nIdentita\' 1: A(B+C)=AB+AC\n\nA(B+C) ="); //primo membro
	clean_matx(dim, aux1); //pulisco le due matrici ausiliare per sicurezza
	clean_matx(dim, aux2);
	sum_matx(dim, b, c, aux1); //aux1=b+c
	prod_matx(dim, a, aux1, aux2);//aux2=a*aux1
	print_matx(dim, aux2);
	//secondo membro
	printf("\n\nAB+AC =");
	clean_matx(dim, aux1); //pulisco le due matrici ausiliare per sicurezza
	clean_matx(dim, aux2);
	prod_matx(dim, a, b, aux1); //aux1=a*b
	prod_matx(dim, a, c, aux2); //aux2=a*c
	sum_matx(dim, aux1, aux2, c); //uso c come risultato perché tanto non mi servirà più
	print_matx(dim, c);

	//identità 2
	printf("\n\n\nIdentita\' 2: r(AB)=(rA)B\n\nr(AB) =");//primo membro
	clean_matx(dim, aux1); //pulisco le due matrici ausiliare per sicurezza
	clean_matx(dim, aux2);
	prod_matx(dim, a, b, aux1); //aux1=a*b
	scalar_prod_matx(dim, r, aux1, aux2); //aux2=r*aux1
	print_matx(dim, aux2);
	//secondo membro
	printf("\n\n(rA)B =");
	clean_matx(dim, aux1); //pulisco le due matrici ausiliare per sicurezza
	clean_matx(dim, aux2);
	scalar_prod_matx(dim, r, a, aux1); //aux1 = r*a
	prod_matx(dim, aux1, b, aux2); //aux2 = aux1*b
	print_matx(dim, aux2);

	//identità 3
	printf("\n\n\nIdentita\' 3: (AB)trasposta=(Btrasposta)(Atrasposta)\n\n(AB)trasposta ="); //primo membro
	clean_matx(dim, aux1); //pulisco le due matrici ausiliare per sicurezza
	clean_matx(dim, aux2);
	prod_matx(dim, a, b, aux1); //aux1 = a*b
	trasp_matx(dim, aux1); //aux1= trasposta di a*b
	print_matx(dim, aux1);
	//secondo membro
	printf("\n\n(Btrasposta)(Atrasposta) =");
	clean_matx(dim, aux1); //pulisco le due matrici ausiliare per sicurezza
	clean_matx(dim, aux2);
	trasp_matx(dim, b); //b = b trasposta
	trasp_matx(dim, a); //a = a trasposta
	prod_matx(dim, b, a, aux1); //aux1 = a*b
	print_matx(dim, aux1);

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

void clean_matx(int dim, double m[dim][dim]){
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			m[i][j] = 0;
		}
	}
}

void trasp_matx(int dim, double m[dim][dim]){
	double temp;
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
