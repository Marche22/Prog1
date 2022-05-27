#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double EPSILON = 1.0e-6;

typedef struct{
    char label;
    double x;
    double y;
} Point;

typedef struct{
    Point* a;
    Point* b;
    double length;
} Segment;

void clean_string(char*);
void string_to_point(char*,Point*);
double distance(Point*, Point*);
void def_segment_from_points(Point*, Point*, Segment*);
int check_parallel_to_axis(Segment*);
int check_different_quarter(Segment*);
int check_above_limit(Segment*, double);
void print_segment(Segment*);

int main(int argc, char* argv[]) {

    if (argc<2){
        printf("\nErrore! Mancanza di argomenti!\n");
        return -1;
    }

    double limit = atof(argv[1]);
    int number_of_points = -1;
    char strings_of_points[50][BUFSIZ];
    do{
        number_of_points++;
        printf("\nInserisci un punto o chiudi il flusso:\n");
    } while(fgets(strings_of_points[number_of_points],BUFSIZ,stdin)!=NULL);

    Point points[number_of_points];
    int number_of_segments = 0;


    for(int i=0; i<number_of_points; i++){
        string_to_point(strings_of_points[i],&points[i]);
        number_of_segments +=i;
    }

    Segment segments[number_of_segments];
    int index = 0;

    for(int i=0; i<number_of_points-1; i++){
        for(int j=i+1; j<number_of_points; j++){
            def_segment_from_points(&points[i],&points[j],&segments[index]);
            index++;
        }
    }

    for(int i=0; i<number_of_segments; i++){
        if(!(check_parallel_to_axis(&segments[i])) && (check_different_quarter(&segments[i])) && (check_above_limit(&segments[i],limit)))
            print_segment(&segments[i]);
    }

    printf("\n");
    return 0;
}

void clean_string(char* s){
    for(int i=0;i<BUFSIZ;i++)
        *(s+i)='\0';
}

void string_to_point(char* string, Point* p){
    p->label = *string;
    int i = 2;
    char aux[2][BUFSIZ];
    for(int j=0; j<2; j++){
        int index = 0;
        clean_string(aux[j]);
        do{
            aux[j][index] = *(string+i);
            index++;
            i++;
        } while(*(string+i)!=';' && *(string+i)!='\n');
        i++;
    }
    p->x = atof(aux[0]);
    p->y = atof(aux[1]);
}

double distance(Point* p, Point* q){
    return pow(pow((p->x)-(q->x),2)+pow((p->y)-(q->y),2),0.5);
}

void def_segment_from_points(Point* p, Point* q, Segment* s){
    s->a = p;
    s->b = q;
    s->length = distance(p,q);
}

int check_parallel_to_axis(Segment* s){
    if (s->a->x==s->b->x || s->a->y==s->b->y)
        return 1;
    return 0;
}

int check_different_quarter(Segment* s){
    if ((s->a->x)*(s->a->y)*(s->b->x)*(s->b->y)<=0)
        return 1;
    if ((s->a->x)*(s->b->x)<0)
        return 1;
    return 0;
}

int check_above_limit(Segment* s, double limit){
    if (((s->length)+EPSILON)>limit)
        return 1;
    return 0;
}

void print_segment(Segment* s){
    printf("\nSegmento con estremi %c = (%.3f, %.3f) e %c = (%.3f, %.3f).", s->a->label, s->a->x, s->a->y, s->b->label, s->b->x, s->b->y);
}
