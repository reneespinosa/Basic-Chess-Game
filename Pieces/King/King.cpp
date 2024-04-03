#include "King.h"

// Constructor
King::King(int color) : Piece("King", color), moved(false) {}

// Destructor
King::~King() {}

bool King::validateMove(pair<int, int> new_position) {
    // Calculamos la diferencia en filas y columnas entre la posición actual y la nueva posición
    int row_diff = abs(new_position.first - position.first);
    int col_diff = abs(new_position.second - position.second);

    // Verificamos si el movimiento es válido para el rey (una casilla en cualquier dirección)
    if ((row_diff <= 1) && (col_diff <= 1)) {
        // El movimiento es válido para el rey
        return true;
    }

        // El movimiento no es válido para el rey
        return false;
}

bool King::getMoved() {
    return moved;
}

void King::setMoved(bool moved_status) {
    moved = moved_status;
}

string King::getSymbol() {
    return (color == 0) ? "♚" : "♔";
}