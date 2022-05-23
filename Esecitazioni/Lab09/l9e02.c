#include <stdio.h>

typedef struct{
    double x;
    double y;
} Vett;

Vett somma(Vett,Vett);
Vett invadd(Vett);
Vett sott(Vett,Vett);
Vett pscal(Vett, double);
double pint(Vett,Vett);

int main(void) {

    Vett v1, v2;
    double scalar;

    printf("\nInserisci le coordinate del primo vettore separate da uno spazio: ");
    scanf("%lf %lf",&v1.x,&v1.y);
    getchar();
    printf("\nInserisci le coordinate del secondo vettore separate da uno spazio: ");
    scanf("%lf %lf",&v2.x,&v2.y);
    getchar();
    printf("\nInserisci uno scalare: ");
    scanf("%lf", &scalar);
    getchar();

    printf("\n\nIl vettore somma tra i due vettori e\': (%.3f  %.3f)\n", somma(v1,v2).x, somma(v1,v2).y);
    printf("\n\nGli inversi additivi dei due vettori sono rispettivamente: (%.3f  %.3f) e (%.3f  %.3f)\n", invadd(v1).x, invadd(v1).y,invadd(v2).x, invadd(v2).y);
    printf("\n\nIl vettore differenza tra i due vettori e\': (%.3f  %.3f)\n", sott(v1,v2).x, sott(v1,v2).y);
    printf("\n\nI vettori prodotto tra i singoli vettori e lo scalare sono rispettivamente: (%.3f  %.3f) e (%.3f  %.3f)\n", pscal(v1,scalar).x, pscal(v1,scalar).y, pscal(v2,scalar).x, pscal(v2,scalar).y);
    printf("\n\nIl prodotto interno e\': %.3f\n", pint(v1,v2));

    return 0;
}

Vett somma(Vett v1, Vett v2){
    Vett somma;
    somma.x = v1.x+v2.x;
    somma.y = v1.y+v2.y;
    return somma;
}

Vett invadd(Vett v){
    Vett inv;
    inv.x = -v.x;
    inv.y = -v.y;
    return inv;
}

Vett sott(Vett v1, Vett v2){
    Vett diff;
    diff.x = v1.x-v2.x;
    diff.y = v1.y-v2.y;
    return diff;
}

Vett pscal(Vett v, double k){
    Vett prod;
    prod.x = k*v.x;
    prod.y = k*v.y;
    return prod;
}

double pint(Vett v1, Vett v2){
    return (v1.x*v2.x)+(v1.y*v2.y);
}
