#include <stdio.h>

void delete_new_line(char* string);
int string_dim(char* string);
int equals(char* string1, char* string2);

int main(void){

	/* BUFSIZ e' una costante definita in stdio.h */
	char str1[BUFSIZ], str2[BUFSIZ];

	printf("Inserisci la prima stringa: ");
	fgets(str1,BUFSIZ,stdin);
	printf("Inserisci la seconda stringa: ");
	fgets(str2,BUFSIZ,stdin);

	delete_new_line(str1);
	delete_new_line(str2);

	if(equals(str1, str2))
		printf("\nLe stringhe sono uguali.\n");
	else
		printf("\nLe stringhe NON sono uguali.\n");
}
//Davide Marchesi

void delete_new_line(char* string){
	int i=0;
	for (;string[i]!='\n';i++);
	string[i]='\0';
}

int string_dim(char* string){
	int i=0;
	for(;(*(string+i))!='\0'; i++);
	return i;
}

int equals(char* string1, char* string2){
	int dim = string_dim(string1);

	if(dim!=string_dim(string2))
		return 0;
	else{
		for(int i=0; i<dim; i++){
			if((*(string1+i))!=(*(string2+i))){
				return 0;
			}
		}
		return 1;
	}
}
