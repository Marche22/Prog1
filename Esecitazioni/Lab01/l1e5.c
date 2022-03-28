#include <stdio.h>
#include <limits.h>

int main(void){

	printf("CHAR_MIN=%d\n",CHAR_MIN);
	printf("CHAR_MAX=%d\n",CHAR_MAX);
	printf("INT_MIN=%d\n",INT_MIN);
	printf("INT_MAX=%d\n",INT_MAX);
	
	printf("\nPer i char abbiamo 7 bit per le cifre (2^7=128) e 1 per il segno, perciò 8.\n");
	printf("\nPe gli int abbiamo 15 bit per le cifre (2^15=32768) e 1 per il segno, perciò 16.\n");

	return 0;

}
//Davide Marchesi
