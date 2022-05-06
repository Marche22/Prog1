#include <stdio.h>

void delete_new_line(char* string);
int string_dim(char* string);
void clean(char* string, char* cleaned, char character);

int main(void){

	char str1[BUFSIZ], str2[BUFSIZ];

	printf("Inserisci una stringa: ");

	if(fgets(str1,BUFSIZ,stdin)==NULL){
		printf("Errore in lettura!\n");
		return -1;
	}

	delete_new_line(str1);

	clean(str1, str2, '!');
	//printf("\n%d", string_dim(str1));
	printf("\nLa stringa senza spazi e':\n%s\n", str2);
}
//Davide Marchesi

void delete_new_line(char* string){
	int i=0;
	for (;string[i]!='\n';i++);
	string[i]='\0';
}

int string_dim(char* string){
	int i=0;
	for(;(*(string+i))!='\0'; i++){}
	return i;
}

void clean(char* string, char* cleaned, char character){
	int count_character = 0;
	int i;
	for(i=0; i<string_dim(string);i++){
		if(*(string+i)==character)
			count_character++;
		else
			(*(cleaned+i-count_character))=(*(string+i));
	}
	*(cleaned+i-count_character)='\0';
}
