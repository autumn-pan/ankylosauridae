#ifndef BOARD_H
#define BOARD_H
#include "types.h"
#include <vector>
#include "pieces.h"

    using namespace std;
    
    class Piece;

    typedef struct {
        Type type;
        vector<Piece> attackers;
    } Tile;

    typedef struct {
        Tile * tiles[8][8];
    } Board;
#endif