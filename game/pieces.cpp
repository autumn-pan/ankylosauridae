#include "./pieces.h"
#include "types.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "player.h"

using namespace std;



Color switch_color(Color color)
{
    switch(color) {
        case WHITE: return BLACK;
        case BLACK: return WHITE;
        default: return NONE;
    }
}

Tile * init_tile(Type type)
{
    Tile * tile = (Tile *)malloc(sizeof(Tile));
    tile->type = type;

    return tile;
}

bool pos_equals(Pos pos1, Pos pos2)
{
    if (pos1.row == pos2.row && pos1.col == pos2.col)
        return true;
    return false;
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
    board->tiles[new_row][new_col]->type = board->tiles[row][col]->type;
    board->tiles[row][col]->type = EMPTY;
}

bool in_bounds(int row, int col)
{
    if (row < 8 && row > -1 && col < 8 && col > -1)
        return true;
    return false;
}

// Initalizes position strcut
Pos init_pos(int row, int col)
{
    Pos pos = {};
    pos.row = row;
    pos.col = col;

    return pos;
}

// Prints a position, mainly for debugging
void print_pos(Pos pos)
{
    cout << "Row: " << pos.row << " Col: " << pos.col << endl;
}

// Define default base constructor
Piece::Piece(Board * board, int row, int col, Color color, Type type)
{
    this->row = row;
    this->col = col;
    this->color = color;
    this->type = type;
    this->board = board;

    board->tiles[row][col]->type = type;
    board->tiles[row][col]->color = color;

}
// Define base functions
vector<Pos> Piece::get_legal_moves(Board * board)
{
    vector<Pos> moves;
    return moves;
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
    if(row != 7 && board->tiles[row+1][col + 1]->color == switch_color(this->color) )
        moves.push_back(init_pos(row + 1, col + 1));

    if(row != 0 && board->tiles[row+1][col - 1]->color == switch_color(this->color))
        moves.push_back(init_pos(row + 1, col - 1));
            
    return moves;
}

vector<Pos> Bishop::get_legal_moves(Board * board)
{
    vector<Pos> moves;
    int nrow = this->row;
    int ncol = this->col;
    int directions[4][2] = {{1,1},{-1,1},{-1,-1},{1,-1}};

    for(int i = 0; i < 4; i++)
    {
        while(in_bounds(nrow + directions[i][0], ncol + directions[i][1]) && board->tiles[nrow+directions[i][0]][ncol+directions[i][1]]->type == EMPTY)
        {
            nrow += directions[i][0];
            ncol += directions[i][1];

            moves.push_back(init_pos(nrow, ncol));
        }
        if(in_bounds(nrow + directions[i][0], ncol + directions[i][1]) && board->tiles[nrow+directions[i][0]][ncol+directions[i][1]]->color == switch_color(this->color))
                moves.push_back(init_pos(nrow + directions[i][0], ncol+directions[i][1]));

        nrow = this->row;
        ncol = this->col;
    }
    return moves;
}

vector<Pos> Knight::get_legal_moves(Board * board)
{
    // Knight movement table
    int positions[8][2] = {
        {-1, -2}, {1, -2},
        {-2, -1}, {2, -1},
        {-2, 1}, {2, 1},
        {-1, 2}, {1, 2}
    };

    vector<Pos> moves;
    for (int i = 0; i < 8; i++)
    {
        
        if (in_bounds(this->row + positions[i][0], this->col + positions[i][1]) && board->tiles[this->row + positions[i][0]][this->col + positions[i][1]]->color == switch_color(this->color))
            moves.push_back(init_pos(this->row + positions[i][0], this->col + positions[i][1]));
    }
    return moves;
}
// Moves a piece to another position
void print_board(Board * board)
{
    for (int i = 0; i < 8; i++)
    {
        cout << endl;
        for (int j = 0; j < 8; j++)
        {
            cout << get_material(board->tiles[i][j]->type)<< ", ";
        }
    }
}


// Move a piece to a specific square
void Piece::move(Pos pos, Game * game) {
    // Check every legal move to see if the move if legal
    Board * board = this->board;
    for (Pos npos : this->get_legal_moves(board))
    {
        if (pos_equals(npos, pos))
        {
            move_board(board, this->row, this->col, pos.row, pos.col);

            if (this->color == BLACK)
                game->white->pop_piece(get_piece_from_pos(game->white, pos));
            else    
                game->black->pop_piece(get_piece_from_pos(game->black, pos));

            break;
        }
    }
}

int main()
{
    Board * board = init_pawn_board();
    Game * game = new Game(board);

    Piece * bishop = (new Bishop(board, 1,2, WHITE, BISHOP));
    Piece * pawn = new Pawn(board, 3,4, BLACK, PAWN);
    Piece * knight = new Knight(board, 1,3, BLACK, KNIGHT);
    game->add(bishop);
    game->add(pawn);
    game->add(knight);
    for(Pos pos : knight->get_legal_moves(board))
    {
        print_pos(pos);
    }
    
    return 0;
}