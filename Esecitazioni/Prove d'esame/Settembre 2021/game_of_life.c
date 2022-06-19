#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int DIM = 12;

void clean_string(char*);
void show(int**);
int extern_cell(int**, int, int);
int next_cell_state(int**, int, int);
void next_automa_state(int**);
int importa(FILE*, int**);
int esporta(FILE*, int**);
void run(int**, int);

int main(int argc, char* argv[]) {

    int** aut = malloc(sizeof(int*)*DIM); //anche se non strettamente necessario alloco la memoria per l'automa
    if(aut==NULL)
        return -1;
    for(int i=0; i<DIM; i++){
        aut[i] = malloc(sizeof(int)*DIM);
        if(aut[i]==NULL)
            return -1;
    }

    char string[BUFSIZ]; //la stringa che conterrà i nomi dei file
    FILE* file;

    int i;
    int choice; //scelta del menù dell'utente
    int n;
    int x = -1;
    int y = -1;

    do{
        sleep(1); //rallento la visualizzazione del menù per chiarezza in esecuzione
        printf("\n\n\tMENU'\n1. visualizzare la griglia di gioco;"
        "\n2. inserire una cella viva;"
        "\n3. passare al prossimo stato dell’automa;"
        "\n4. importa l'automa da un file esterno;"
        "\n5. esporta l'automa su un file esterno;"
        "\n6. l'automa avanza di n stati a tua scelta;"
        "\n7. uscire dal programma.\nInserisci il numero all'opzione corrispondente: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                show(aut);
                break;

            case 2:
                do{ //inserisce i valori finché non sono validi
                    printf("\nInserisci due valori 0-11 (separati da ',') per indicare le coordinate della cella che vuoi rendere viva: ");
                    scanf("%d,%d",&x,&y);
                } while(x<0 || x>11 || y<0 || y>11);

                if(aut[x][y]==0)
                    aut[x][y] = 1;
                else
                    printf("\nLa cella e\' gia\' viva.\n");
                break;

            case 3:
                printf("\nL'automa e\' passato allo stato successivo.\n");
                next_automa_state(aut);
                break;

            case 4:
                printf("\nInserisci il nome del file da cui importare l'automa: ");
                fgets(string, BUFSIZ, stdin); //prende il nome del file

                for(i=0; *(string+i)!='\0'; i++); //toglie lo \n dalla stringa per farlo leggere
                *(string+i-1) = '\0';

                if( (file = fopen(string,"r"))==NULL){ //prova ad aprirlo
                    printf("\nErrore apertura file\n");
                    break;
                }
                if(importa(file,aut)<(DIM*DIM)) //se ha importato meno di 12*12 valori c'è un problema
                    printf("\nPotrebbero essersi verificati errori nell'importazione.");
                else
                    printf("\nImport avvenuto con successo.");
                clean_string(string); //pulisce la stringa con un apposita funzione per poterla riutilizzare
                break;

            case 5:
                printf("\nInserisci il nome del file su cui esportare l'automa: ");
                fgets(string, BUFSIZ, stdin);

                for(i=0; *(string+i)!='\0'; i++); //toglie \n dal nome del file
                *(string+i-1) = '\0';

                if( (file = fopen(string,"w"))==NULL){
                    printf("\nErrore apertura file\n");
                    break;
                };
                if(esporta(file,aut)<(DIM*DIM)) //controlla che abbia esportato 12*12 valori
                    printf("\nPotrebbero essersi verificati errori nell'esportazione.");
                else
                    printf("\nScrittura avvenuta con successo.");
                clean_string(string); //pulisce la stringa con un apposita funzione per poterla riutilizzare
                break;

            case 6:
                do{ //chiede un numero valido di stati da far eseguire all'automa
                    printf("\nInserisci il numero di stati che vuoi far passare all'automa (n>=1): ");
                    scanf("%d",&n);
                    getchar();
                    if(n<=0)
                        printf("\nValore non valido...\n");
                } while(n<=0);
                run(aut, n);
                break;

            case 7:
                return 0;
                break;

            default :
                break;
        }
    } while(1);

    for(int i=0; i<DIM; i++) //dealloca tutto
        free(aut[i]);
    free(aut);

    return 0;
}

void clean_string(char* string){ //pulisce una stringa
    for(int i=0; i<BUFSIZ; i++)
        *(string+i) = '\0';
}

void show(int** aut){
    for(int i=0; i<DIM+2; i++){ //stampa l'automa come da richiesta
        printf("\n");
        for(int j=0; j<DIM; j++){
            if(i==0 || i==DIM+1)
                printf("-");
            else{
                if(aut[i-1][j]==0)
                    printf("\u2591");
                else
                    printf("\u2593");
            }
        }
    }
    printf("\n");
}

int extern_cell(int** aut, int x, int y){ //ritorna 0 se la cellula non è sul bordo, 1 se lo è e 2 se è negli angoli
    if(x!=0 && x!=11 && y!=0 && y!=11)
        return 0;
    if((x==0 && y==0)||(x==0 && y==11)||(x==11 && y==0)||(x==11 && y==11))
        return 2;
    return 1;
}

int next_cell_state(int** aut, int x, int y){
    int alive_cells = 0; //tiene conto delle cellule vive intorno alla mia cellula x
    int cell_position = extern_cell(aut,x,y); //mi aiuto con la funzione extern cell che mi dice in che posizione e\' la cella
    //aumento di uno il conto delle cellule vive per ognuna viva che trovo
    int i;
    if(cell_position==0){ //se è interna
        for(i=-1; i<2; i++){ //controllo le 3 adiacenti sopra
            if(aut[x-1][y+i]==1)
                alive_cells++;
        }
        for(i=-1; i<2; i++){ //controllo le 3 adicenti sotto
            if(aut[x+1][y+i]==1)
                alive_cells++;
        }
        if(aut[x][y-1]==1) //controllo quella a sx
            alive_cells++;
        if(aut[x][y+1]==1) //controllo quella a dx
            alive_cells++;
    }
    else if(cell_position==1){ //se è sul bordo ma non sugli angoli

        if(x==0){ //se è sul bordo alto
            for(i=-1; i<2; i++){ //controllo quelle adicenti sotto
                if(aut[x+1][y+i]==1)
                    alive_cells++;
            }
            if(aut[x][y+1]==1) //controllo quella a dx
                alive_cells++;
            if(aut[x][y-1]==1) //controllo quella a sx
                alive_cells++;
        }

        if(x==11){ //se è sul bordo basso
            for(i=-1; i<2; i++){ //controllo quelle adicenti sopra
                if(aut[x-1][y+i]==1)
                    alive_cells++;
            }
            if(aut[x][y+1]==1) //controllo quella a dx
                alive_cells++;
            if(aut[x][y-1]==1) //controllo quella a sx
                alive_cells++;
        }

        if(y==0){ //se è sul bordo a sx
            for(i=-1; i<2; i++){ //controllo quelle adicenti a dx
                if(aut[x+i][y+1]==1)
                    alive_cells++;
            }
            if(aut[x+1][y]==1)//controllo quella sotto
                alive_cells++;
            if(aut[x-1][y]==1)//controllo quella sopra
                alive_cells++;
        }

        if(y==11){//se è sul bordo a dx
            for(i=-1; i<2; i++){ //controllo quelle adicenti a sx
                if(aut[x+i][y-1]==1)
                    alive_cells++;
            }
            if(aut[x+1][y]==1)//controllo quella sotto
                alive_cells++;
            if(aut[x-1][y]==1)//controllo quella sopra
                alive_cells++;
        }
    }
    else{ //se è una dei 4 angoli controllo per ognuna le uniche 3 adiacenti
        if(x==0 && y==0){ //alto a sx
            if(aut[1][1]==1)
                alive_cells++;
            if(aut[1][0]==1)
                alive_cells++;
            if(aut[0][1]==1)
                alive_cells++;
        }
        if(x==0 && y==11){ //alto a dx
            if(aut[1][11]==1)
                alive_cells++;
            if(aut[0][10]==1)
                alive_cells++;
            if(aut[0][10]==1)
                alive_cells++;
        }
        if(x==11 && y==0){ //basso a sx
            if(aut[11][1]==1)
                alive_cells++;
            if(aut[10][0]==1)
                alive_cells++;
            if(aut[10][1]==1)
                alive_cells++;
        }
        if(x==11 && y==11){ //basso a dx
            if(aut[11][10]==1)
                alive_cells++;
            if(aut[10][10]==1)
                alive_cells++;
            if(aut[10][11]==1)
                alive_cells++;
        }
    }

    if(aut[x][y]==1){ //se la cellula è viva
        if(alive_cells<2 || alive_cells>3) //ma ha meno di 2 o più di 3 cell vive vicino allora muore
            return 0;
        else return 1; //altrimenti vive
    }
    else if(aut[x][y]==0 && alive_cells==3) //se e\' morta e ne ha 3 vive, diventa viva
            return 1;
}

void next_automa_state(int** aut){
    int new_aut[DIM][DIM]; //nuovo automa
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            new_aut[i][j] = next_cell_state(aut,i,j); //in ogni cellula dell'automa mette lo stato successivo di quella vecchia
        }
    }

    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            aut[i][j] = new_aut[i][j]; //copia l'automa nuovo in quello vecchio
        }
    }
}

int importa(FILE* file, int** aut){
    int counter = 0;
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if(fscanf(file,"%d",&aut[i][j])==1) //inserisce i valori del file nell'automa e aumenta di uno il contatore per ogni inserimento riuscito
                counter++;
        }
    }
    fclose(file);
    return counter;
}

int esporta(FILE* file, int** aut){
    int counter = 0;
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if(fprintf(file,"%d ",aut[i][j])==2)//stesso ragionamento di importa ma stavolta scrive su file, controlla che sia uguale a 2 perche\' conta sia il numero che lo spazio
                counter++;
        }
        fprintf(file,"\n");
    }
    fclose(file);
    return counter;
}

void run(int** aut, int n){
    for(int i=0; i<n; i++){ //per n volte fa progredire l'automa di 1 e lo mostra, poi aspetta un secondo per migliorare la visualizzazione
        printf("\n\t%d",i+1);
        next_automa_state(aut);
        show(aut);
        sleep(1);
    }
}
