#include <stdio.h>

int menu(); //menù
int play_again(); //return 1 if user want to play again, otherwise 0
void clear_board(); //clean the board before every game start (putting inside -1)
void print_board(); //print the board but read -1 as ' ', 0 as 'O' and 1 as 'X'
void print_free_cells(); //print the cells identified by a number
int check_rows(); //check if in the rows someone won
int check_columns();  //check if in the columns someone won
int check_diagonals();  //check if in the diagonals someone won
int check_win();  //use the 3 functions before for checking if someone won
int valid_move(int cell); //check if the user is inserting the symbole in a valid cell
void pc_move(int difficulty); //computer does a move base on difficulty set
void player_move(int player); //let a player do a move
void play_match(int mode); //make a game start, run and end

int board[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};

int main (void){

    do{
        switch(menu()){
            case 0:
                return 0; //if player insert 0 in the menu the program finishes
            case 1:
                play_match(0);
                break;
            case 2:
                //play vs pc diff normal
                break;
            case 3:
                //play vs pc diff hard
                break;
            default:
                break;
            }
    }
    while(play_again());
    printf("\n");
    return 0;
}

int menu(){
    printf("\n\n\tTRIS\t\t\t\t(by Davide Marchesi)"); //Title
    int choice;
    do{
        printf("\n\nMake a choice by typing the respective number:\n0: Exit\n1: Play vs another user\n2: Play vs PC in normal mode\n3: Play vs PC in hard mode\n\n"); //options
        scanf("%d", &choice);
        getchar();
    }
    while(choice<0 || choice>3);
    return choice;
}

int play_again(){
    int rematch;
    do{
        printf("\n\nDo you want to play again or exit? Insert 1 for playing or 0 for closing the game.\n");
        scanf("%d", &rematch);
        getchar();
    }
    while(rematch!=0 && rematch!=1);
    return rematch;
}

void clear_board(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            board[i][j] = -1;
    }
}

void print_board(){
    char num_into_symbol;
    printf("\n\n—————————————");
    for(int i=0; i<3; i++){
        printf("\n|");
        for(int j=0; j<3; j++){ //board get numbers but is printed as letters -1=' ', 0='O', 1='X'
            if(board[i][j]<0)
                num_into_symbol = ' ';
            if(board[i][j]==0)
                num_into_symbol = 'O';
            if(board[i][j]>0)
                num_into_symbol = 'X';
            printf(" %c |", num_into_symbol);
        }
        printf("\n—————————————");
    }
    printf("\n\n");
}

void print_free_cells(){
    int cell_id = 0;
    printf("\n\n—————————————");
    for(int i=0; i<3; i++){
        printf("\n|");
        for(int j=0; j<3; j++){
            cell_id++;
            if(board[i][j]<0)
                printf(" %d |", cell_id);
            else{
                if(board[i][j]==0)
                    printf(" O |");
                if(board[i][j]>0)
                    printf(" X |");
            }
        }
        printf("\n—————————————");
    }
    printf("\n\n");
}

int check_rows(){
    for(int i=0; i<3; i++){
        if(board[i][0]!=-1 && board[i][1]==board[i][0] && board[i][2]==board[i][0])
            return 1;
    }
    return 0;
}

int check_columns(){
    for(int i=0; i<3; i++){
        if(board[0][i]!=-1 && board[0][i]==board[1][i] && board[0][i]==board[2][i])
            return 1;
    }
    return 0;
}

int check_diagonals(){
    if((board[0][0]!=-1 && board[0][0]==board[1][1] && board[0][0]==board[2][2])||
        (board[0][2]!=-1 && board[0][2]==board[1][1] && board[0][2]==board[2][0]))
        return 1;
    return 0;
}

int check_win(){
    if(check_diagonals()||check_rows()||check_columns()){
        printf("\n%d %d %d\n", check_diagonals(),check_rows(),check_columns());
        return 1;
    }
    return 0;
}

int valid_move(int cell){
    int cell_id = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cell_id++;
            if(cell==cell_id && board[i][j]==-1)
                return 1;
        }
    }
    return 0;
}

void pc_move(int difficulty);

void player_move(int player){
    print_free_cells();
    char symbol;
    int cell;
    if(!player)
        symbol = 'O';
    else
        symbol = 'X';
    do{
        cell = 0;
        printf("\nWhere do you want to insert %c? Insert the number corresponding to the cell: ", symbol);
        scanf("%d", &cell);
        getchar();
        if(!valid_move(cell))
            printf("\nInvalid cell!");
    }
    while(!valid_move(cell));

    int cell_id = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cell_id++;
            if (cell==cell_id)
                board[i][j] = player;
        }
    }
}

void play_match(int mode){
    if(!mode){ //mode=0 means playing vs other player
        int turn = 0, player;
        clear_board();
        do{
            printf("\nTURN %d", turn+1);
            if(turn%2==0)
                player_move(0);
            else
                player_move(1);

            print_board();
            turn++;
        }
        while(!check_win() && turn<9);

        if(check_win() && turn%2==0)
            printf("\nPlayer2 wins!");

        else if(check_win() && turn%2!=0)
            printf("\nPlayer1 wins!");

        else
            printf("\nDraw!");

    }
}
