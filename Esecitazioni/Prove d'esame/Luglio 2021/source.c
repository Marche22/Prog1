#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int c;
    int x;
    int y;
    int z;
    int w;
} term;

term read_term(void);
void write_term(term t);
int read_poly(term** poly);
void write_poly(int n, term* poly);
int term_like(term t1, term t2);
int simplify_poly(int n, term** poly);
int sum_poly(int n1, int n2, term** p1, term** p2, term** p3);
term mult_term(term t1, term t2);
int mult_poly(int n1, int n2, term** p1, term** p2, term** p3);

int main(int argc, char* argv[]) {

    term* poly1;
    int n1 = read_poly(&poly1);
    write_poly(n1,poly1);
    printf("\n");
    term* poly2;
    int n2 = read_poly(&poly2);
    write_poly(n2,poly2);
    printf("\n");

    term* poly3;

    mult_poly(n1,n2,&poly1,&poly2,&poly3);
    write_poly(n1*n2, poly3);
    printf("\n");

    free(poly1);
    free(poly2);
    free(poly3);


    //printf("%d %d %d %d %d", t.c, t.x, t.y, t.z, t.w);

    return 0;
}

term read_term(void){
    term t;
    scanf("%d",&t.c);

    t.x = 0;
    t.y = 0;
    t.z = 0;
    t.w = 0;

    for(int i=0; i<4; i++){
        getchar();
        char v = getchar();
        switch(v){
            case 'x':
                getchar();
                scanf("%d",&t.x);
                break;
            case 'y':
                getchar();
                scanf("%d",&t.y);
                break;
            case 'z':
                getchar();
                scanf("%d",&t.z);
                break;
            case 'w':
                getchar();
                scanf("%d",&t.w);
                break;
            case '.':
                i = 4;
                break;
            default:
                break;
        }
    }
    return t;
}

void write_term(term t){
    if(t.c==0){
        return;
    }
    if(t.x==0 && t.y==0 && t.z==0 && t.w==0){
        printf("%d", t.c);
    }
    else{
        if(t.c!=1 && t.c!=-1)
            printf("%d",t.c);
        if(t.c==-1)
            printf("-");

        if(t.x==1)
            printf("x");
        if(t.x!=0 && t.x!=1)
            printf("x%d",t.x);

        if(t.y==1)
            printf("y");
        if(t.y!=0 && t.y!=1)
            printf("y%d",t.y);

        if(t.w==1)
            printf("w");
        if(t.w!=0 && t.w!=1)
            printf("w%d",t.w);

        if(t.z==1)
            printf("z");
        if(t.z!=0 && t.z!=1)
            printf("z%d",t.z);

    }
}

int read_poly(term** poly){
    int n = 0;
    scanf("%d", &n);
    getchar();
    *poly = calloc(n,sizeof(term));
    if(*poly == NULL)
        return -1;
    for(int i=0; i<n; i++){
        (*poly)[i] = read_term();
        getchar();
    }

    return n;
}

void write_poly(int n, term* poly){
    for(int i=0; i<n; i++){
        if(i!=0){
            if( (poly[i].c)>0 ){
                printf("+");
            }
        }
        write_term(poly[i]);
    }
}

int term_like(term t1, term t2){
    if(t1.x==t2.x && t1.y==t2.y && t1.w==t2.w && t1.z==t2.z)
        return 1;
    return 0;
}

int simplify_poly(int n, term** poly){
    int counter = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(term_like( (*poly)[i] , (*poly)[j]) ){
                (*poly)[i].c += (*poly)[j].c;
                (*poly)[j].c = 0;
                counter++;
            }
        }
    }
    return counter;
}


int sum_poly(int n1, int n2, term** p1, term** p2, term** p3){
    *p3 = calloc(n1+n2,sizeof(term));

    for(int i=0; i<n1+n2; i++){
        if(i<n1)
            (*p3)[i] = (*p1)[i];
        else
            (*p3)[i] = (*p2)[i-n1];
    }

    return simplify_poly(n1+n2,p3);

}

term mult_term(term t1, term t2){
    term t;
    t.c = t1.c*t2.c;
    t.x = t1.x+t2.x;
    t.y = t1.y+t2.y;
    t.w = t1.w+t2.w;
    t.z = t1.z+t2.z;
    return t;
}

int mult_poly(int n1, int n2, term** p1, term** p2, term** p3){
    *p3 = calloc(n1*n2,sizeof(term));
    int index = 0;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            (*p3)[index] = mult_term((*p1)[i],(*p2)[j]);
            index++;
        }
    }

    return simplify_poly(n1*n2, p3);
}
