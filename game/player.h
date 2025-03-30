#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "pieces.h"
using namespace std;
class Player
{
    public:
        Player(Color color);
        Color color;
        vector<Piece*> pieces;
        int material;
        
        int calculate_material();
        void add_piece(Piece * piece);
};

class Game
{
    public:
        Game(Board * board);
        Board * board;
        Player*  white;
        Player*  black;
        
        Color turn;

        void add(Piece * piece);
};
#endif