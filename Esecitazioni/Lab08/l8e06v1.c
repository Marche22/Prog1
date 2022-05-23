#include <stdio.h>

int string_dim(char* string);
void clean(char* string, char* cleaned, char* characters);

int main(int argc, char* argv[]){

	char string[BUFSIZ];

	if(argc!3){
		printf("Mancano argomenti!\n");
		return -1;
	}

	clean(argv[1], string, argv[2]);
	printf("\nLa stringa ripulita e':\n%s\n", string);
	return 0;
}
//Davide Marchesi

int string_dim(char* string){
	int i=0;
	for(;(*(string+i))!='\0'; i++){}
	return i;
}


void clean(char* string, char* cleaned, char* characters){
	int count_characters = 0;
	int skip_pos = 0; //se è zero non succede nulla, se è 1 il ciclo for non copia il carattere di quel giro
	int i;
	for(i=0; i<string_dim(string);i++){
		skip_pos = 0;
		for(int k=0; k<string_dim(characters);k++){
			if(*(string+i)==(*(characters+k))){
				skip_pos++; //se trova uno dei caratteri da eliminare skip_pos va a 1 che permetterà di saltarlo nella copiatura
				count_characters++;
				break;
			}
		}
		if(!skip_pos) // se skip_pos è zero non deve saltare quel carattere quindi lo copia
			(*(cleaned+i-count_characters))=(*(string+i));
	}
	*(cleaned+i-count_characters)='\0';
}
