//
// Created by quentin on 26.07.2024.
//


#include "stufe4.h"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>



/*
 * typedef struct Playfield{
    int size;
    int bombs;
    int** backField;
}Playfield;


enum CellState {
    REVEALED,
    UNREVEALED,
    BOMB,
    MARKED
};

*/

void updateState(Playfield* playfield, int* row, int* col) {
    if(playfield->backField[*row][*col] == BOMB) {
        printf("You hit a bomb, game over\n");
        exit(0);
    }
    if(playfield ->revealedCells == 90) {
        printf("Du hast meine Liebe gebonen!\n");
        exit(0);
    }
}

bool checkField(Playfield* playfield, int x, int y) {
    return x >= 0 && y >= 0 && x < playfield->size && y < playfield->size;
}

void input(Playfield* playfield, int* row, int* col) {
    bool input = false;
    int size = 4;
    while(!input) {
        printf("Please enter the field you want to operate on : ");
        scanf("%d, %d", row, col);
        if(!checkField(playfield, *row, *col)) {
            printf("Invalid input, please try again\n");
            continue;
        }
        input = true;
    }
    updateState(playfield, row, col);
}


Playfield* initField() {
    Playfield* playfield = (Playfield*) malloc (sizeof(Playfield));
    playfield->size = 10;
    playfield->bombs = 10;
    playfield->revealedCells = 0;
    playfield->backField = malloc(sizeof (enum CellState*) * playfield->size);
    playfield->fromtField = malloc(sizeof (enum CellState*) * playfield->size);
    for(int i = 0; i < playfield->size; i++) {
        playfield->backField[i] = malloc(sizeof(enum CellState) * playfield->size);
        playfield->fromtField[i] = malloc(sizeof(enum CellState) * playfield->size);
    }
    for(int x = 0; x < playfield->size; ++x) {
        for(int y = 0; y < playfield->size; ++y) {
            playfield->backField[x][y] = REVEALED;
            playfield->fromtField[x][y] = UNREVEALED;
        }
    }
    srand(time(NULL));
    for(int i = 0; i < playfield->bombs; ++i) {
        int x = rand() % playfield->size;
        int y = rand() % playfield->size;
        if(playfield->backField[x][y] == BOMB)
            --i;
        playfield->backField[x][y] = BOMB;
    }
    return playfield;
}


int getSurroundingBombs(int i, int j, Playfield* playfield){
    int bombCount = 0;
    for(int x = i - 1; x <= i + 1; ++x) {
        for(int y = j - 1; y <= j + 1; ++y) {
            if(checkField(playfield, x, y) && playfield->backField[x][y] == BOMB) {
                ++bombCount;
            }
        }
    }
    return bombCount;
}

void revealFieldAround(int x, int y, Playfield* playfield) {
    if (!checkField(playfield, x, y) || playfield->fromtField[x][y] == REVEALED)
        return;
    int bombCount = getSurroundingBombs(x, y, playfield);
    playfield->fromtField[x][y] = REVEALED;
    ++playfield->revealedCells;
    if (bombCount != 0) {
        return;
    }

    for(int i = x - 1; i <= x + 1; ++i) {
        for(int j = y - 1; j <= y + 1; ++j) {
            if(i == x && j == y)
                continue;
            revealFieldAround(i, j, playfield);
        }
    }
        }

void printField(Playfield* playfield, bool showBombs) {
    for(int i = 0; i < playfield->size; ++i) {
        printf("|");
        for(int j = 0; j < playfield->size; ++j) {
            switch(playfield->fromtField[i][j]) {
                case REVEALED:
                    printf("%d ", getSurroundingBombs(i, j, playfield));
                    break;
                case UNREVEALED:
                    printf("_ ");
                    break;
                case BOMB:
                    if(showBombs)
                        printf("* ");
                    else
                        printf("_ ");
                    break;
            }
        }
        printf("|\n");
    }

    printf("\n\n\n");


    for(int i = 0; i < playfield->size; ++i) {
        printf("|");
        for(int j = 0; j < playfield->size; ++j) {
            switch(playfield->backField[i][j]) {
                case REVEALED:
                    printf("%d ", getSurroundingBombs(i, j, playfield));
                    break;
                case UNREVEALED:
                    printf("_ ");
                    break;
                case BOMB:
                    if(showBombs)
                        printf("* ");
                    else
                        printf("_ ");
                    break;
            }
        }
        printf("|\n");
    }

}














