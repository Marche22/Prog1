#include <stdio.h>
#define DIM 9

void print_board(int board[DIM][DIM]);
int valid_row(int board[DIM][DIM], int row, int n);
int valid_column(int board[DIM][DIM], int column, int n);
int valid_box(int board[DIM][DIM], int row, int column, int n);

int main(void){

    int board[DIM][DIM] = {
        {0,8,0,0,7,2,0,0,0},
        {0,0,0,3,8,0,2,6,0},
        {0,2,9,0,0,0,3,0,8},
        {0,1,0,0,0,0,6,0,0},
        {0,5,0,2,0,8,0,1,4},
        {0,0,7,0,1,0,8,9,0},
        {0,0,0,8,9,3,1,5,7},
        {0,0,0,1,0,0,0,0,0},
        {5,0,1,7,0,0,0,0,0}
    };

    print_board(board);
    printf("\n%d", valid_row(board, 0, 8));
    printf("\n%d", valid_column(board, 0, 8));
    printf("\n%d", valid_box(board, 7, 7, 7));

    return 0;
}

void print_board(int board[DIM][DIM]){
    for(int i=0; i<DIM; i++){ //rows
        if(!i){
            for(int k=0; k<(DIM*4+1); k++){
                printf("-");
            }
        printf("\n");
        }
        for(int j=0; j<DIM; j++){ //columns
            if(!j)
                printf("|");
            printf(" %d |",board[i][j]);
        }
        printf("\n");
        for(int k=0; k<(DIM*4+1); k++){ //--- finale
            printf("-");
        }
        printf("\n");
    }
}

int valid_row(int board[DIM][DIM], int row, int n){
    int valid = 1;
    for(int i=0; i<DIM; i++){
        if(board[row][i]==n){
            valid = 0;
            break;
        }
    }
    return valid;
}

int valid_column(int board[DIM][DIM], int column, int n){
    int valid = 1;
    for(int i=0; i<DIM; i++){
        if(board[i][column]==n){
            valid = 0;
            break;
        }
    }
    return valid;
}

int valid_box(int board[DIM][DIM], int row, int column, int n){
    int valid = 1;
    for(int i=row-(row%3); i<(row-(row%3)+3); i++){
        for(int j=column-(column%3); j<(column-(column%3)+3); j++){
            if(board[i][j]==n){
                valid = 0;
                break;
            }
        }
    }
    return valid;
}
