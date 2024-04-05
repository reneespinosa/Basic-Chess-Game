#include "Piece.h"

// Constructor
Piece::Piece(string type, int color) : type(type), color(color) {}

// Destructor
Piece::~Piece() {}

// Constructor de copia
Piece::Piece(const Piece& other) : type(other.type), color(other.color), position(other.position) {}

/*
Piece& Piece::operator=(const Piece& other) {
    if (this != &other) {
        type = other.type;
        color = other.color;
        position = other.position;
    }
    return *this;
}
*/

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


