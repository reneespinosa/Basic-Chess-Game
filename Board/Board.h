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
    void print(bool isBlackPerspective) ;

    // Método para obtener la pieza en una posición específica del tablero
    Piece* getPieceAt(int row ,int col);



    bool checkPathClear(pair<int, int> start, pair<int, int> end);

    bool canMoveToSquare(pair<int, int> position, int color);

    bool isValidMove(pair<int, int> start, pair<int, int> end, int color);

    void promotePawn(pair<int, int> position, int newPieceType, int color);

    void movePiece(pair<int, int> start, pair<int, int> end, int color);

    pair<int, int> getKingPosition(int color);

    Board(const Board& other);
    Board& operator=(const Board& other);

    Board* clone();

};

#endif // BOARD_H