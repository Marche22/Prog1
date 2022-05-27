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

int linind(Vett*, Vett*);
Vett sott(Vett, Vett);
int affind(Vett*, Vett*, Vett*);
int degenere(Tri *);
double dist(Vett*, Vett*);
double area(Tri*);
void clean_string(char*);
void clean_double_array(double*);

int main(int argc, char *argv[]) {
    if(argc<2){
        printf("\nErrore, mancanza di argomenti!\n");
        return -1;
    }


    FILE* file_pointer = fopen(argv[1], "r");

    if(file_pointer==NULL){
        printf("\nErrore, impossibile aprire il file inserito!\n");
        return -1;
    }

    char first_line[BUFSIZ]; //salvo la prima riga del file
    fgets(first_line, BUFSIZ, file_pointer);
    int number_of_tri = atoi(first_line); //la rendo un intero

    Tri t [number_of_tri];
    int i;

    for(i=0; i<number_of_tri; i++){
        fscanf(file_pointer,"%lf",&t[i].v1.x);
        fscanf(file_pointer,"%lf",&t[i].v1.y);
        fscanf(file_pointer,"%lf",&t[i].v2.x);
        fscanf(file_pointer,"%lf",&t[i].v2.y);
        fscanf(file_pointer,"%lf",&t[i].v3.x);
        fscanf(file_pointer,"%lf",&t[i].v3.y);
    }

    fclose(file_pointer);

    int counter_degeneri = 0;
    double aree[number_of_tri];
    for(i=0; i<number_of_tri; i++){
        if(degenere(&t[i])) //se il triangolo è degenere aumento il counter
            counter_degeneri++;
        aree[i] = area(&t[i]); //calcolo tutte le aree e le metto in un array apposito
    }

    double area_minore = 0;
    int index_minore = 0;
    double media_aree;
    for(i=0; i<number_of_tri; i++){
        media_aree += aree[i]; //sommo tutte le aree
        if( (aree[i]<area_minore && aree[i]!=0) || (area_minore==0) ){ //se l'area che sto considerando non è zero ed è minore dell'area minore finora essa diventa quella minore
            area_minore = aree[i];
            index_minore = i; //qua salvo l'indice dell'area minore
        }
    }
    media_aree = media_aree/number_of_tri;

    printf("\nCi sono %d triangoli, di cui %d degeneri.\nLa media delle aree e\': %.3f.\nL'area più piccola e\' quella del triangolo di indice %d.\n", number_of_tri, counter_degeneri, media_aree, index_minore);

    int indici[number_of_tri];
    for(i=0; i<number_of_tri; i++)
        indici[i] = i;

    int swap = 1;
    double temp_d;
    int temp_i;
    while(swap){ //uso un bubble sort per ordinaree le aree e contemporaneamente cambio anche gli indici dei triangoli su un array parallelo
        swap = 0;
        for(i=0; i<number_of_tri-1; i++){
            if(aree[i]>aree[i+1]){
                temp_d = aree[i]; //scambio aree
                aree[i] = aree[i+1];
                aree[i+1] = temp_d;
                temp_i = indici[i]; //scambio indici
                indici[i] = indici[i+1];
                indici[i+1] = temp_i;
                swap = 1;
            }
        }
    }

    printf("\nI triangoli in ordine di superficie crescente sono:\n");
    for(int i=0; i<number_of_tri; i++)
        printf("Il triangolo di indice %d e area %.3f\n", indici[i], aree[i]);

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

void clean_string(char* string){
    for(int i=0; i<BUFSIZ; i++)
        *(string+i)='\0';
}

void clean_double_array(double* coordinates){
    for(int i=0; i<6; i++)
        *(coordinates+i)=0;
}
