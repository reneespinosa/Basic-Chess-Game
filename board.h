#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utility>
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

class Board {
private:
    std::vector<std::vector<Piece*>> board; // Tablero de juego

public:
    // Constructor
    Board();

    // Destructor
    ~Board();

    // Método para imprimir el tablero de juego en consola
    void print() const;

    // Método para mover una pieza en el tablero
    bool movePiece(const std::pair<int, int>& from, const std::pair<int, int>& to);

    // Método para obtener la pieza en una posición específica del tablero
    Piece* getPieceAt(const std::pair<int, int>& position) const;
};

#endif // BOARD_H
