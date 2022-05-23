#include <stdio.h>

int palindroma(char* string);

int main(void){

char str[BUFSIZ];

	printf("Inserisci una stringa: ");
	fgets(str,BUFSIZ,stdin);

	if(palindroma(str))
		printf("\nLa stringa e\' palindroma.\n");
	else
		printf("\nLa stringa NON e\' palindroma.\n");

}
//Davide Marchesi

int palindroma(char* string){
	int i=0;
	for(i=0; *(string+i)!='\n';i++);
	int dim = i;

	for(int i=0; i<dim/2; i++){
		if(*(string+i)!=*(string+dim-1-i))
			return 0;
	}
	return 1;
}
