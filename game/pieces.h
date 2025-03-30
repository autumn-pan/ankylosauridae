#ifndef PIECES_H
#define PIECES_H
#include "types.h"
#include <vector>

using namespace std;
    
class Game;

enum Color
{
    WHITE,
    BLACK,
    NONE
};

typedef struct {
    Type type;
    // Denotes what color the tile is held
    Color color;
} Tile;

typedef struct {
    Tile * tiles[8][8];
} Board;

Tile * init_tile(Type type);
Board * init_pawn_board();
bool in_bounds(int row, int col);

typedef struct {
    int row;
    int col;
} Pos;

Pos init_pos(int row, int col);

class Piece
{
    public:
        Piece(Board * board, int row, int col, Color color, Type type);
        int row;
        int col;
        Board * board;
        Color color;

        Type type = UNASSIGNED;

        virtual vector<Pos> get_legal_moves(Board * board);

        void move(Pos pos, Game * game);
};

class Pawn : public Piece
{
    public:
        using Piece::Piece;
        Type type = PAWN;
        int material = 1;

        virtual vector<Pos> get_legal_moves(Board * board) override;
};

class Bishop : public Piece
{
    public:
        using Piece::Piece;
        Type type = BISHOP;
        int material = 3;

        virtual vector<Pos> get_legal_moves(Board * board) override;
};

class Knight : public Piece
{
    public:
        using Piece::Piece;
        Type type = KNIGHT;
        int material = 3;

        virtual vector<Pos> get_legal_moves(Board * board) override;
};

#endif