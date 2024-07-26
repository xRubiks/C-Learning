#include "stufe4.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int main() {
    Playfield* playfield = initField();
    printField(playfield, true);
    return 0;
}