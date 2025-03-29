#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "pieces.h"
using namespace std;
class Player
{
    public:
        bool white;
        Player(bool white);
        vector<Piece*> pieces;
        int material;
        int calculate_material(Board * board);
};
#endif