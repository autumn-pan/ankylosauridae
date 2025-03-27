#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "board.h"

using namespace std;

Tile * init_tile(Type type)
{
    Tile * tile = (Tile *)malloc(sizeof(Tile));
    tile->type = type;

    return tile;
}

Board * init_pawn_board()
{
    Board * board = (Board *)malloc(sizeof(Board));
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board->tiles[i][j] = init_tile(EMPTY);
        }
    }

    return board;
}

void move_board(Board * board, int row, int col, int new_row, int new_col)
{
    board->tiles[new_row][new_col] = board->tiles[row][col];
    board->tiles[row][col] = init_tile(EMPTY);
}

bool in_bounds(int row, int col)
{
    if (row < 8 && row > -1 && col < 8 && col > -1)
        return true;
    return false;
}