#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
} Vett;

typedef struct{
    Vett v1;
    Vett v2;
    Vett v3;
} Tri;

double dist(Vett*, Vett*);
double area(Tri*);
void rot_Vett(Vett*, double);
void rot_Tri(Tri*, double);

int main(void) {

    Tri t;
    double angle;

    printf("\nInserisci le coordinate del primo vertice del triangolo separate da uno spazio: ");
    scanf("%lf %lf",&t.v1.x,&t.v1.y);
    getchar();
    printf("\nInserisci le coordinate del secondo vertice del triangolo separate da uno spazio: ");
    scanf("%lf %lf",&t.v2.x,&t.v2.y);
    getchar();
    printf("\nInserisci le coordinate del terzo vertice del triangolo separate da uno spazio: ");
    scanf("%lf %lf",&t.v3.x,&t.v3.y);
    getchar();
    printf("\nInserisci l'angolo di rotazione in radianti: ");
    scanf("%lf",&angle);
    getchar();

    printf("\nL'area del rettangolo e\': %.3f.\n", area(&t));
    printf("\nRotazione in corso...\n");

    rot_Tri(&t, angle);
    printf("\nOra l'area del rettangolo e\': %.3f.\n", area(&t));

    return 0;
}

double dist(Vett* v1, Vett* v2){
    return pow((pow(v1->x-v2->x,2)+pow(v1->y-v2->y,2)),0.5);
}

double area(Tri* t){
    double l1 = dist(&t->v1,&t->v2);
    double l2 = dist(&t->v2,&t->v3);
    double l3 = dist(&t->v1,&t->v3);
    double semip = (l1+l2+l3)*0.5;
    return pow(semip*(semip-l1)*(semip-l2)*(semip-l3),0.5);
}

void rot_Vett(Vett* v, double a){
    double coseno = cos(a);
    double seno = sin(a);
    double x = coseno*(v->x)-seno*(v->y);
    double y = coseno*(v->y)+seno*(v->x);
    v->x = x;
    v->y = y;
}

void rot_Tri(Tri* t, double a){
    rot_Vett(&t->v1,a);
    rot_Vett(&t->v2,a);
    rot_Vett(&t->v3,a);
}
