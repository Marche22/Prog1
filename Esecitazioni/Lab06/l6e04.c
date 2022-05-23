#include <stdio.h>

void delete_new_line(char* string);
int string_dim(char* string);
int lex(char *s, char *t);

int main(void){

	/* BUFSIZ e' una costante definita in stdio.h */
	char str1[BUFSIZ], str2[BUFSIZ];

	printf("Inserisci una stringa: ");
	if(fgets(str1,BUFSIZ,stdin)==NULL){
		printf("Errore in lettura!\n");
		return -1;
	}
	printf("Inserisci un'altra stringa: ");
	if(fgets(str2,BUFSIZ,stdin)==NULL){
		printf("Errore in lettura!\n");
		return -1;
	}

	delete_new_line(str1);
	delete_new_line(str2);

	printf("%d",lex(str1,str2));

	if(lex(str1,str2))
		printf("\nLa prima stringa precede la seconda nell'ordinamento lessicografico.");
	else if(lex(str1,str2)<0)
		printf("\nLa seconda stringa precede la prima nell'ordinamento lessicografico.");
	else
		printf("\nLe due stringhe sono uguali");


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

int lex(char *s, char *t){
	int dim = string_dim(s);
	int equal = 0;
	if (dim>string_dim(t))
		dim = string_dim(t);
	else if (dim==string_dim(t))
		equal = 1;

	for(int i=0; i<dim; i++){
		if(((int) *(s+i)) < ((int) *(t+i)))
			return 1;
		if(((int) *(s+i)) > ((int) *(t+i)))
			return -1;
	}
	if(equal==1)
		return 0;
	if(string_dim(s)>string_dim(t))
		return -1;
	else
		return 1;
}
