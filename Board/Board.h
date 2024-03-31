#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utility>
#include <iostream>
#include <iomanip>


#include "../Pieces/Pawn/Pawn.h"
#include "../Pieces/Rook/Rook.h"
#include "../Pieces/Knight/Knight.h"
#include "../Pieces/Bishop/Bishop.h"
#include "../Pieces/Queen/Queen.h"
#include "../Pieces/King/King.h"

using namespace std;

class Board {
private:
    vector<vector<Piece*>> board; // Tablero de juego

public:
    // Constructor
    Board();

    // Destructor
    ~Board();

    // Método para imprimir el tablero de juego en consola
    void print() ;

    // Método para mover una pieza en el tablero
    bool movePiece(const std::pair<int, int>& from, const std::pair<int, int>& to);

    // Método para obtener la pieza en una posición específica del tablero
    Piece* getPieceAt(const std::pair<int, int>& position) const;
};

#endif // BOARD_H