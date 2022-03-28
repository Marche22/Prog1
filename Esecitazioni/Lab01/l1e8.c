#include <stdio.h>
#include <float.h>

int main(void){
	
	float num = FLT_MIN;
	printf("num = %g\n",num);
	
	num = FLT_MIN/FLT_MAX;
	printf("num = %g\nL'errore è causato dall'underflow!\n",num);
	
	return 0;
}
//Davide Marchesi
