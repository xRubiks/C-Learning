//
// Created by quentin on 26.07.2024.
//

#ifndef UNTITLED2_STUFE4_H
#define UNTITLED2_STUFE4_H

typedef struct Playfield{
    int size;
    int bombs;
    int** field;
}Playfield;


enum CellState {
    REVEALED,
    UNREVEALED,
    BOMB,
    MARKED
};





#endif //UNTITLED2_STUFE4_H
