#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define BLACK_BG_WHITE_TEXT "\x1b[0;30;107m"

//  welcome
#define CYAN "\033[0;36m"
#define YELLOW "\e[1;93m"
#define GREEN   "\x1b[32m"

#define RED_R "\e[0;31m"
#define RED_B "\e[1;31m"
#define RED_UL "\e[4;31m"
#define RED_BG "\e[41m"
#define RED_HIBG "\e[0;101m"
#define RED_HI "\e[0;91m"
#define RED_BHI "\e[1;91m"

#define BLUE_R "\e[1;94m"

#define BHGRN "\e[1;92m"

#define RESET "\x1b[0m"

void delay();
int counter (char* message);
void welcomemessage (char* message);
void GameRules();
void JUS_THE_TABLE();
void PRINT_TABLE();
int CHECK_WINNER();
void UPDATE(int USER);
void USER_INPUT_AND_UPDATES();
void START_GAME();
void RESET_GAME();
void END_SCREEN();
// ===============================================
// ===============================================
// ===============================================
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
    
    printf(RED_R "\x1b[31m""Rules of the game:\n""\x1b[31m" RESET);
    
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
    printf("If you ready press any "RED_BG "key" RESET": ");
    startGame = getch() - '0';
}

/*-------------------------------------------*/

char SQUARES_NUMBERS[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

/*-------------------------------------------*/
// Varibals
int playerX = 0;
int playerO = 0;
int end_game_counter = 0;
int X_USER;
int O_USER;
int flag = 0;
int inputs_counter = 0;

void JUS_THE_TABLE(){
    printf("-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("|");

        for (int j = 0; j <= 2; j++)
            if(SQUARES_NUMBERS[i][j] == 'X'){
                
                printf(RED_B" %c "RESET, SQUARES_NUMBERS[i][j]);
                
                printf("|");
            }
            else if(SQUARES_NUMBERS[i][j] == 'O'){
                
                printf(BLUE_R" %c "RESET, SQUARES_NUMBERS[i][j]);
                
                printf("|");
            }else{
                printf(" %c ",SQUARES_NUMBERS[i][j]);
                printf("|");
            }
            
        printf("\n");
        printf("-------------\n");
    }
}
void PRINT_TABLE(){
    if(!flag) printf(RED_B "X "RESET "turn...\n");
    else printf(BLUE_R "O " RESET "turn...\n");
    printf("-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("|");

        for (int j = 0; j <= 2; j++)
            if(SQUARES_NUMBERS[i][j] == 'X'){
                
                printf(RED_B" %c "RESET, SQUARES_NUMBERS[i][j]);
                
                printf("|");
            }
            else if(SQUARES_NUMBERS[i][j] == 'O'){
                
                printf(BLUE_R" %c "RESET, SQUARES_NUMBERS[i][j]);
                
                printf("|");
            }else{
                printf(" %c ",SQUARES_NUMBERS[i][j]);
                printf("|");
            }
            
        printf("\n");
        printf("-------------\n");
    }
}
/*------------------------------------------*/
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
/*------------------------------------------*/
void UPDATE(int USER){
    // invalid number
    USER -= '0';
    if(USER > 9 || USER < 1){
        if (flag) flag = 0;
        else    flag = 1;
        system("cls");
        PRINT_TABLE();
        
        printf(RED_HIBG"Enter a valid number"RESET);
        
        printf("\n");
        end_game_counter--;
        return;
    }
    
    // ==> IF ALREADY TAKEN <==
    if( SQUARES_NUMBERS[(USER-1)/3][(USER-1)%3] == 'X' || 
        SQUARES_NUMBERS[(USER-1)/3][(USER-1)%3] == 'O'){
        // when input the same number twice
        // The third symbol will be the first symbol
        // input [1] -> X
        // input [1] -> for "O" but 1 is already taken
        // input [2] -> for "O" but we get X again in 2
        // that's because the change of the flag every input
        // this condition prevent that bug
        if (flag) flag = 0;
        else    flag = 1;
        system("cls");
        PRINT_TABLE();
        
        printf(YELLOW"\n[%d] "CYAN,USER);
        
        printf(RED_R"Already taken\n"RESET);
        
        printf("Enter another number:\n");
        
        // because it is considered as a round
        //but we don't want that
        end_game_counter--; 
        
        
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
/*------------------------------------------*/
int PRINT_GAME_RESULT(){
    if(playerX) {
            system("cls");
            JUS_THE_TABLE();
            printf("Player " RED_B "X" RESET " won!\n");
            return 1;
        }
        else if (playerO){
            system("cls");
            JUS_THE_TABLE();
            printf("Player " BLUE_R "O" RESET " won!\n\n");
            return 1;
        }
        else if (end_game_counter == 9){
            system("cls");
            JUS_THE_TABLE();
            printf("It's a "BLACK_BG_WHITE_TEXT"DRAW!\n"RESET);
            return 1;
        }
    return 0;
}
/*------------------------------------------*/
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
        // print game results:
        // returns 1 if x win, o win, draw happen
        // returns 0 else
        if(PRINT_GAME_RESULT()) break;
    }
    
    printf("\nNew Game? [Y/y] \nor press any key to ");
        printf(RED_HI"EXIT"RESET".");
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
    for (int i = 0; i < 199990000; i++);
}
void END_SCREEN(){
    printf("%c" RED_BHI "Thanks for playing ^.^" RESET "\n", 248);
    printf(YELLOW "ab2a t3ala tany\n\n" RESET);
    JUS_THE_TABLE();
    delay();

    printf("\e[4;37m""Produced by:\n" RESET);
    delay();
    
    const char symbol_end = 192;
    printf(RED_HI "%cAhmed Mohamed\n" RESET, symbol_end);
    delay();
    
    printf(BLUE_R "%cMalak Salah Elddin\n" RESET, symbol_end);
    delay();
    
    printf(YELLOW "%cMoataz Mohamed\n" RESET, symbol_end);
    delay();

    printf(GREEN "%cAhmed Tharwat\n" RESET, symbol_end);

    delay();
    printf("====");
    delay();
    printf("====");
    delay();
    printf("====");
    delay();
    printf(RED_BG "BYE!" RESET); /* print love symbol */
    delay();
    printf("====");
    delay();
    printf("====");
    delay();
    printf("====\n");
    getch();
}
/*------------------------------------------*/
int main(){
    welcomemessage ("\033[1;34mwelcome to tic tac toe\033[0m");
    GameRules();
    
    if(startGame)
        START_GAME();
    
    delay();

    END_SCREEN();
    
    exit(0);
}