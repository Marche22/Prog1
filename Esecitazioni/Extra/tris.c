#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int menu(); //menù
void set_names(); //make possibile to insert names in player vs player mode
int play_again(); //return 1 if user want to play again, otherwise 0
void clear_board(); //clean the board before every game start (putting inside -1)
void print_board(); //print the board but read -1 as ' ', 0 as 'O' and 1 as 'X'
void print_free_cells(); //print the cells identified by a number
int check_rows(); //check if in the rows someone won
int check_columns();  //check if in the columns someone won
int check_diagonals();  //check if in the diagonals someone won
int check_win();  //use the 3 functions before for checking if someone won
int valid_move(int cell); //check if the user is inserting the symbole in a valid cell
int opponent_win_angle(int player); //given a player check if the other one can win in the next turn and return the cell for winning, otherwise ret 0
void pc_move(int difficulty, int player); //computer does a move base on difficulty set
void player_move(int player); //let a player do a move
void play_match(int mode); //make a game start, run and end

int board[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
char player1_name [BUFSIZ];
char player2_name [BUFSIZ];

int main (void){

    srand(time(NULL));

    do{
        switch(menu()){
            case 0:
                return 0; //if player insert 0 in the menu the program finishes
            case 1:
                play_match(0);
                break;
            case 2:
                play_match(1);
                break;
            case 3:
                play_match(2);
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

void set_names(){
    printf("\nChoose a name for player1: ");
    fgets(player1_name, BUFSIZ, stdin);
    printf("\nChoose a name for player2: ");
    fgets(player2_name, BUFSIZ, stdin);
    int i=0;
    for(;*(player1_name+i)!='\n';i++);
    *(player1_name+i)='\0';
    i = 0;
    for(;*(player2_name+i)!='\n';i++);
    *(player2_name+i)='\0';
}
int play_again(){
    int rematch;
    sleep(2);
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
    printf("\n\n\t—————————————");
    for(int i=0; i<3; i++){
        printf("\n\t|");
        for(int j=0; j<3; j++){ //board get numbers but is printed as letters -1=' ', 0='O', 1='X'
            if(board[i][j]<0)
                num_into_symbol = ' ';
            if(board[i][j]==0)
                num_into_symbol = 'O';
            if(board[i][j]>0)
                num_into_symbol = 'X';
            printf(" %c |", num_into_symbol);
        }
        printf("\n\t—————————————");
    }
    printf("\n\n");
}

void print_free_cells(){
    int cell_id = 0;
    printf("\n\n\t—————————————");
    for(int i=0; i<3; i++){
        printf("\n\t|");
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
        printf("\n\t—————————————");
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
    if(check_diagonals()||check_rows()||check_columns())
        return 1;
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

int opponent_win_angle(int player){
    int opponent;
    if (player==0)
        opponent = 1;
    else
        opponent = 0;

    for(int i=0; i<3; i++){ //check win on rows
        if(board[i][0]==opponent){
            if(board[i][1]==opponent && board[i][2]!=player)
                return (i+1)*3;
            if(board[i][2]==opponent && board[i][1]!=player)
                return ((i+1)*3)-1;
        }
        else if (board[i][1]==opponent && board[i][2]==opponent && board[i][0]!=player)
            return (i*3)+1;
    }

    for(int i=0; i<3; i++){ //check win on columns
        if(board[0][i]==opponent){
            if(board[1][i]==opponent && board[2][i]!=player)
                return 7+i;
            if(board[2][i]==opponent && board[1][i]!=player)
                return 4+i;
        }
        else if (board[1][i]==opponent && board[2][i]==opponent && board[0][i]!=player)
            return 1+i;
    }

    if(board[1][1]==opponent){ //check diagonals
        if(board[0][0]==opponent && board[2][2]!=player)
            return 9;
        if(board[2][2]==opponent && board[0][0]!=player)
            return 1;
        if(board[0][2]==opponent && board[2][0]!=player)
            return 7;
        if(board[2][0]==opponent && board[0][2]!=player)
            return 3;
    }
    else if(board[1][1]!=player && ((board[0][0]==opponent && board[2][2]==opponent)||(board[0][2]==opponent && board[2][0]==opponent)))
        return 5;
    else
        return 0;
}

void pc_move(int pc, int difficulty){
    printf("\n\nPC is making a move...\n");
    sleep(1);
    int opponent;
    int cell;
    if (pc==0)
        opponent = 1;
    else
        opponent = 0;

    if (!difficulty){ //difficulty=0 means normal mode and pc will do a random move
        do{
            cell = (rand()%9)+1;
        }
        while(!valid_move(cell));

        int cell_id = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cell_id++;
                if(cell==cell_id)
                    board[i][j] = pc;
            }
        }
    }
    else{ //if difficult is set on hard
        if(board[1][1]==-1) //if the central cell is free always goes for it
            board[1][1]=pc;
        else{ //if there is a move that make pc win, it does it
            cell = opponent_win_angle(opponent);
            printf("\n!%d!", cell);
            if(cell>0){
                int cell_id = 0;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        cell_id++;
                        if(cell==cell_id)
                            board[i][j] = pc;
                    }
                }
            }
            else{ //if there is a move that make opponent wins the pc goes for that cell
                cell = opponent_win_angle(pc);
                if(cell>0){
                    int cell_id = 0;
                    for(int i=0; i<3; i++){
                        for(int j=0; j<3; j++){
                            cell_id++;
                            if(cell==cell_id)
                                board[i][j] = pc;
                        }
                    }
                }
                else{ //if there is no move to stop other player to win or that make pc wins, random move
                    do{
                        cell = (rand()%9)+1;
                    }
                    while(!valid_move(cell));

                    int cell_id = 0;
                    for(int i=0; i<3; i++){
                        for(int j=0; j<3; j++){
                            cell_id++;
                            if(cell==cell_id)
                                board[i][j] = pc;
                        }
                    }
                }
            }
        }
    }
}

void player_move(int player){
    char symbol;
    int cell;

    if(!player)
        symbol = 'O';
    else
        symbol = 'X';
    do{
        cell = 0;
        printf("\nWhere do you want to insert %c? Insert the number corresponding to the cell: ", symbol);
        print_free_cells();
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
        int turn = 0, player1, player2;
        clear_board();

        set_names();

        printf("\nFlipping a coin to decide who starts...\n");
        if (rand()%2){
            printf("\n%s starts", player1_name);
            player1 = 0;
            player2 = 1;
        }
        else{
            printf("\n%s starts", player2_name);
            player1 = 1;
            player2 = 0;
        }
        do{
            printf("\n\n\t    TURN %d\n", turn+1);
            sleep(2);
            if(turn%2==0)
                player_move(0);
            else
                player_move(1);

            print_board();
            turn++;
        }
        while(!check_win() && turn<9);

        sleep(1);
        if(check_win()){
            if(turn%2==0 && player1==0)
                printf("\n%s wins!", player2_name);
            if(turn%2==0 && player1!=0)
                printf("\n%s wins!", player1_name);
            if(turn%2!=0 && player1==0)
                printf("\n%s wins!", player1_name);
            if(turn%2!=0 && player1!=0)
                printf("\n%s wins!", player2_name);
        }
        else
            printf("\nDraw!");

    }
    else{ //mode is set on 1 or 2 that means plays vs pc
        int turn = 0, player, pc;
        clear_board();
        printf("\nFlipping a coin to decide who starts...\n");
        if (rand()%2){
            printf("\nPlayer starts");
            player = 0;
            pc = 1;
        }
        else{
            printf("\nPC starts");
            player = 1;
            pc = 0;
        }

        do{
            printf("\n\n\t    TURN %d\n", turn+1);
            sleep(2);
            if(turn%2==0 && player==0)
                player_move(0);
            if(turn%2!=0 && player==1)
                player_move(1);
            if(turn%2==0 && player==1)
                pc_move(0, mode-1);
            if(turn%2!=0 && player==0)
                pc_move(1, mode-1);

            sleep(1);
            print_board();
            turn++;
        }
        while(!check_win() && turn<9);

        sleep(1);
        if(check_win()){
            if(turn%2==0 && player==0)
                printf("\nPC wins!");
            if(turn%2==0 && player!=0)
                printf("\nPlayer wins!");
            if(turn%2!=0 && player==0)
                printf("\nPlayer wins!");
            if(turn%2!=0 && player!=0)
                printf("\nPC wins!");
        }
        else
            printf("\nDraw!");
    }
}
