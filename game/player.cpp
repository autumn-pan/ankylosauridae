#include "player.h"
#include "pieces.h"
#include <algorithm>

Player::Player(Color color)
{
    this->color = color;
    this->material = 0;
}

int Player::calculate_material()
{
    int sum = 0;
    for(Piece * piece : pieces)
    {
        sum += get_material(piece->type);
    }
    return sum;
}

void Player::add_piece(Piece *piece)
{
    this->pieces.push_back(piece);
}

Game::Game(Board * board)
{
    this->board = board;
    this->turn = WHITE;
    this->white = new Player(WHITE);
    this->black = new Player(BLACK);
}

void Game::add(Piece * piece)
{
    if(piece->color == WHITE) 
        this->white->add_piece(piece);
    else
        this->black->add_piece(piece);
}

void Player::pop_piece(Piece * piece)
{
    auto i = std::find(this->pieces.begin(), this->pieces.end(), piece);

    if (i != this->pieces.end()) {
        this->pieces.erase(i);
    }
}

Piece * get_piece_from_pos(Player * player, Pos pos)
{

    for (Piece * piece : player->pieces)
    {
        if(piece->row == pos.row && piece->col == pos.col)
            return piece;
    }
    return NULL;
}