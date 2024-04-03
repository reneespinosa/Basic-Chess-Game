#include "Board.h"

Board::Board() {
    // Inicializar el tablero con un tamaño estándar de 8x8
    board.resize(8, vector<Piece*>(8, nullptr));

    // Inicializar las piezas blancas
    board[0][0] = new Rook(0);
    board[0][0]->setPosition({0, 0});
    board[0][1] = new Knight(0);
    board[0][1]->setPosition({0, 1});
    board[0][2] = new Bishop(0);
    board[0][2]->setPosition({0, 2});
    board[0][3] = new Queen(0);
    board[0][3]->setPosition({0, 3});
    board[0][4] = new King(0);
    board[0][4]->setPosition({0, 4});
    board[0][5] = new Bishop(0);
    board[0][5]->setPosition({0, 5});
    board[0][6] = new Knight(0);
    board[0][6]->setPosition({0, 6});
    board[0][7] = new Rook(0);
    board[0][7]->setPosition({0, 7});

    for (int col = 0; col < 8; col++) {
        board[1][col] = new Pawn(0);
        board[1][col]->setPosition({1, col});
    }

    // Inicializar las piezas negras
    board[7][0] = new Rook(1);
    board[7][0]->setPosition({7, 0});
    board[7][1] = new Knight(1);
    board[7][1]->setPosition({7, 1});
    board[7][2] = new Bishop(1);
    board[7][2]->setPosition({7, 2});
    board[7][3] = new Queen(1);
    board[7][3]->setPosition({7, 3});
    board[7][4] = new King(1);
    board[7][4]->setPosition({7, 4});
    board[7][5] = new Bishop(1);
    board[7][5]->setPosition({7, 5});
    board[7][6] = new Knight(1);
    board[7][6]->setPosition({7, 6});
    board[7][7] = new Rook(1);
    board[7][7]->setPosition({7, 7});

    for (int col = 0; col < 8; col++) {
        board[6][col] = new Pawn(1);
        board[6][col]->setPosition({6, col});
    }
}

// Destructor
Board::~Board() {
    // Implementación del destructor
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            delete board[i][j];
            board[i][j] = nullptr;
        }
    }
}

// Operador de asignación


Board& Board::operator=(const Board& other) {
    if (this != &other) {
        // Limpiar el tablero actual
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                delete board[i][j];
            }
        }

        // Copiar el tablero de other al tablero actual
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (other.board[i][j] != nullptr) {
                    if (other.board[i][j]->getType() == "Pawn") {
                        this->board[i][j] = new Pawn(*dynamic_cast<Pawn*>(other.board[i][j]));
                    } else if (other.board[i][j]->getType() == "Rook") {
                        this->board[i][j] = new Rook(*dynamic_cast<Rook*>(other.board[i][j]));
                    } else if (other.board[i][j]->getType() == "Knight") {
                        this->board[i][j] = new Knight(*dynamic_cast<Knight*>(other.board[i][j]));
                    } else if (other.board[i][j]->getType() == "Bishop") {
                        this->board[i][j] = new Bishop(*dynamic_cast<Bishop*>(other.board[i][j]));
                    } else if (other.board[i][j]->getType() == "Queen") {
                        this->board[i][j] = new Queen(*dynamic_cast<Queen*>(other.board[i][j]));
                    } else if (other.board[i][j]->getType() == "King") {
                        this->board[i][j] = new King(*dynamic_cast<King*>(other.board[i][j]));
                    }
                } else {
                    this->board[i][j] = nullptr;
                }
            }
        }
    }
    return *this;
}

Board::Board(const Board& other) {
    // Realizar una copia profunda del tablero desde other al nuevo tablero
    *this = other; // Esto asume que el tipo de datos utilizado para almacenar el tablero admite copia profunda (por ejemplo, un vector de vectores)
}


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
            for (int j = 0; j <= 7; ++j) { // Cambiar el orden de las columnas
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
        return false;
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
    if(piece== nullptr)
        return true;

    if (piece != nullptr && piece->getColor() == color) {
        return false; // La casilla está ocupada por una pieza del mismo color
    }

    return true; // La casilla está vacía o ocupada por una pieza de otro color
}

bool Board::isValidMove(pair<int, int> start, pair<int, int> end, int color) {
    // Verificar si la posición de inicio está dentro del tablero
    if (start.first < 0 || start.first >= 8 || start.second < 0 || start.second >= 8) {
        return false; // La posición de inicio está fuera del tablero
    }

    if(!canMoveToSquare(end,color ))
    {
        return false;
    }


    //cout<<"PATHCLEAR "<<(checkPathClear(start, end))<<endl;



    // Verificar si el camino está despejado para el movimiento
    if (!checkPathClear(start, end)) {
        return false; // El camino no está despejado para el movimiento
    }

    int direction = (color==0)? 1:-1;

    auto* piece = getPieceAt(start.first,start.second);
    auto* ppiece = getPieceAt(end.first,end.second);

    if (piece != nullptr && piece->getType() == "Pawn") {
        // El peón solo puede moverse una casilla hacia adelante si la casilla está vacía
        if(ppiece != nullptr && end.first == start.first+direction && end.second==start.second)
        {
            return  false;
        }
    }


    if(piece->getType()=="Pawn"&&abs(end.second - start.second) == 1 && end.first == start.first + direction)
    {
        auto* piece2 = getPieceAt(end.first,end.second);
        if(piece2 == nullptr)return false;
        else return true;
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
    newPiece->setPosition(position);
}


void Board::movePiece(pair<int, int> start, pair<int, int> end, int color ) {
    // Verificar si el movimiento es válido

    // Obtener la pieza en la posición de inicio
    Piece* piece = getPieceAt(start.first, start.second);

    if(piece== nullptr)
    {
        cout<<"Invalid move.Try again\n";
        return;
    }


    // Mover la pieza a la posición de destino
    board[end.first][end.second] = piece;
    board[start.first][start.second] = nullptr;

    // Actualizar la posición de la pieza
    piece->setPosition(end);
    if (piece->getType() == "Rook") {
        dynamic_cast<Rook*>(piece)->setMoved(true);
    }
    if (piece->getType() == "King") {
        dynamic_cast<King*>(piece)->setMoved(true);
    }

    // Verificar si el peón alcanzó el extremo opuesto del tablero
    if (piece->getType() == "Pawn" && (end.first == 0 || end.first == 7)) {
        // Llamar al método PromotePawn para promover el peón
        int opt=-1;
        do{
            if(opt<=0&&opt>4){
            cout<<"Promote a Pawn (Select a number) : "
                  "\n 1. Queen "
                  "\n 2. Rook "
                  "\n 3. Bishop "
                  "\n 4. Knight \n";
            }
            cin>>opt;
            if(opt<=0&&opt>4)
            {
                cout<<"Incorrect number.Try again\n";
            }
        }while(opt<=0&&opt>4);

        promotePawn(end,opt, color);
    }


    return ; // El movimiento fue exitoso
}

pair<int, int> Board::getKingPosition(int color) {
    // Recorrer el tablero para encontrar la posición del rey del color especificado
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = board[i][j];
            if (piece != nullptr && piece->getType() == "King" && piece->getColor() == color) {
                return make_pair(i, j);
            }
        }
    }
    // Si no se encuentra el rey, devolver una posición inválida (-1, -1)
    return make_pair(-1, -1);
}

Board* Board::clone() {
    // Crear una nueva instancia de Board
    Board* newBoard = new Board();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] != nullptr) {
                // Clonar la pieza actual en la posición [i][j]
                Piece* clonedPiece = nullptr;
                if (board[i][j]->getType() == "Pawn") {
                    clonedPiece = new Pawn(*dynamic_cast<Pawn*>(board[i][j]));
                } else if (board[i][j]->getType() == "Rook") {
                    clonedPiece = new Rook(*dynamic_cast<Rook*>(board[i][j]));
                } else if (board[i][j]->getType() == "Knight") {
                    clonedPiece = new Knight(*dynamic_cast<Knight*>(board[i][j]));
                } else if (board[i][j]->getType() == "Bishop") {
                    clonedPiece = new Bishop(*dynamic_cast<Bishop*>(board[i][j]));
                } else if (board[i][j]->getType() == "Queen") {
                    clonedPiece = new Queen(*dynamic_cast<Queen*>(board[i][j]));
                } else if (board[i][j]->getType() == "King") {
                    clonedPiece = new King(*dynamic_cast<King*>(board[i][j]));
                }
                // Asignar la pieza clonada a la nueva posición en el tablero
                newBoard->board[i][j] = clonedPiece;
            } else {
                newBoard->board[i][j] = nullptr;
            }
        }
    }

    return newBoard;
}
