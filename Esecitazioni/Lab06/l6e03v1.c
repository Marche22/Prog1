#include <stdio.h>

void delete_new_line(char* string);
int string_dim(char* string);
void reverse(char* string, char* reversed);
int equals(char* string1, char* string2);
int palindroma(char* string);

int main(void){

	char str[BUFSIZ];

	printf("Inserisci una stringa: ");
	fgets(str,BUFSIZ,stdin);

	delete_new_line(str);

	if(palindroma(str))
		printf("\nLa stringa e\' palindroma.\n");
	else
		printf("\nLa stringa NON e\' palindroma.\n");
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

void reverse(char* string, char* reversed){
	int dim = string_dim(string);
	for(int i=dim-1;i>=0;i--){
		*(reversed+dim-1-i)=*(string+i);
	}
	*(reversed+dim)='\0';
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

int palindroma(char* string){
	char reversed[BUFSIZ];
	reverse(string,reversed);
	return(equals(string,reversed));
}
