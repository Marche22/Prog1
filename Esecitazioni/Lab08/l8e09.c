#include <stdio.h>

void delete_new_line(char* string);
int string_dim(char* string);
void switch_strings(char* s1, char* s2);
int lex(char *s, char *t);
void ordina(char **s, int lung);

int main(int argc, char* argv[]) {

    char array[5][BUFSIZ];
    char* strings[5];

    for(int i=0; i<5; i++){
        printf("\nInserisci una stringa: ");
        fgets(array[i],BUFSIZ,stdin);
        delete_new_line(array[i]);
        strings[i] = array[i];
    }

    ordina(strings, 5);

    printf("\nOrdinamento avvenuto con successo:\n");
    for(int k=0;k<5;k++)
        printf("\n%s",strings[k]);

    printf("\n");
    return 0;
}

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

void switch_strings(char* s1, char* s2){
    char aux[BUFSIZ];

    int i = 0;
    for(;*(s1+i)!='\0';i++)
        *(aux+i)=(*(s1+i));
    *(aux+i) = '\0';

    for(i = 0;*(s2+i)!='\0';i++)
        *(s1+i)=(*(s2+i));
    *(s1+i) = '\0';

    for(i = 0;*(aux+i)!='\0';i++)
        *(s2+i)=(*(aux+i));
    *(s2+i) = '\0';
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

void ordina(char **s, int lung){
    int scambio = 1;
    while(scambio){
        scambio = 0;
        for(int i=0; i<lung-1; i++){
            if(lex(s[i],s[i+1])==-1){
                switch_strings(s[i],s[i+1]);
                scambio = 1;
            }
        }
    }
}
