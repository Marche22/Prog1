#include <stdio.h>
#include <limits.h>


int main(void){

	int num = INT_MAX;
	printf("num = %d\n",num);

	num = num+1;
	printf("num = %d\n",num);
	printf("Il problema è dato dal fatto che stiamo superando il valore massimo di un int.\n");


	return 0;
}
//Davide Marchesi
