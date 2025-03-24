#include "./pieces.h"
#include "./board.h"
#include <vector>

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

class Piece
{
    public:
        Piece(int row, int col)
        {
            this->row = row;
            this->col = col;
        }

        vector<Pos> get_legal_moves()
        {
            vector<Pos> moves;
            return moves;
        }

    private:
        int row;
        int col;
        Type type = UNASSIGNED;
};

class Pawn : public Piece
{
    public:
        using Piece::Piece;
    private:
        Type type = PAWN;
};

int main()
{
    Pawn pawn(1,2);

    return 0;
}