#include "./pieces.h"
#include "./board.h"
#include "types.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;



Pos init_pos(int row, int col)
{
    Pos pos = {};
    pos.row = row;
    pos.col = col;

    return pos;
}

void print_pos(Pos pos)
{
    cout << "Row: " << pos.row << " Col: " << pos.col << endl;
}

Piece::Piece(int row, int col, bool white)
{
    this->row = row;
    this->col = col;
    this->white = white;
}





// Returns legal moves for a given pawn
vector<Pos> Pawn::get_legal_moves(Board * board)
{
    // If it is at the end, it can't move
    vector<Pos> moves;
    if(row == 7)
        return moves; 

    // Checks if the tile ahead is empty
    if(board->tiles[row+1][col]->type == EMPTY)
        moves.push_back(init_pos(row + 1, col));
    // Checks if the pawn can capture
    if(row != 7 && board->tiles[row+1][col + 1]->type != EMPTY)
        moves.push_back(init_pos(row + 1, col + 1));

    if(row != 0 && board->tiles[row+1][col - 1]->type != EMPTY)
        moves.push_back(init_pos(row + 1, col - 1));
            
    return moves;
}

vector<Pos> Bishop::get_legal_moves(Board * board)
{
    vector<Pos> moves;
    int nrow = this->row;
    int ncol = this->col;
    while(in_bounds(nrow + 1, ncol + 1)) moves.push_back(init_pos(++nrow, ++ncol));
    nrow = this->row;
    ncol = this->col;
    while(in_bounds(nrow - 1, ncol + 1)) moves.push_back(init_pos(--nrow, ++ncol));
    nrow = this->row;
    ncol = this->col;
    while(in_bounds(nrow - 1, ncol - 1)) moves.push_back(init_pos(--nrow, --ncol));
    nrow = this->row;
    ncol = this->col;
    while(in_bounds(nrow + 1, ncol - 1)) moves.push_back(init_pos(++nrow, --ncol));


    return moves;
}


int main()
{
    Bishop bishop(1,2, true);
    Board * board = init_pawn_board();
    for(Pos pos : bishop.get_legal_moves(board))
    {
        print_pos(pos);
    }

    cout << "Hi" << endl;

    return 0;
}