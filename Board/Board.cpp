#include "Board.h"

Board::Board() {
    // Inicializar el tablero con un tamaño estándar de 8x8
    board.resize(8, std::vector<Piece*>(8, nullptr));

    // Inicializar las piezas blancas
    board[0][0] = new Rook(1);
    board[0][1] = new Knight(1);
    board[0][2] = new Bishop(1);
    board[0][3] = new Queen(1);
    board[0][4] = new King(1);
    board[0][5] = new Bishop(1);
    board[0][6] = new Knight(1);
    board[0][7] = new Rook(1);

    for (int col = 0; col < 8; col++) {
        board[1][col] = new Pawn(1);
    }

    // Inicializar las piezas negras
    board[7][0] = new Rook(2);
    board[7][1] = new Knight(2);
    board[7][2] = new Bishop(2);
    board[7][3] = new Queen(2);
    board[7][4] = new King(2);
    board[7][5] = new Bishop(2);
    board[7][6] = new Knight(2);
    board[7][7] = new Rook(2);

    for (int col = 0; col < 8; col++) {
        board[6][col] = new Pawn(2);
    }
}

// Destructor
Board::~Board() {
    // Liberar la memoria de las piezas en el tablero
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] != nullptr) {
                delete board[i][j];
                board[i][j] = nullptr;
            }
        }
    }
}


#include "Board.h"


void Board::print() {
    // Imprimir las coordenadas superiores del tablero
    cout << "   a b c d e f g h" << endl;
    cout << "  ------------------" << endl;

    // Imprimir el tablero con las piezas, las coordenadas laterales y numéricas
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " |"; // Imprimir coordenada vertical
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == nullptr) {
                cout << "  "; // Casilla vacía
            } else {
                cout << board[i][j]->getSymbol() << " "; // Casilla con pieza
            }
        }
        cout << "| " << 8 - i << endl; // Separador lateral del tablero y coordenada vertical
    }

    // Imprimir línea inferior del tablero con las coordenadas inferiores
    cout << "  ------------------" << endl;
    cout << "   a b c d e f g h" << endl;
}


