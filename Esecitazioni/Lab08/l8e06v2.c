#include <stdio.h>

int string_dim(char* string);
void clean(char* string, char* characters);

int main(int argc, char* argv[]){

	char string[BUFSIZ];

	if(argc!=3){
		printf("Mancano argomenti!\n");
		return -1;
	}

	printf("\nLa stringa ripulita e':\t");
	clean(argv[1], argv[2]);
	printf("\n");

	return 0;
}
//Davide Marchesi

int string_dim(char* string){
	int i=0;
	for(;(*(string+i))!='\0'; i++){}
	return i;
}


void clean(char* string, char* characters){
	int found;
	for(int i=0; i<string_dim(string);i++){
		found = 0;
		for(int j=0; *(characters+j)!='\0'; j++){
			if(*(string+i)==(*(characters+j))){
				found = 1;
				break;
			}
		}
		if (!found)
			printf("%c",*(string+i));
	}
}
