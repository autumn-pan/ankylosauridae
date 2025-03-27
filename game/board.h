#ifndef BOARD_H
#define BOARD_H

#include "./types.h"
#include <vector>

    using namespace std;
    
    typedef struct {
        Type type;
    } Tile;

    typedef struct {
        Tile * tiles[8][8];
    } Board;

    Tile * init_tile(Type type);
    Board * init_pawn_board();
    bool in_bounds(int row, int col);
    
#endif