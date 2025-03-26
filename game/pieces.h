#ifndef PIECES_H
#define PIECES_H
#include "types.h"
#include "board.h"
#include <vector>

typedef struct {
    int row;
    int col;
} Pos;

Pos init_pos(int row, int col);

class Piece
{
    public:
        Piece(int row, int col, bool white);
        int row;
        int col;
        bool white;
        Type type = UNASSIGNED;

        vector<Pos> get_legal_moves(Board * board);
        void move(Board board);
};

class Pawn : public Piece
{
    public:
        using Piece::Piece;
        Type type = PAWN;
        int material = 1;

        vector<Pos> get_legal_moves(Board * board);
        void move(Board board);

};

#endif