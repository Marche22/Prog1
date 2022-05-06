#include <stdio.h>

void delete_new_line(char* string);
int string_dim(char* string);
void reverse(char* string, char* reversed);

int main(void){

	/* BUFSIZ e' una costante definita in stdio.h */
	char str1[BUFSIZ], str2[BUFSIZ];

	printf("Inserisci una stringa: ");

	if(fgets(str1,BUFSIZ,stdin)==NULL){
		printf("Errore in lettura!\n");
		return -1;
	}

	delete_new_line(str1);

	reverse(str1, str2);
	//printf("\n%d", string_dim(str1));
	printf("\nLa stringa al contrario e':\n%s\n", str2);
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

void reverse(char* string, char* reversed){
	int dim = string_dim(string);
	for(int i=dim-1;i>=0;i--){
		*(reversed+dim-1-i)=*(string+i);
	}
	*(reversed+dim)='\0';
}
