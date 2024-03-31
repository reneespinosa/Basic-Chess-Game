#include "Pawn.h"

Pawn::Pawn(int color) : Piece("Pawn", color) {}

Pawn::~Pawn() {}

bool Pawn::validateMove(pair<int, int> new_position) {

    int new_row = new_position.first;
    int new_col = new_position.second;

    // Obtener la posición actual del peón
    int current_row = getPosition().first;
    int current_col = getPosition().second;

    // Determinar la dirección del movimiento según el color del peón
    int direction = (color == 1) ? 1 : -1;

    // Validar movimiento hacia adelante (una casilla)
    if (new_col == current_col && new_row == current_row + direction) {
        return true;
    }

    // Validar movimiento de dos casillas en el primer paso
    if (current_row == (color == 1 ? 1 : 6) && new_col == current_col && new_row == current_row + 2 * direction) {
        return true;
    }

    // Validar captura en diagonal
    if (abs(new_col - current_col) == 1 && new_row == current_row + direction) {
        return true;
    }

    // Si no cumple ninguna de las condiciones anteriores, el movimiento es inválido
    return false;
}

string Pawn::getSymbol() {
    return (color == 1) ? "♟" : "♙";
}