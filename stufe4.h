//
// Created by quentin on 26.07.2024.
//

#include <stdbool.h>

#ifndef UNTITLED2_STUFE4_H
#define UNTITLED2_STUFE4_H

typedef struct Playfield{
    int size;
    int bombs;
    int revealedCells;
    enum CellState** backField;
    enum CellState** fromtField;
}Playfield;


enum CellState {
    REVEALED,
    UNREVEALED,
    BOMB
};


void printField(Playfield* playfield, bool showBombs);
Playfield* initField();
void revealFieldAround(int x, int y, Playfield* playfield);
void input(Playfield* playfield, int* row, int* col);



#endif //UNTITLED2_STUFE4_H
