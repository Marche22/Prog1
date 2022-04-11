#include <stdio.h>

int main(void){

	char s1[] = "Galileo Galilei";
	char s2[] = "Leonardo da Vinci";
	char s_aux[1024];
	char* p1 = s1;
	char* p2 = s2;
	char* p_aux = s_aux;


	printf("\np1 punta alla stringa che contiene \"%s\", p2 punta alla stringa che contiene \"%s\".", p1, p2);

	p_aux = p1;
	p1 = p2;
	p2 = p_aux;

	printf("\np1 punta alla stringa che contiene \"%s\", p2 punta alla stringa che contiene \"%s\".", p1, p2);

	printf("\n");
	return 0;
}
//Davide Marchesi
