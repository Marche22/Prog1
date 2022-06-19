#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int c; //coefficiente
    int x; //potenza di x
    int y; //potenza di y
    int z;  //...
    int w;
} term;

term read_term(void);
void write_term(term t);
int read_poly(term** poly);
void write_poly(int n, term* poly);
int term_like(term t1, term t2);
int simplify_poly(int* n, term** poly);
int sum_poly(int n1, int n2, term** p1, term** p2, term** p3);
term mult_term(term t1, term t2);
int mult_poly(int n1, int n2, term** p1, term** p2, term** p3);

int main(int argc, char* argv[]) {

    term* poly1;
    term* poly2;
    term* poly3;
    int n1;
    int n2;
    int n3;
    term t;

    do{
        printf("\nInserisci un comando: "
        "\n'T' per inserire e leggere un termine"
        "\n'S' per inserire e leggere un polinomio"
        "\n'+' per inserire e sommare due polinomi"
        "\n'*' per inserire e moltiplicare fra loro due polinomi"
        "\n'.' per terminare il programma\n");

        char comand = getchar(); // il comando che inserisce l'utente
        getchar();
        switch (comand) {

            case 'T':
                t = read_term();
                write_term(t);
                break;

            case 'S':
                n1 = read_poly(&poly1); //leggo il polinomio salvandone la dimensione
                write_poly(n1, poly1); //lo scrivo
                free(poly1); //libero la memoria allocata nella lettura del polinomio
                break;

            case '+':
                n1 = read_poly(&poly1); //leggo i due poli e alloco le rispettive memorie
                n2 = read_poly(&poly2);
                n3 = sum_poly(n1, n2, &poly1, &poly2, &poly3); //sommo i 2 poli nel terzo
                write_poly(n3, poly3); //lo scrivo
                printf("\n");

                free(poly1); //libero le memorie allocate
                free(poly2);
                free(poly3);
                break;

            case '*':
                n1 = read_poly(&poly1); //leggo i due poli e alloco le rispettive memorie
                n2 = read_poly(&poly2);
                n3 = mult_poly(n1, n2, &poly1, &poly2, &poly3); //moltiplico i 2 poli nel terzo
                write_poly(n3, poly3); //lo scrivo
                printf("\n");

                free(poly1); //libero le memorie allocate
                free(poly2);
                free(poly3);
                break;

            case '.':
                return 0;
                break;

            default :
                printf("\nComando non riconosciuto.\n\n");
                break;
        }
    } while(1);

    return 0;
}

term read_term(void){
    term t;
    scanf("%d",&t.c); //leggo il coefficente

    t.x = 0; //setto le potenze a 0 in modo che quelle non inserite dall'utente siano già apposto
    t.y = 0;
    t.z = 0;
    t.w = 0;

    for(int i=0; i<4; i++){
        getchar(); //"mangio" lo spazio tra C e V o tra i futuri P e V .
        char v = getchar(); //leggo V e in base a che variabile e' inserirò la potenza
        switch(v){
            case 'x':
                getchar(); //prima di inserire la potenza "mangio" lo spazio tra V e P
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
                i = 4; //se trova il punto manda l'indice che scorre il for a 4 cioè interrompe il for
                break;
            default:
                break;
        }
    }
    return t; //ritorno il termine.
}

void write_term(term t){
    if(t.c==0){ //se il termine ha coeff zero non legge nulla
        return;
    }
    if(t.x==0 && t.y==0 && t.z==0 && t.w==0){ //se tutte le potenze sono 0 legge il coefficiente
        printf("%d", t.c);
    }
    else{
        if(t.c!=1 && t.c!=-1) //se il coeff è 1 o -1 li legge come "" e "-"
            printf("%d",t.c);
        if(t.c==-1)
            printf("-");

        if(t.x==1) //per tutte le varibili legge solo la lettera se la potenza e' 1, non la legge se e' zero o la legge seguita dalla potenza
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
    scanf("%d", &n); //legge la dimensione dei termini del polinomio
    getchar(); //"mangia" l'invio
    *poly = calloc(n,sizeof(term)); //alloca la memoria adatta
    if(*poly == NULL) //controlla se l'allocazione e' riuscita
        return -1;
    for(int i=0; i<n; i++){ //legge i singoli termini 1 a 1.
        (*poly)[i] = read_term();
        getchar(); //mangia gli invii
    }
    return n; //ritorna il numero di termini
}

void write_poly(int n, term* poly){
    for(int i=0; i<n; i++){ //scorre il polinomio
        if(i!=0){
            if( (poly[i].c)>0 ){ //se il termine non e' il primo ed è positivo ci mette davanti '+'
                printf("+");
            }
        }
        write_term(poly[i]); //scrive il singolo termine
    }
}

int term_like(term t1, term t2){
    if(t1.x==t2.x && t1.y==t2.y && t1.w==t2.w && t1.z==t2.z) //se ogni potenza di ogni variabile è uguale i termini sono simili
        return 1;
    return 0;
}

int simplify_poly(int* n, term** poly){
    term* aux; //puntatore ausiliari
    for(int i=0; i<*n; i++){ //scorre il polinomio da sx
        for(int j=(*n)-1; j>i; j--){ //scorre il polinomio da dx arrivando fino al termine successivo a quello di i (ex se i è 2 scorre da n-1 fino a 3)
            if(term_like( (*poly)[i] , (*poly)[j]) ){ //se i termini sono simili
                (*poly)[i].c += (*poly)[j].c; //somma i coeff
                (*poly)[j].c = 0; //pone quello del secondo a zero
                if(j!=(*n)-1){ //se il termine indicizzato da j (quello azzerato dopo la somma) non e' l'ultimo lo scambia con l'ultimo
                    (*poly)[j] = (*poly)[(*n)-1];
                }
                *n = (*n)-1; //aggiorna la dimensione del polinomio togliendo 1
                aux = realloc(*poly,sizeof(term)*(*n)); //rialloca la memoria diminuendo di un termine, perde l'ultimo, ecco perché ho scambiato, per fargli perdere quello azzerato
                *poly = aux; //punto il polinomio alla nuova allocazione
            }
        }
    }
    return *n; //ritorno al nuova dimensione del poli
}

int sum_poly(int n1, int n2, term** p1, term** p2, term** p3){
    *p3 = calloc(n1+n2,sizeof(term)); //alloco un poli grande come la somma delle dimensioni dei 2 poli da sommare

    for(int i=0; i<n1+n2; i++){ //scorro questo poli somma
        if(i<n1) //metto i termini del primo nelle prime posizioni
            (*p3)[i] = (*p1)[i];
        else //metto quelli del secondo nelle posizioni rimaste
            (*p3)[i] = (*p2)[i-n1];
    }
    int n3 = n1+n2;
    return simplify_poly(&n3,p3); //semplifico in modo che la somma rimanga, notare che restituirà la dimensione del poli dopo la riallocazione con simplify
}

term mult_term(term t1, term t2){
    term t; //creo un termine e pongo il suo coeff come il prodotto dei due da moltiplicare e le potenze come somme di quelle dei due termini da molt
    t.c = t1.c*t2.c;
    t.x = t1.x+t2.x;
    t.y = t1.y+t2.y;
    t.w = t1.w+t2.w;
    t.z = t1.z+t2.z;
    return t; //ritorno quel termine
}

int mult_poly(int n1, int n2, term** p1, term** p2, term** p3){
    *p3 = calloc(n1*n2,sizeof(term)); //alloco un poli grande come il prodotto delle dimensioni dei 2 poli da moltiplicare
    int index = 0;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            (*p3)[index] = mult_term((*p1)[i],(*p2)[j]); //scorro i due poli e faccio il prodotto termine a termine salvando nel 3 poli
            index++;
        }
    }
    int n3 = n1*n2;
    return simplify_poly(&n3, p3); //semplifico eventuali termini simili e ritorno la nuova dimensione del poli semplificato (riallocaz)
}
