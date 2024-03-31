#include "Bishop.h"

// Constructor
Bishop::Bishop(int color) : Piece("Bishop", color) {}

// Destructor
Bishop::~Bishop() {}

bool Bishop::validateMove(pair<int, int> new_position) {
    // Implementación de la validación del movimiento del alfil
    int row_diff = abs(new_position.first - position.first);
    int col_diff = abs(new_position.second - position.second);
    return row_diff == col_diff; // El movimiento es válido si la diferencia entre filas y columnas es la misma
}
