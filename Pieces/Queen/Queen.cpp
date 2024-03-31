#include "Queen.h"

// Constructor
Queen::Queen(int color) : Piece("Queen", color) {}

// Destructor
Queen::~Queen() {}


bool Queen::validateMove(std::pair<int, int> new_position) {

    int row_diff = abs(new_position.first - position.first);
    int col_diff = abs(new_position.second - position.second);

    if(row_diff==col_diff)return true;


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

    return false;
}