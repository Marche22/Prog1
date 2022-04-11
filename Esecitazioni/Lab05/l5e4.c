#include <stdio.h>

int main(void){

	int a, b, ausiliario;
	int* px = &a;
	int* py = &b;
	int* paux = &ausiliario;

	*px = 0;
	*py = 1;

	printf("\npx punta ha una cella che contiene %d, py punta ha una cella che contiene %d", *px, *py);

	*paux = *px;
	*px = *py;
	*py = *paux;

	printf("\npx punta ha una cella che contiene %d, py punta ha una cella che contiene %d", *px, *py);

	printf("\n");
	return 0;
}
//Davide Marchesi
