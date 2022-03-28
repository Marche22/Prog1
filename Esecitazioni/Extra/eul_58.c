#include <stdio.h>

void print_matx(int r, int c, int m[r][c]);
void clean_matx(int r, int c, int m[r][c]);
void spiral(int n, int d, int m[d][d]);

int main (void){
	int d = 19;
	int m[d][d];

	clean_matx(d,d,m);
	spiral(3,d,m);
	print_matx(d,d,m);
	printf("\n");

	return 0;
}

void clean_matx(int r, int c, int m[r][c]){

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			m[i][j]=0;
		}
	}
}

void print_matx(int r, int c, int m[r][c]){

	for(int i=0; i<r; i++){
		printf("\n|");
		for(int j=0; j<c; j++){
			if(j){
				printf(" ");
			}
			printf("%d",m[i][j]);
		}
		printf("|");
	}
}

void spiral(int n, int d, int m[d][d]){
	int p = d/2;
	m[p][p]=1;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){

				}
			}
		}
	}
}
