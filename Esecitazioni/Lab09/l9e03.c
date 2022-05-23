#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x;
    double y;
} Vett;

int linind(Vett*, Vett*);

int main(int argc, char* argv[]) {

    if(argc<5){
        printf("\nErrore: mancano argomenti.\n");
        return -1;
    }

    Vett v1, v2;

    v1.x = atof(argv[1]);
    v1.y = atof(argv[2]);
    v2.x = atof(argv[3]);
    v2.y = atof(argv[4]);

    if(linind(&v1,&v2))
        printf("\nI due vettori sono linearmente indipendenti.\n");
    else
        printf("\nI due vettori sono linearmente dipendenti.\n");

    return 0;
}

int linind(Vett* v1, Vett* v2){
    if ( ( ( ((*v1).x) * ((*v2).y) ) - ( ((*v2).x)*((*v1).y) ) )==0) //sfrutto il fatto che se metto i vettori per formare una matx il det è zero SSE i vett sono dip
        return 0;
    return 1;
}
