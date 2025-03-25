#ifndef TYPES_H
#define TYPES_H
typedef enum {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    EMPTY,
    UNASSIGNED
} Type;

int get_material(Type type);
#endif