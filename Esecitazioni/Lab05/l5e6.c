#include <stdio.h>

int main(void){

	int* pi;
	double* pd;
	char* pc;

	int ai[]={0,1};
	double ad[]={0.1,0.2};
	char ac[]="pippo";

	pi = &ai[0];
	pd = &ad[0];
	pc = &ac[0];

	printf("\npi = %p, pi punta a %d\npd = %p, pd punta a %f\npc = %p, pc punta a \'%c\'\n", pi, *pi, pd, *pd, pc, *pc);
	pi++;
	pd++;
	pc++;
	printf("\npi = %p, pi punta a %d\npd = %p, pd punta a %f\npc = %p, pc punta a \'%c\'\n", pi, *pi, pd, *pd, pc, *pc);

	printf("\n");
	return 0;
}
//Davide Marchesi
