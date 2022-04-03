/******************************************************************************

PRODOTTO RIGA PER COLONNA TRA DUE MATRICI

*******************************************************************************/
#include <stdio.h>

void clean_matx(int r, int c, float m[r][c]);	//riempie matx con zeri
void write_matx(int r, int c, float m[r][c]); //riempire matx
void print_matx(int r, int c, float m[r][c]); //stampare matx
void matx_prod(int r1,int c1, int r2, int c2, float m1[r1][c1], float m2[r2][c2], float m[r1][c2]); //prodotto riga x colonna di due matx

int main (void){
	int r1,c1,r2,c2,r,c;

	printf("\n\tCALCOLATORE PRODOTTO RIGHE X COLONNE TRA 2 MATRICI\n");

	printf("\nInserisci il numero di righe della prima matrice: ");
	scanf("%d",&r1);
	printf("\nInserisci il numero di colonne della prima matrice: ");
	scanf("%d",&c1);

	do{
		printf("\nInserisci il numero di righe della seconda matrice: ");
		scanf("%d",&r2);
		if(r2!=c1){
			printf("\nERRORE!\nIl numero di righe della seconda matrice deve essere uguale a quello delle colonne della prima!\nReinserisci...");
		}
	}
	while(r2!=c1);

	printf("\nInserisci il numero di colonne della seconda matrice: ");
	scanf("%d",&c2);

	r=r1;
	c=c2;

	float m1[r1][c1];
	float m2[r2][c2];
	float m[r][c];

	clean_matx(r1,c1,m1);
	clean_matx(r2,c2,m2);
	clean_matx(r,c,m);

	printf("\nRiempimento della prima matrice:");
	write_matx(r1,c1,m1);
	printf("\nRiempimento della seconda matrice:");
	write_matx(r2,c2,m2);

	printf("\nCalcolo in corso...\n");
	print_matx(r1,c1,m1);
	printf("\n\n\tX\n");
	print_matx(r2,c2,m2);
	printf("\n\n\t=\n");
	matx_prod(r1,r2,c1,c2,m1,m2,m);
	print_matx(r,c,m);
	printf("\n");

	return 0;
}

void clean_matx(int r, int c, float m[r][c]){

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			m[i][j]=0;
		}
	}
}

void write_matx(int r, int c, float m[r][c]){

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			printf("\nInserisci il valore nella riga %d e colonna %d: ", i+1, j+1);
			scanf("%f",&m[i][j]);
		}
	}
}

void print_matx(int r, int c, float m[r][c]){

	for(int i=0; i<r; i++){
		printf("\n|");
		for(int j=0; j<c; j++){
			if(j){
				printf("\t");
			}
			printf("%g",m[i][j]);
		}
		printf("|");
	}
}

void matx_prod(int r1,int c1, int r2, int c2, float m1[r1][c1], float m2[r2][c2], float m[r1][c2]){

	for(int i=0; i<r1; i++){
		for(int j=0; j<c2; j++){
			for(int k=0; k<r2; k++){
				m[i][j]+=(m1[i][k]*m2[k][j]);
			}
		}
	}
}
