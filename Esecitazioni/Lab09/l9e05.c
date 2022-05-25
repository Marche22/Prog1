#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x;
    double y;
} Vett;

typedef struct{
    Vett v1;
    Vett v2;
    Vett v3;
} Tri;

int linind(Vett*, Vett*);
Vett sott(Vett, Vett);
int affind(Vett*, Vett*, Vett*);
int degenere(Tri *);

int main(void) {

    Tri t;

    printf("\nInserisci le coordinate del primo vertice del triangolo separate da uno spazio: ");
    scanf("%lf %lf",&t.v1.x,&t.v1.y);
    getchar();
    printf("\nInserisci le coordinate del secondo vertice del triangolo separate da uno spazio: ");
    scanf("%lf %lf",&t.v2.x,&t.v2.y);
    getchar();
    printf("\nInserisci le coordinate del terzo vertice del triangolo separate da uno spazio: ");
    scanf("%lf %lf",&t.v3.x,&t.v3.y);
    getchar();

    if(degenere(&t))
        printf("\nIl triangolo e\' degenere.\n");
    else
        printf("\nIl triangolo non e\' degenere.\n");

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

int degenere(Tri* t){
    if(!affind(&t->v1,&t->v2,&t->v3))
        return 1;
    return 0;

}
