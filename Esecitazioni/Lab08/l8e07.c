#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* days_it[7] = {"lunedi","martedi","mercoledi","giovedi","venerdi","sabato","domenica"};
char* days_en[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int indice(char*);

int main(int argc, char* argv[]) {
    if(argc<2){
        printf("\nERRORE! Manca l'argomento.\n");
        return -1;
    }
    int index = indice(argv[1]);
    if(index<0){
        printf("\nERRORE! Non e\' stato inserito un giorno della settimana.\n");
        return -1;
    }

    printf("\nIn inglese il giorno della settimana inserito e\': %s\n", days_en[index]);
    return 0;
}

int indice(char* giorno){
    int i = 0;
    for(; *(giorno+i)!='\0';i++)
        *(giorno+i)=tolower(*(giorno+i));
    for(i=0;i<7;i++){
        if(!(strcmp(giorno,days_it[i])))
            return i;
    }
    return -1;
}
