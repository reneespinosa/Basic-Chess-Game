#include "Rook.h"

// Constructor
Rook::Rook(int color, bool is_crowned) : Piece("Rook", color), moved(false), crowned(is_crowned) {}

// Destructor
Rook::~Rook() {}

bool Rook::getMoved()  {
    return moved;
}

bool Rook::getCrowned() {
    return crowned;
}

void Rook::setMoved(bool has_moved)  {
    moved = has_moved;
}

void Rook::setCrowned(bool is_crowned)
{
    crowned = is_crowned;
}

bool Rook::canCastle(){
    return (!getMoved()&&!getCrowned());
}


bool Rook::validateMove(pair<int, int> new_position){

    int new_row = new_position.first;
    int new_col = new_position.second;

    // Obtener la posición actual de la torre
    int current_row = getPosition().first;
    int current_col = getPosition().second;

    // Validar movimiento horizontal
    if (new_row == current_row && new_col != current_col) {
        return true;
    }

    // Validar movimiento vertical
    if (new_col == current_col && new_row != current_row) {
        return true;
    }

    // Si no cumple ninguna de las condiciones anteriores, el movimiento es inválido
    return false;
}

string Rook::getSymbol()
{
    return (color == 0) ?     "♜" : "♖";

}