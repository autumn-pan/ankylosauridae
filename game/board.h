#ifndef BOARD_H
#define BOARD_H
#include "types.h"

    typedef struct {
        Type type;
    } Tile;

    typedef struct {
        Tile * tiles[8][8];
    } Board;
#endif