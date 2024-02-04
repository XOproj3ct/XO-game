#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

//  welcome
#define CYAN printf("\033[0;36m");
#define YELLOW printf("\e[1;93m");

#define RED_R printf("\e[0;31m");
#define RED_B printf("\e[1;31m");
#define RED_UL printf("\e[4;31m");
#define RED_BG printf("\e[41m");
#define RED_HIBG printf("\e[0;101m");
#define RED_HI printf("\e[0;91m");
#define RED_BHI printf("\e[1;91m");

#define BLUE_R printf("\e[1;94m");


#define RESET printf("\x1b[0m");

int counter (char* message) {
    int count;
    for (count = 0; message[count] != '\0'; count++); 
    return count;
}

void welcomemessage (char* message) {
    int n = counter(message) ;  
    for (int i = 7; i < n; i++) printf("-");
    printf("\n| %s |\n", message);
    for (int i = 7; i < n; i++) printf("-");
    printf("\n");
}
int startGame;
void GameRules() {
    RED_R
    printf("\x1b[31m""Rules of the game:\n""\x1b[31m");
    RESET;
    printf("\n");
    printf("1- Get three of your marks (X or O) in a row either horizontally, vertically, or diagonally.\n");
    printf("\n");
    printf("2- Players take turns placing their mark in empty squares on a 3x3 grid.\n");
    printf("\n");
    printf("3- The first player to align three marks in a row wins the game.\n");
    printf("\n");
    printf("4- If all squares are filled and no player has three marks in a row, the game is declared a draw.\n");
    printf("\n");
    printf("----------------------------------------\n");
    printf("----------------------------------------\n");
    printf("If you ready input [1]: ");
    startGame = getch() - '0';
    // printf("\033[0m");
}




/*-------------------------------------------*/


char SQUARES_NUMBERS[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

/*-------------------------------------------*/
int playerX = 0;
int playerO = 0;
int end_game_counter = 0;
int X_USER;
int O_USER;
int flag = 0;
int inputs_counter = 0;

void PRINT_TABLE(){
    if(!flag) printf("X turn\n");
    else printf("O trun\n");
    printf("-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("|");

        for (int j = 0; j <= 2; j++)
            if(SQUARES_NUMBERS[i][j] == 'X'){
                RED_B
                printf(" %c ", SQUARES_NUMBERS[i][j]);
                RESET
                printf("|");
            }
            else if(SQUARES_NUMBERS[i][j] == 'O'){
                BLUE_R
                printf(" %c ", SQUARES_NUMBERS[i][j]);
                RESET
                printf("|");
            }else{
                printf(" %c ",SQUARES_NUMBERS[i][j]);
                printf("|");
            }
            
        printf("\n");
        printf("-------------\n");
    }
}

// Varibals

/*----------------------------------------*/

int CHECK_WINNER(){
    //Check Win for rows
    if(1){
        for(int i=0; i<3; i++)
            if(SQUARES_NUMBERS[i][0] == SQUARES_NUMBERS[i][1] && SQUARES_NUMBERS[i][0] == SQUARES_NUMBERS[i][2])/*|| SQUARES_NUMBERS[0][i] == SQUARES_NUMBERS[1][i] && SQUARES_NUMBERS[0][i] == SQUARES_NUMBERS[2][i])*/
                if(SQUARES_NUMBERS[i][0] == 'O')
                    playerO++;
                else{
                    playerX++;
                }
        
    // Check win for coloumns
    for(int i = 0; i < 3; i++)
        if(SQUARES_NUMBERS[0][i] == SQUARES_NUMBERS[1][i] && SQUARES_NUMBERS[0][i] == SQUARES_NUMBERS[2][i])
            if(SQUARES_NUMBERS[0][i]=='O')
                playerO++;
            else
                playerX++;

    //checking the win for both diagonal

    if(SQUARES_NUMBERS[0][0] == SQUARES_NUMBERS[1][1] && SQUARES_NUMBERS[0][0] == SQUARES_NUMBERS[2][2])
        if(SQUARES_NUMBERS[0][0]=='O')
            playerO++;
        else
            playerX++;

    if(SQUARES_NUMBERS[0][2] == SQUARES_NUMBERS[1][1] && SQUARES_NUMBERS[0][2] == SQUARES_NUMBERS[2][0])
        if(SQUARES_NUMBERS[0][2]=='O')
            playerO++;
        else
            playerX++;
}

// Check for a tie

// working but prints it is a tie 2 times

    else if(end_game_counter == 10 ){
        printf("It is a Tie!!\n");
        return 1;
    }

    // 0
    // 1 --> X
    // 2 --> O
    // 3 --> X
    return 0;
}

/*----------------------------*/

void UPDATE(int USER){
    // invalid number
    USER -= '0';
    if(USER > 9 || USER < 1){
        if (flag) flag = 0;
        else    flag = 1;
        system("cls");
        PRINT_TABLE();
        RED_HIBG
        printf("Enter a valid number");
        RESET
        printf("\n");
        end_game_counter--;
        return;
    }
    
    // ==> IF ALREADY TAKEN <==
    if( SQUARES_NUMBERS[(USER-1)/3][(USER-1)%3] == 'X' || 
        SQUARES_NUMBERS[(USER-1)/3][(USER-1)%3] == 'O'){
        if (flag) flag = 0;
        else    flag = 1;
        system("cls");
        PRINT_TABLE();
        YELLOW
        printf("\n[%d] ",USER);
        CYAN
        printf("Already taken\n");
        RED_R
        printf("Enter another number:\n");
        RESET
        // because it is considered as a round
        //but we don't want that
        end_game_counter--; 
        
        // when input the same number twice
        // The third symbol will be the first symbol
        // input [1] -> X
        // input [1] -> for "O" but 1 is already taken
        // input [2] -> for "O" but we get X again in 2
        // that's because the change of the flag every input
        // this condition prevent that bug
        
        
        return;
    }
    
    // ==> Updating <==
    if(flag)
        SQUARES_NUMBERS[(USER-1)/3][(USER-1)%3] = 'X';
    else
        SQUARES_NUMBERS[(USER-1)/3][(USER-1)%3] = 'O';
    system("cls");
    
    PRINT_TABLE();
};
/*------------------------------------------*/

void USER_INPUT_AND_UPDATES(){
    // take input from user
    // update global array
    // input validation system    
        if(!flag){
        X_USER = getch();
        inputs_counter++;
        flag = 1;
        UPDATE(X_USER);
        if(inputs_counter > 4) // no one will win before 5 inputs
            CHECK_WINNER();

    }else if(flag){
        O_USER = getch();
        inputs_counter++;
        flag = 0;
        UPDATE(O_USER);
        if(inputs_counter > 4)
            CHECK_WINNER();
    } 
}
/*--------------------------------------*/
//logic
// global scope
    // 3x3 array from 1 to 9

// function to print the table



/*int main()
{
    printf("Welcome to JavaTpoint");
    printf("\nThis is the Second sentence of the program");
    clrscr();
    printf("Output After using clrscr() function");
    return 0;
}*/
void RESET_GAME(){
    char x = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            SQUARES_NUMBERS[i][j] = x;
            x++;
        }
    }    
    
    playerX = 0;
    playerO = 0;
    end_game_counter = 0;
    X_USER;
    O_USER;
    flag = 0;
    inputs_counter = 0;
}

void START_GAME(){
    system("cls");
    PRINT_TABLE();
    while(++end_game_counter != 10){
        USER_INPUT_AND_UPDATES();
        if(playerO ^ playerX){
            if(playerX) printf("Player X won\n");
            else if (playerO) printf("Player O won\n\n");
            
            break;
        }else if (end_game_counter == 10)
            printf("TIE\n");
        
    }
    
    printf("\nNew Game? [Y/y] \nor press any key to ");
    RED_R printf("END");RESET
            char NEW_END = getch();
            if(NEW_END == 'Y' || NEW_END == 'y'){
                RESET_GAME();
                return START_GAME();
            }
            else{
                system("cls");
                // malak 
                return;
            }
            
            
};

void delay(){
    for (int i = 0; i < 199999999; i++)
    {
        i++; i--;
    }
}


int main(){
    welcomemessage ("\033[1;34mwelcome to tic tac toe\033[0m");
    GameRules();
    
    if(startGame)
        START_GAME();
    
    delay();
    
    printf("Thanks for playing ^.^\n");
    printf("ab2a t3ala tany\n\n");
    
    delay();
    
    printf("produced by :\n");
    
    delay();
    
    printf("Ahmed Tharwat Abdelhamid\n");
    
    delay();
    
    printf("Moataz Mohamed Abdelrahman\n");
    
    delay();
    
    printf("Ahmed Mohamed Ali\n");
    
    delay();
    
    printf("Malak Salah Elddin Ahmed");
        getchar();

    return 0;
    
}


    

