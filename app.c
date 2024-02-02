#include<stdio.h>  
#include <stdlib.h>
#include<conio.h> 
#include <string.h>
// skip welcome

char SQUARES_NUMBERS[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void PRINT_TABLE(){
    printf("-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        
        for (int j = 0; j <= 2; j++)
            printf(" %c |", SQUARES_NUMBERS[i][j]);
        
        printf("\n");
        printf("-------------\n");
    }    
}






int X_USER;
int O_USER;
int flag = 0;
int inputs_counter = 0;

int CHECK_WINNER(){
    for(int i=0; i<3; i++)
        if(SQUARES_NUMBERS[i][0] == SQUARES_NUMBERS[i][1] && SQUARES_NUMBERS[i][0] == SQUARES_NUMBERS[i][2] || SQUARES_NUMBERS[0][i] == SQUARES_NUMBERS[1][i] && SQUARES_NUMBERS[0][i] == SQUARES_NUMBERS[2][i])
        {
            //BUGGGGGGGGGGGGGGGGGGGGG
                printf("PLAYER %c WON!!\n", SQUARES_NUMBERS[i][0]);
            return 1;
        }

    //checking the win for both diagonal

    if(SQUARES_NUMBERS[0][0] == SQUARES_NUMBERS[1][1] && SQUARES_NUMBERS[0][0] == SQUARES_NUMBERS[2][2] || SQUARES_NUMBERS[0][2] == SQUARES_NUMBERS[1][1] && SQUARES_NUMBERS[0][2] == SQUARES_NUMBERS[2][0])
    {
        //BUGGGGGGGGGGGGGGGGGGGGG
        if(inputs_counter%2)
                printf("PLAYER 'X' WON!!\n");
            else
                printf("PLAYER 'O' WON!!\n");
        return 1;
    }
    // 0
    // 1 --> X
    // 2 --> O
    // 3 --> X
    return 0;
};

void UPDATE(int USER){
    if(flag){
        if(USER < 4)
            SQUARES_NUMBERS[0][(USER-1)%3] = 'X';
        else if(USER < 7)
            SQUARES_NUMBERS[1][(USER-1)%3] = 'X';
        else if(USER < 10) 
            SQUARES_NUMBERS[2][(USER-1)%3] = 'X';
    }else{
        if(USER < 4)
            SQUARES_NUMBERS[0][(USER-1)%3] = 'O';
        else if(USER < 7)
            SQUARES_NUMBERS[1][(USER-1)%3] = 'O';
        else if(USER < 10) 
            SQUARES_NUMBERS[2][(USER-1)%3] = 'O';
    }
    PRINT_TABLE();
};

void USER_INPUT_AND_UPDATES(){
    // take input from user
    // update global array
    // input validation system
    
        if(!flag){
        scanf("%d", &X_USER, inputs_counter++);
        flag = 1;
        UPDATE(X_USER);
        if(inputs_counter > 4) // no one will win before 5 inputs
            CHECK_WINNER();
        
    }else if(flag){
        scanf("%d", &O_USER, inputs_counter++);
        flag = 0;
        UPDATE(O_USER);
        if(inputs_counter > 4)
            CHECK_WINNER();
    }
}

//logic
// global scope
    // 3x3 array from 1 to 9 

// function to print the table  

    
int end_game_counter = 0;
int main()  
{  
    printf("Welcome to JavaTpoint");  
    printf("\nThis is the Second sentence of the program");  
    clrscr();  
    printf("Output After using clrscr() function");  
    return 0;  
}  