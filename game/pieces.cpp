#include "./pieces.h"
#include "./board.h"
#include <vector>

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

Pos init_pos(int row, int col)
{
    Pos pos = {};
    pos.row = row;
    pos.col = col;
    return pos;
}

class Piece
{
    public:
        Piece(int row, int col)
        {
            this->row = row;
            this->col = col;
        }

        vector<Pos> get_legal_moves(Board board)
        {
            vector<Pos> moves;
            return moves;
        }

        int row;
        int col;
        Type type = UNASSIGNED;
};

class Pawn : public Piece
{
    public:
        using Piece::Piece;
        // Returns legal moves for a given pawn
        vector<Pos> get_legal_moves(Board * board)
        {
            // If it is at the end, it can't move
            vector<Pos> moves;
            if(row == 7)
                return moves;

            if(board->tiles[row+1][col]->type == EMPTY)
                moves.push_back(init_pos(row + 1, col));

            if(row != 7 && board->tiles[row+1][col + 1]->type != EMPTY)
                moves.push_back(init_pos(row + 1, col + 1));

            if(row != 0 && board->tiles[row+1][col - 1]->type != EMPTY)
                moves.push_back(init_pos(row + 1, col - 1));
        }

    private:
        
        Type type = PAWN;
};

int main()
{
    Pawn pawn(1,2);
    Board * board = {};
    pawn.get_legal_moves(board);
    return 0;
}