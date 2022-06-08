#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char** f;
    int n;
}testo;

void mostra(testo*);
int carica(char*,testo**);
int aggiungi(testo**,char*);
int scrivisuf(char*,testo*);

int main(int argc, char *argv[]) {

    if(argc<2){
        printf("\nMancanza di argomenti, inserisci il nome di un file da riga di comando!\n");
        return -1;
    }

    int choice;
    testo* txt;

    switch (carica(argv[1],&txt)) {
        case -1:
            printf("\nErrore nell'apertura dei file \n");
            break;

        case -2:
            printf("\nL’intero n non è positivo, o la prima riga del file non contiene un intero.\n");
            break;

        case -3:
            printf("\nErrore nell’allocazione del testo.\n");
            break;

        case -4:
            printf("\nErrore nell’allocazione di una frase del testo.\n");
            break;

        case 0:
            do{
                do{
                    choice = 0,
                    printf("\n\tMENU\n1.\tMostra.\n2.\tAggiungi frase.\n3.\tScrivi su file.\n4.\tEsci.\n");
                    scanf("%d",&choice);
                    getchar();
                    if(choice<1 || choice>4)
                        printf("\nValore non valido, reinseriscine uno accettabile!\n");
                } while(choice<1 || choice>4);

                switch (choice) {

                    case 1:
                        mostra(txt);
                        break;

                    case 2:
                        printf("\nInserisci una frase da accodare al testo: ");
                        char string_to_add [BUFSIZ];
                        fgets(string_to_add, BUFSIZ, stdin);
                        if (aggiungi(&txt,string_to_add)<0){
                            printf("\nErrore nell'allocazione del testo\n");
                            break;
                        }
                        printf("\nFrase aggiunta correttamente.\n");
                        break;

                    case 3:
                        printf("\nInserisci il nome di un file su cui copiare il testo: ");
                        char file_name [BUFSIZ];
                        fgets(file_name, BUFSIZ, stdin);
                        if(scrivisuf(file_name,txt)){
                            printf("\nErrore nell'apertura del file.\n");
                            break;
                        }
                        printf("\nTesto copiato sul file.\n");
                        break;

                    case 4:
                        for(int i=0; i<txt->n; i++)
                            free(txt->f[i]);
                        free(txt->f);
                        free(txt);
                        return 0;
                        break;

                    default:
                        break;
                }
            } while(1);
                break;

        default:
            break;
    }

    return 0;
}

void mostra(testo *txt){
    for(int i=0; i<txt->n; i++){
        printf("%s",txt->f[i]);
    }
}

int carica(char* nf,testo** txt){
    FILE* file;
    if( (file = fopen(nf,"r") )==NULL){
        return -1;
    }
    int n_of_strings;
    if(fscanf(file,"%d",&n_of_strings)==EOF || n_of_strings<1){
        return -2;
    }

    getc(file);

    *txt = malloc(sizeof (testo) );
    if (txt==NULL)
        return -3;
    (*txt)->n = n_of_strings;
    (*txt)->f = malloc( (sizeof ( *((*txt)->f) ) )*n_of_strings);

    char aux[BUFSIZ];

    for(int i=0; i<n_of_strings; i++){
        for(int j=0; aux[j]!='\0';j++)
            aux[j] = '\0';
        fgets(aux,BUFSIZ,file);
        (*txt)->f[i] = malloc(strlen(aux));
        if (((*txt)->f[i])==NULL)
            return -4;
        strcpy((*txt)->f[i],aux);
    }
    fclose(file);
    return 0;
}

int aggiungi(testo** txt, char* s){;
    (*txt)->n++;
    char** temp = realloc((*txt)->f,(sizeof ( *((*txt)->f) ) )*( (*txt)->n) );
    if(temp==NULL)
        return -1;
    (*txt)->f = temp;
    (*txt)->f[((*txt)->n)-1] = malloc(strlen(s));
    if(( (*txt)->f[ ((*txt)->n) -1 ] )==NULL)
        return -2;
    strcpy((*txt)->f[((*txt)->n)-1],s);
    return 0;
}

int scrivisuf(char* nf,testo* txt){
    FILE* file_to_copy_on;
    if( (file_to_copy_on = fopen(nf,"w")) ==NULL)
        return -1;
    for(int i=0; i<(txt->n); i++)
        fprintf(file_to_copy_on, "%s", txt->f[i]);
    fclose(file_to_copy_on);
    return 0;
}
