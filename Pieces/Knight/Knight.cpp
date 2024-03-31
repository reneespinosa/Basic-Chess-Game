#include "Knight.h"

// Constructor
Knight::Knight(int color) : Piece("Knight", color) {}

// Destructor
Knight::~Knight() {}

bool Knight::validateMove(pair<int, int> new_position) {
    // Obtener la posición actual del caballo
    auto current_position = getPosition();

    // Calcular la diferencia en filas y columnas entre la posición actual y la nueva posición
    int row_diff = abs(new_position.first - current_position.first);
    int col_diff = abs(new_position.second - current_position.second);

    // Verificar si el movimiento sigue las reglas del caballo en forma de L
    if ((row_diff == 1 && col_diff == 2) || (row_diff == 2 && col_diff == 1)) {
        // El movimiento es válido para el caballo
        return true;
    }

        // El movimiento no es válido para el caballo
        return false;

}


string Knight::getSymbol()
{
    return (color == 1) ? "♞" : "♘";
}
