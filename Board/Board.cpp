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


void Board::print(bool isBlackPerspective) {
    // Imprimir las coordenadas superiores del tablero
    if (!isBlackPerspective) {
        cout << "   a b c d e f g h" << endl;
    }
    else {
        cout << "   a b c d e f g h" << endl;
    }
    cout << "  ------------------" << endl;

    // Imprimir el tablero con las piezas y las coordenadas laterales
    if (!isBlackPerspective) {
        for (int i = 7; i >= 0; --i) {
            cout << i + 1 << " |"; // Imprimir coordenada vertical
            for (int j = 7; j >= 0; --j) { // Cambiar el orden de las columnas
                if (board[i][j] == nullptr) {
                    cout << "  "; // Casilla vacía
                } else {
                    cout << board[i][j]->getSymbol() << " "; // Casilla con pieza
                }
            }
            cout << "| " << i + 1 << endl; // Separador lateral del tablero y coordenada vertical
        }
    }
    else {
        for (int i = 0; i < 8; ++i) { // Cambiar el orden de las filas
            cout << i + 1 << " |"; // Imprimir coordenada vertical
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == nullptr) {
                    cout << "  "; // Casilla vacía
                } else {
                    cout << board[i][j]->getSymbol() << " "; // Casilla con pieza
                }
            }
            cout << "| " << i + 1 << endl; // Separador lateral del tablero y coordenada vertical
        }
    }

    // Imprimir línea inferior del tablero con las coordenadas inferiores
    if (!isBlackPerspective) {
        cout << "  ------------------" << endl;
        cout << "   a b c d e f g h" << endl;
    } else {
        cout << "  ------------------" << endl;
        cout << "   a b c d e f g h" << endl;
    }
}






Piece* Board::getPieceAt(int row, int col) {
    // Verificar si las coordenadas están dentro de los límites del tablero
    if (row < 0 || row >= 8 || col < 0 || col >= 8) {
        // Coordenadas fuera de los límites del tablero
        return nullptr;
    }

    // Devolver la pieza en las coordenadas especificadas
    return board[row][col];
}


bool Board::checkPathClear(pair<int, int> start, pair<int, int> end) {
    // Obtener la pieza en la posición de inicio
    Piece* piece = board[start.first][start.second];

    // Verificar si hay una pieza en la posición de destino
    if (board[end.first][end.second] != nullptr) {
        return false; // El camino no está despejado si hay una pieza en la posición de destino
    }

    // Verificar el tipo de pieza y validar el movimiento
    if (piece != nullptr) {
        // Validar el movimiento dependiendo del tipo de pieza
        string pieceType = piece->getType();
        if (pieceType == "Pawn") {
           return true;
        }


        else if (pieceType == "Rook") {


            // Verificar si el movimiento es válido para la torre
            if (start.first == end.first || start.second == end.second) {
                // El movimiento es válido para la torre, por lo que el camino está despejado
                if (start.first == end.first) {
                    // Movimiento vertical
                    int step = (start.second < end.second) ? 1 : -1;
                    int j = start.second + step;
                    while (j != end.second) {
                        if (board[start.first][j] != nullptr) {
                            // Hay una pieza en el camino, por lo que el camino no está despejado
                            return false;
                        }
                        j += step;
                    }
                } else {
                    // Movimiento horizontal
                    int step = (start.first < end.first) ? 1 : -1;
                    int i = start.first + step;
                    while (i != end.first) {
                        if (board[i][start.second] != nullptr) {
                            // Hay una pieza en el camino, por lo que el camino no está despejado
                            return false;
                        }
                        i += step;
                    }
                }
                // No hay piezas en el camino, por lo que el camino está despejado
                return true;
            } else {
                // El movimiento no es válido para la torre, por lo que el camino no está despejado
                return false;
            }



        }

        else if (pieceType == "Knight") {
            return true;

        }



        else if (pieceType == "Bishop") {
            // Verificar si el movimiento es diagonal
            int rowDiff = abs(end.first - start.first);
            int colDiff = abs(end.second - start.second);

            if (rowDiff == colDiff) {
                // Determinar la dirección del movimiento diagonal
                int rowDir = (end.first > start.first) ? 1 : -1;
                int colDir = (end.second > start.second) ? 1 : -1;

                // Verificar si hay piezas en el camino diagonal
                for (int i = start.first + rowDir, j = start.second + colDir;
                     i != end.first; i += rowDir, j += colDir) {
                    if (board[i][j] != nullptr) {
                        // Hay una pieza en el camino, por lo que el camino no está despejado
                        return false;
                    }
                }

                // No hay piezas en el camino diagonal
                return true;
            } else {
                // El movimiento no es diagonal, por lo que el camino no está despejado
                return false;
            }
        } else {
            if (pieceType == "Queen") {


                // Implementar lógica para la reina (dama)
                int row_diff = abs(start.first - end.first);
                int col_diff = abs(start.second - end.second);

                // Verificar movimiento horizontal
                if (start.first == end.first) {
                    int min_col = min(start.second, end.second);
                    int max_col = max(start.second, end.second);
                    for (int j = min_col + 1; j < max_col; ++j) {
                        if (board[start.first][j] != nullptr) {
                            return false; // Hay una pieza obstruyendo el camino
                        }
                    }
                    return true;
                }

                // Verificar movimiento vertical
                if (start.second == end.second) {
                    int min_row = min(start.first, end.first);
                    int max_row = max(start.first, end.first);
                    for (int i = min_row + 1; i < max_row; ++i) {
                        if (board[i][start.second] != nullptr) {
                            return false; // Hay una pieza obstruyendo el camino
                        }
                    }
                    return true;
                }

                // Verificar movimiento diagonal
                if (row_diff == col_diff) {
                    int min_row = min(start.first, end.first);
                    int max_row = max(start.first, end.first);
                    int min_col = min(start.second, end.second);
                    int max_col = max(start.second, end.second);
                    for (int i = min_row + 1, j = min_col + 1; i < max_row; ++i, ++j) {
                        if (board[i][j] != nullptr) {
                            return false; // Hay una pieza obstruyendo el camino
                        }
                    }
                    return true;
                }


            } else if (pieceType == "King") {
                return true;
            }
        }
    }

    // Si no se encuentra ninguna pieza en la posición de inicio,
    // o si la pieza no es un tipo conocido, asumimos que el camino está despejado
    return true;
}


bool Board::canMoveToSquare(pair<int, int> position, int color) {
    // Verificar si la posición está dentro del tablero
    if (position.first < 0 || position.first >= 8 || position.second < 0 || position.second >= 8) {
        return false; // La posición está fuera del tablero
    }

    // Verificar si la casilla está ocupada por una pieza del mismo color
    Piece* piece = getPieceAt(position.first, position.second);
    if (piece != nullptr && piece->getColor() == color) {
        return false; // La casilla está ocupada por una pieza del mismo color
    }

    // Verificar movimiento especial para el peón
    if (piece != nullptr && piece->getType() == "Pawn") {
        // El peón solo puede moverse una casilla hacia adelante si la casilla está vacía
        if (color == 1) { // Si es un peón blanco
            return (getPieceAt(position.first - 1, position.second) == nullptr);
        } else { // Si es un peón negro
            return (getPieceAt(position.first + 1, position.second) == nullptr);
        }
    }

    return true; // La casilla está vacía o ocupada por una pieza de otro color
}

bool Board::isValidMove(pair<int, int> start, pair<int, int> end, int color) {
    // Verificar si la posición de inicio está dentro del tablero
    if (start.first < 0 || start.first >= 8 || start.second < 0 || start.second >= 8) {
        return false; // La posición de inicio está fuera del tablero
    }

    if(!canMoveToSquare(end,color))
    {
        return false;
    }


    // Verificar si el movimiento es válido según la pieza
    auto* piece = getPieceAt(start.first,start.second);

    if (!piece->validateMove(end)) {
        return false; // El movimiento no es válido según las reglas de la pieza
    }


    // Verificar si el camino está despejado para el movimiento
    if (!checkPathClear(start, end)) {
        return false; // El camino no está despejado para el movimiento
    }

    // Si todas las condiciones anteriores se cumplen, el movimiento es válido
    return true;
}

void Board::promotePawn(pair<int, int> position, int newPieceType, int color) {
    // Eliminar el peón de la posición actual
    delete board[position.first][position.second];

    // Crear la nueva pieza según el tipo especificado
    Piece* newPiece = nullptr;
    switch (newPieceType) {
        case 1:
            newPiece = new Queen(color);
            break;
        case 2:
            newPiece = new Rook(color);
            // Verificar si la nueva pieza es una torre y establecer su estado coronado
            if (auto rook = dynamic_cast<Rook*>(newPiece)) {
                rook->setCrowned(true);
            } else {
                cerr << "Error: la nueva pieza no es una torre." << endl;
                return;
            }
            break;
        case 3:
            newPiece = new Bishop(color);
            break;
        case 4:
            newPiece = new Knight(color);
            break;
        default:
            cerr << "Tipo de pieza no válido para la coronación del peón." << endl;
            return;
    }

    // Colocar la nueva pieza en la posición del peón
    board[position.first][position.second] = newPiece;
}


bool Board::movePiece(pair<int, int> start, pair<int, int> end, int color) {
    // Verificar si el movimiento es válido
    if (!isValidMove(start, end, color)) {
        return false; // El movimiento no es válido
    }

    // Obtener la pieza en la posición de inicio
    Piece* piece = getPieceAt(start.first, start.second);

    // Mover la pieza a la posición de destino
    board[end.first][end.second] = piece;
    board[start.first][start.second] = nullptr;

    // Actualizar la posición de la pieza
    piece->setPosition(end);

    // Verificar si el peón alcanzó el extremo opuesto del tablero
    if (piece->getType() == "Pawn" && (end.first == 0 || end.first == 7)) {
        // Llamar al método PromotePawn para promover el peón
        int opt=-1;
        do{
            cout<<"Promote a Pawn (Select a number) : "
                  "\n 1. Queen "
                  "\n 2. Rook "
                  "\n 3. Bishop "
                  "\n 4. Knight \n";

            cin>>opt;
            if(opt<=0&&opt>4)
            {
                cout<<"Incorrect number.Try again\n";
            }
        }while(opt<=0&&opt>4);

        promotePawn(end,opt, color);
    }


    return true; // El movimiento fue exitoso
}




