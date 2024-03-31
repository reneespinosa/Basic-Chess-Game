#include "Piece.h"

// Constructor
Piece::Piece(string type, int color) : type(type), color(color) {}

// Destructor
Piece::~Piece() {}

// Métodos Get para acceder a los atributos

string Piece::getType() {
    return type;
}

int Piece::getColor() {
    return color;
}

pair<int, int> Piece::getPosition() {
    return position;
}

void Piece::setPosition(pair<int, int> new_position) {
    position = new_position;
}

void Piece::setType(string new_type) {
    type = new_type;
}

void Piece::setColor(int new_color) {
    color = new_color;
}


