#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define CANT 8
#define MINES 10


typedef struct  {
    int bombs;
    bool flag;
    bool isBomb;
    bool visible;
}box;


void line(){
    printf("\n");
    printf("  ");
    for (int i=0; i<(CANT*2); i++){
        printf("-");
    }
    printf("\n");
}

//print board when Game Over
void endGame(box matrix[CANT][CANT]){
        printf("  ");
    for (int i=0; i<CANT; i++){
        printf("%c ", i+'A');
    }
    line();
    for (int i=0; i<CANT; i++){
        printf("%d|", i);
        for (int j=0; j<CANT; j++){
            if (matrix[i][j].isBomb)
                printf("X|");
            else
                printf("%d|", matrix[i][j].bombs);
        }
        line();
    }
}


//print board after every move
void printBoard(box matrix[CANT][CANT]){
    printf("  ");
    for (int i=0; i<CANT; i++){
        printf("%c ", i+'A');
    }
    line();
    for (int i=0; i<CANT; i++){
        printf("%d|", i);
        for (int j=0; j<CANT; j++){
            if (matrix[i][j].visible){
                printf("%d|", matrix[i][j].bombs);//print the number of bombs around
            }
            else {
                if(matrix[i][j].flag)
                    printf("?|");
                else
                    printf(" |");//if the box is not visible, print a space
            }
    }
        line();
    }
}
//initialize the board
void initBoard(box matrix[CANT][CANT]){
    for (int i=0; i<CANT; i++){
        for (int j=0; j<CANT; j++){
            matrix[i][j].bombs = 0;
            matrix[i][j].isBomb = false;
            matrix[i][j].visible = false;
            matrix[i][j].flag = false;
        }
    }
    for (int i=0; i<MINES; i++){
        int x = rand()%CANT;
        int y = rand()%CANT;
        if (matrix[x][y].isBomb){
            i--;
        }
        else{
            matrix[x][y].isBomb = true;
        }
    }
}

//functions for bomb number
bool getBomb(box matrix[CANT][CANT], int x, int y){
    if (x < 0 || x > CANT || y < 0 || y > CANT){
        return false;
    }
    if (matrix[x][y].isBomb){
        return true;
    }
    return false;
}

int bombs(box matrix[CANT][CANT], int x, int y){
    if (matrix[x][y].isBomb){
        return -1;
    }
    int cant = 0;

    if (getBomb(matrix, x-1, y+1))
        cant++;
    if (getBomb(matrix, x, y+1))
        cant++;
    if (getBomb(matrix, x+1, y+1))
        cant++;
    if (getBomb(matrix, x+1, y))
        cant++;
    if (getBomb(matrix, x+1, y-1))
        cant++;
    if (getBomb(matrix, x, y-1))
        cant++;
    if (getBomb(matrix, x-1, y-1))
        cant++;
    if (getBomb(matrix, x-1, y))
        cant++;

    return cant;
}

void initBombNumber(box matrix[CANT][CANT]){
    for (int i=0; i<CANT; i++){
        for (int j=0; j<CANT; j++){
            if (!matrix[i][j].isBomb)
                matrix[i][j].bombs = bombs(matrix, i, j);
        }
    }
}

bool validatePosition(int x, char y){
    if (y < 'A' || y > 'H' || x < 0 || x > 7){
        printf("Invalid position\n");
        return false;
    }
    return true;
}

void getPosition(int *x, char *y){
    do{
    printf("Enter the box: \n");
    printf("Row: ");
    scanf(" %d", x);
    printf("Column: ");
    scanf (" %c", y);
    }while(!validatePosition(*x, *y));
}

void getOption(int *option){
    do{
    printf("1. Open box\n");
    printf("2. Mark/Unmark box\n");
    printf("3. Exit\n");
    printf("Option: ");
    scanf("%d", option);
    }while(*option < 1 || *option > 4);
}

//when the value of a box is 0, i have to show the near boxes with no bombs, i need a recursive function
void showNear(box matrix[CANT][CANT], int x, int y, int *boxes){
    if ((x < 0) || (x > CANT) || (y < 0) || (y > CANT)){
        return;
    }
    if (matrix[x][y].isBomb || matrix[x][y].visible){
        return;
    }
    (*boxes)--;
    matrix[x][y].visible = true;
    if (matrix[x][y].bombs != 0){
        return;
    }
    else
        showNear(matrix, x-1, y+1,boxes);
        showNear(matrix, x, y+1,boxes);
        showNear(matrix, x+1, y+1,boxes);
        showNear(matrix, x+1, y,boxes);
        showNear(matrix, x+1, y-1,boxes);
        showNear(matrix, x, y-1,boxes);
        showNear(matrix, x-1, y-1,boxes);
        showNear(matrix, x-1, y,boxes);
}

void switchFlag(box matrix [CANT][CANT], int x, int y){
    if (!matrix[x][y].visible){
        if (matrix[x][y].flag){
            matrix[x][y].flag = false;
        }
        else{
            matrix[x][y].flag = true;
        }
    }
}

//-----------------------------------------------MAIN--------------------------------------------------
int main(){
    int boxes;;
    bool gameOver = false;
  //srand(time(NULL));

    box matrix[CANT][CANT];
    initBoard(matrix);
    initBombNumber(matrix);
    printf("Welcome to Minesweeper!\n");
    boxes = CANT*CANT - MINES;
    char column;
    int x,y,option;
    while (!gameOver){
        printf("\n");
        printf("Boxes left: %d\n", boxes);
        printBoard(matrix);
        printf("\n");

        getOption(&option);
        getPosition(&x, &column);
        int y = column - 'A';

        if (option == 2){
            switchFlag(matrix, x, y);
            continue;
        }
        if(option == 3){
            endGame(matrix);
            gameOver = true;
        }

        if (matrix[x][y].isBomb){
            gameOver = true;
            printf("\n\n----------------GAME OVER----------------\n\n");
            endGame(matrix);
        }
        else{
            boxes--;
            if(matrix[x][y].bombs == 0)
                showNear(matrix, x, y, &boxes);
            matrix[x][y].visible = true;
            if (boxes == 0){
                gameOver = true;
                printf("You won!\n");
            }
        }
        system("clear");
    }
}
