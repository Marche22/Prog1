#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x;
    double y;
} Vett;

int linind(Vett*, Vett*);
Vett sott(Vett, Vett);
int affind(Vett*, Vett*, Vett*);

int main(int argc, char* argv[]) {

    if(argc<7){
        printf("\nErrore: mancano argomenti.\n");
        return -1;
    }

    Vett v1, v2, v3;

    v1.x = atof(argv[1]);
    v1.y = atof(argv[2]);
    v2.x = atof(argv[3]);
    v2.y = atof(argv[4]);
    v3.x = atof(argv[5]);
    v3.y = atof(argv[6]);

    if(affind(&v1,&v2,&v3))
        printf("\nI tre vettori sono affinemente indipendenti.\n");
    else
        printf("\nI tre vettori sono affinemente dipendenti.\n");

    return 0;
}

Vett sott(Vett v1, Vett v2){
    Vett diff;
    diff.x = v1.x-v2.x;
    diff.y = v1.y-v2.y;
    return diff;
}

int linind(Vett* v1, Vett* v2){
    if ( ( ( ((*v1).x) * ((*v2).y) ) - ( ((*v2).x)*((*v1).y) ) )==0) //sfrutto il fatto che se metto i vettori per formare una matx il det è zero SSE i vett sono dip
        return 0;
    return 1;
}

int affind(Vett* v1, Vett* v2, Vett* v3){
    Vett diff1;
    Vett diff2;
    diff1 = sott(*v2,*v1);
    diff2 = sott(*v3,*v1);
    if(linind(&diff1,&diff2))
        return 1;
    return 0;
}
