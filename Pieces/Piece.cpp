#include "Piece.h"


Piece::Piece(string type, int color) : type(type), color(color) {}


// Destructor virtual
Piece::~Piece() {}

// Método virtual para mover la pieza

void Piece::move (pair<int, int> new_position) {
    position.first = new_position.first;
    position.second = new_position.second;
}


// Métodos Get para acceder a los atributos

string Piece::getType()
{
    return type;
}

int Piece::getColor()
{
    return color;
}

pair<int,int> Piece::getPosition()
{
    return position;
}