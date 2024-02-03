#define RED_R printf("\e[0;31m"),
#define RED_B printf("\e[1;31m"),
#define RED_UL printf("\e[4;31m"),
#define RED_BG printf("\e[41m"),
#define RED_HIBG printf("\e[0;101m"),
#define RED_HI printf("\e[0;91m"),
#define RED_BHI printf("\e[1;91m"),
#define RESET printf("\x1b[0m");

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


int main(){
        char w = getch();
    printf("%c",w);
    printf("\n");
    RESET
    
    RED_R
    printf("Hello World!\n");
    RED_B
    printf("Hello World!\n");
    RED_UL
    printf("Hello World!\n");
    RED_BG
    printf("Hello World!");
    RESET
    printf("\n");
    RED_HIBG
    printf("Hello World!");
    RED_HI
    printf("\nHello World!\n");
    RED_BHI
    printf("Hello World!\n");
    system("pause");
}