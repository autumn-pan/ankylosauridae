#include "types.h"

int get_material(Type type)
{
    switch(type)
    {
        case PAWN: return 1;
        case BISHOP: return 3;
        case KNIGHT: return 3;
        case ROOK: return 5;
        case QUEEN: return 9;
        case KING: return 100000;
        default: return 0;
    }
}