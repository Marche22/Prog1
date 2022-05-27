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
void rot_Vett(Vett*, double);
void rot_Tri(Tri*, double);
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
    char lines [number_of_tri][BUFSIZ]; //array di stringhe dove metterò le varie righe di testo del file
    char aux[BUFSIZ]; //stringa ausiliria
    double coordinates[6]; //array dove metto le coordinate un triangolo alla volta
    int counter = 0; //counter per aiutarmi a salvare i numeri
    int index = 0; //indice della coordinata

    for(int i=0; i<number_of_tri; i++){ //scorro il file di testo riga per riga
        fgets(lines[i], BUFSIZ, file_pointer); //salvo la riga
        clean_string(aux); //pulisco la stringa ausiliaria
        clean_double_array(coordinates); //pulisco le coordinate
        int index = 0; //setto l'indice delle coordinate a zero
        for(int j=0; j<BUFSIZ; j++){ //scorro la riga del file appena salvata
            if(*(lines[i]+j)!=' ' && *(lines[i]+j)!='\0'){ //se il carattere non è spazio o \0
                *(aux+counter) = (*(lines[i]+j)); //salvo il carattere nella stringa aux
                counter++;
            }
            else{ //altrimenti al primo spazio o alla fine della riga
                coordinates[index] = atof(aux); //converto la stringa ausiliaria (che contiene il numero che ho appena salvato) e lo mette nelll'array delle coordinate
                counter = 0; //resetto il counter perché dovrò salvare la prossima coordinata
                index++; //aumento l'indice delle coordinate
                clean_string(aux); //pulisco la stringa ausiliaria
                if(index>5){ //quando arrivo alla fine dell'array delle coordinate ho finito
                    break;
                }
            }
        }
        t[i].v1.x = coordinates[0]; //salvo le coordinate dall'array al triangolo
        t[i].v1.y = coordinates[1];
        t[i].v2.x = coordinates[2];
        t[i].v2.y = coordinates[3];
        t[i].v3.x = coordinates[4];
        t[i].v3.y = coordinates[5];
    }

    fclose(file_pointer);

    int counter_degeneri = 0;
    double aree[number_of_tri];
    for(int i=0; i<number_of_tri; i++){
        if(degenere(&t[i])) //se il triangolo è degenere aumento il counter
            counter_degeneri++;
        aree[i] = area(&t[i]); //calcolo tutte le aree e le metto in un array apposito
    }

    double area_minore = 0;
    int index_minore = 0;
    double media_aree;
    for(int i=0; i<number_of_tri; i++){
        media_aree += aree[i]; //sommo tutte le aree
        if( (aree[i]<area_minore && aree[i]!=0) || (area_minore==0) ){ //se l'area che sto considerando non è zero ed è minore dell'area minore finora essa diventa quella minore
            area_minore = aree[i];
            index_minore = i; //qua salvo l'indice dell'area minore
        }
    }
    media_aree = media_aree/number_of_tri;

    printf("\nCi sono %d triangoli, di cui %d degeneri.\nLa media delle aree e\': %.3f.\nL'area più piccola e\' quella del triangolo di indice %d.\n", number_of_tri, counter_degeneri, media_aree, index_minore);
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

void clean_string(char* string){
    for(int i=0; i<BUFSIZ; i++)
        *(string+i)='\0';
}

void clean_double_array(double* coordinates){
    for(int i=0; i<6; i++)
        *(coordinates+i)=0;
}
