#include <stdio.h>
#include <math.h>

int main(void){

	double a, b, c, d, x1, x2;
	
	printf("\n\tRISOLUTORE DI EQUAZIONI DI SECONDO GRADO\n");
	
	do{
		printf("\nInserisci il coefficiente del termine di secondo grado (diverso da zero): ");
		scanf("%lf",&a);
	}
	while(!a);
	
	printf("\nInserisci il coefficiente del termine di primo grado: ");
	scanf("%lf",&b);
	printf("\nInserisci il coefficiente del termine noto: ");
	scanf("%lf",&c);
	
	d=(b*b)-(4*a*c);
	printf("\nIl determinante dell'equazione è: %f",d);
	
	if(d>0){
		x1 = (-b+(sqrt(d)))/(2*a);
		x2 = (-b-(sqrt(d)))/(2*a);
		printf("\nEsistono due soluzioni distinte: x1=%f e x2=%f", x1, x2);
	}
	
	else if(d==0){
		x1 = (-b)/(2*a);
		printf("\nEsistono due soluzioni coincidenti: x1=x2=%f",x1);
	}
	
	else{
		printf("\nNon esistono soluzioni in R.");
	}
	
	printf("\n");
	return 0;
}
//Davide Marchesi
