#include "stufe4.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int main() {
    Playfield* playfield = initField();
    while(true) {
        printField(playfield, false);
        int row, col;
        input(playfield, &row, &col);
        revealFieldAround(row, col, playfield);
    }
}