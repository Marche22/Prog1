#include <stdio.h>

void delete_new_line(char* string);
int string_dim(char* string);
void reverse(char* string);

int main(int argc, char* argv[]){

	if (argc<2){
		printf("\nNon è stata inserita nessuna stringa");
		return -1;
	}

	printf("\nLa stringa al contrario e':\n");
	reverse(argv[1]);
	printf("\n");
	return 0;
}
//Davide Marchesi

int string_dim(char* string){
	int i=0;
	for(;(*(string+i))!='\0'; i++){}
	return i;
}

void reverse(char* string){
	int dim = string_dim(string);
	for(int i=dim-1;i>=0;i--)
		printf("%c",*(string+i));
}
