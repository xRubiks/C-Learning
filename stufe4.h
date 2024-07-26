//
// Created by quentin on 26.07.2024.
//

#include <stdbool.h>

#ifndef UNTITLED2_STUFE4_H
#define UNTITLED2_STUFE4_H

typedef struct Playfield{
    int size;
    int bombs;
    enum CellState** backField;
    enum CellState** fromtField;
}Playfield;


enum CellState {
    REVEALED,
    UNREVEALED,
    BOMB,
    MARKED
};


void printField(Playfield* playfield, bool showBombs);
Playfield* initField();



#endif //UNTITLED2_STUFE4_H
