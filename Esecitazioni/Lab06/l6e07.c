#include <stdio.h>

void delete_new_line(char* string);
int string_dim(char* string);
void clean(char* string, char* cleaned, char* characters);

int main(void){

	char str1[BUFSIZ], str2[BUFSIZ], chars[BUFSIZ];

	printf("Inserisci una stringa: ");

	if(fgets(str1,BUFSIZ,stdin)==NULL){
		printf("Errore in lettura!\n");
		return -1;
	}

	printf("Inserisci una stringa contenente tutti i caratteri  che vuoi eliminare dalla stringa: ");

	if(fgets(chars,BUFSIZ,stdin)==NULL){
		printf("Errore in lettura!\n");
		return -1;
	}

	delete_new_line(str1);
	delete_new_line(chars);

	clean(str1, str2, chars);
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
