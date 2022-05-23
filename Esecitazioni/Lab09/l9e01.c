#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;
} Vett;

double dist(Vett,Vett);

int main(void) {

    Vett v1, v2;

    printf("\nInserisci le coordinate del primo vettore separate da uno spazio: ");
    scanf("%lf %lf",&v1.x,&v1.y);
    getchar();
    printf("\nInserisci le coordinate del secondo vettore separate da uno spazio: ");
    scanf("%lf %lf",&v2.x,&v2.y);
    getchar();

    printf("\n\nLa distanza dei due vettori e\': %.3f\n", dist(v1,v2));

    return 0;
}

double dist(Vett v1, Vett v2){
    return pow((pow(v1.x-v2.x,2)+pow(v1.y-v2.y,2)),0.5);
}
