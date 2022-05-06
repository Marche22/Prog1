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
	for (;string[i]!='\n';i++);/
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
	int dim = string_dim(string);
	if(dim%2==0){
		char first_half[(dim/2)+1];
		first_half[dim/2] = '\0';
		for(int i=0; i<(dim/2);i++)
			*(first_half+i) = *(string+i);
		char* second_half = string+(dim/2);
		char reversed_second_half[(dim/2)+1];
		reverse(second_half,reversed_second_half);
		reversed_second_half[dim/2] = '\0';
		if(equals(reversed_second_half,first_half))
			return 1;
		else
			return 0;
	}
	else{
		char no_central_letter [dim];
		no_central_letter[dim-1] = '\0';
		for(int i=0; i<=dim; i++){
			if(i<dim/2)
				*(no_central_letter+i)=*(string+i);
			if(i>dim/2 && i!=dim)
				*(no_central_letter+i-1)=*(string+i);
		}
		return(palindroma(no_central_letter));
	}
}
