#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const DIM = 3;

char mat[3][3];

int menu();
void gen_mat();
void read_mat();
void shift();
void rifletti();
void nega();
int speculare();

int main(void) {

    gen_mat();
    do{
        switch (menu()) {
            case 1:
                read_mat();
                break;
            case 2:
                shift();
                printf("\nShifting avvenuto con successo.\n");
                break;
            case 3:
                rifletti();
                printf("\nRiflessione avvenuta con successo.\n");
                break;
            case 4:
                nega();
                printf("\nNegazione avvenuta con successo.\n");
                break;
            case 5:
                if(speculare())
                    printf("\nLa matrice e\' speculare.\n");
                else
                    printf("\nNon e\' speculare.\n");
                break;
            case 6:
                return -1;
            default:
                break;
        }

    } while(1);

    return 0;
}

int menu(void){
    int choice;
    printf("\n\tMENU\'\n\n1. Mostra matrice\n2. Shift\n3. Riflessione\n4. Negazione\n5. Controlla se speculare\n6. Esci\n");
    do{
        scanf("%d",&choice);
        getchar();
    }while(choice<1 || choice>6);
    return choice;
}

void gen_mat(void){
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if((rand()%2)==0)
                mat[i][j]='+';
            else
                mat[i][j]='-';
        }
    }
}

void read_mat(void){
    for(int i=0; i<DIM; i++){
        printf("\n\t");
        for(int j=0; j<DIM; j++){
            printf("%c ",mat[i][j]);
        }
    }
    printf("\n");
}

void shift(void){
    for(int i=0; i<DIM; i++){
        char aux;
        aux = mat[i][0];
        mat[i][0] = mat[i][2];
        mat[i][2] = mat[i][1];
        mat[i][1] = aux;
    }
}

void rifletti(void){
    for(int i=0; i<DIM; i++){
        for(int j=i+1; j<DIM; j++){
            char aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
}

void nega(void){
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if(mat[i][j]=='+')
                mat[i][j]='-';
            else
                mat[i][j]='+';
        }
    }
}

int speculare(void){
    if(mat[0][1]==mat[1][0] && mat[0][2]==mat[2][0] && mat[2][1]==mat[1][2])
        return 1;
    return 0;
}
