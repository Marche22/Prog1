#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int** G;
int* n;
int* r;
int* c;

void clear_board();
void show();
int game_over();
int mossa();
int leggi_mossa();
int scrivi(int, int);

int main(int argc, char* argv[]) {

    srand(time(NULL));

    if (argc<3){
        printf("\nMancanza di argomenti.\n");
        return -1;
    }
    if (atoi(argv[1])<2 || atoi(argv[2])<2 || atoi(argv[3])<2){
        printf("\nLa dimensione della griglia di gioco o il numero di pedine da allineare non e\' un valore valido.\n");
        return -2;
    }

    n = malloc(sizeof(int));
    r = malloc(sizeof(int));
    c = malloc(sizeof(int));
    *n = atoi(argv[1]);
    *r = atoi(argv[2]);
    *c = atoi(argv[3]);

    G = malloc((*r) * sizeof(int*));
    if(G==NULL){
        printf("\nErrore nell'allocazione della griglia.\n");
        return -3;
    }
    for(int i=0; i<*r; i++){
        G[i] = malloc((*c) * sizeof(int));
        if(G[i]==NULL){
            printf("\nErrore nell'allocazione delle colonne di gioco.\n");
            return -4;
        }
    }

    clear_board();
    show();

    int turn = 0;
    do{
        int j;
        do{
            if(turn%2){ //se è il turno del pc
                j = mossa();
            }
            else{ //se è il turno del giocatore
                do{
                    j = leggi_mossa();
                    if(j==-1)
                        printf("\nColonna non valida, reinserisci.");
                } while(j==-1);
            }
        } while(!scrivi(turn,j-1));
        show();
        turn++;


    } while(game_over()<0);

    switch (game_over()){
        case 0:
            printf("\nPartita finita: patta.\n");
            break;
        case 1:
            printf("\nPartita finita: ha vinto il giocatore.\n");
            break;
        case 2:
            printf("\nPartita finita: ha vinto il computer.\n");
            break;
        default:
            break;
    }

    for(int i=0; i<*r; i++)
        free(G[i]);
    free(G);
    free(n);
    free(r);
    free(c);
    return 0;
}

void clear_board(){
    for(int i=0; i<*r; i++){
        for(int j=0; j<*c; j++){
            G[i][j] = 0;
        }
    }
}

void show(){
    for(int i=0; i<*r; i++){
        printf("\n|");
        for(int j=0; j<*c; j++){
            if(G[i][j]==0)
                printf(" ");
            if(G[i][j]==1)
                printf("+");
            if(G[i][j]==2)
                    printf("*");
            printf("|");
        }
    }
    printf("\n");
}

int game_over(){
    for(int turn = 1; turn<=2; turn++){

        for(int i= ((*r)-1) ; i>=0; i--){ //controllo vittoria per riga
            for(int j=0; j<( (*c)-(*n)+1 ); j++){
                if(G[i][j]==turn){
                    for(int k=1; k<*n; k++){
                        if( G[i][j+k] != turn)
                            break;
                        else if(k == ( (*n)-1) )
                            return turn;
                    }
                }
            }
        }

        for(int i=0 ; i<(*c); i++){ //controllo vittoria per colonna
            for(int j=((*r)-1); j>=((*n)-1 ); j--){
                if(G[j][i]==turn){
                    for(int k=1; k<*n; k++){
                        if( G[j-k][i] != turn)
                            break;
                        else if(k == ( (*n)-1) )
                            return turn;
                    }
                }
            }
        }
    }

    for(int i=0; i<*r; i++){ //controllo se ci sono celle vuote cioè se la partita è in corso
        for(int j=0; j<*c; j++){
            if(G[i][j]==0)
                return -1;
        }
    }

    return 0;
}

int leggi_mossa(){
    int j;
    printf("\nInserisci la colonna in cui vuoi inserire la pedina: (1,...,%d)\n",*c);
    scanf("%d", &j);
    getchar();
    if(j>0 && j<=(*c))
        return j;
    return -1;
}

int scrivi(int gioc, int j){
    for(int i=(*r)-1; i>=0; i--){
        if(G[i][j]==0){
            G[i][j] = gioc%2+1;
            return 1;
        }
    }
    return 0;
}

int mossa(){
    return (rand()%(*c))+1;
}
