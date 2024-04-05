#include "Game.h"

Game::Game(string player1Name, string player2Name)
        : board(new Board()), players{Player(player1Name, 0), Player(player2Name, 1)}, currentPlayer(0), gameOver(false), moveCount(0),Pawn_enPassantable(
        make_pair(-1,-1)) {
    // Inicializar los jugadores
    players[0] = Player(player1Name, 0);
    players[1] = Player(player2Name, 1);
}

Game::~Game() = default;

bool Game::isInsufficientMaterial() {
    // Contadores para el número de piezas de cada color y tipo
    map<int, map< string, int> > pieceCount;

    // Inicializar los mapas con cero
    for (int color = 0; color <= 1; color++) { // Iterar sobre blancas (1) y negras (-1)
        for (const string& pieceType : {"Pawn", "Knight", "Bishop", "Rook", "Queen"}) {
            pieceCount[color][pieceType] = 0;
        }
    }

    // Recorrer el tablero para contar las piezas de cada color y tipo
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = board->getPieceAt(i, j);
            if (piece != nullptr && piece->getType() != "King") {
                int color = piece->getColor();
                string type = piece->getType();
                pieceCount[color][type]++;
            }
        }
    }

    int totalPieces = 0;
    // Verificar las condiciones de empate por insuficiencia de material
    for (int color = 0; color <=1; color++) { // Iterar sobre blancas (1) y negras (-1)
        // Obtener la cantidad total de piezas del color actual

        for (const auto &pair: pieceCount[color]) {
            totalPieces += pair.second;
        }
    }

        // Verificar condiciones específicas de empate
        if (totalPieces == 0) {
            return true; // No hay suficientes piezas para continuar el juego
        }
        if (totalPieces == 1) {

            if(pieceCount[0]["Knight"]==1||pieceCount[0]["Bishop"]==1||pieceCount[1]["Knight"]==1||pieceCount[1]["Bishop"]==1)
                return true;
        }

        if (totalPieces == 2) {
            // Rey y caballo o alfil contra rey: Empate si no hay otros tipos de piezas
            if( (pieceCount[0]["Knight"]==1
            &&pieceCount[0]["Bishop"]==1)
            || (pieceCount[1]["Knight"]==1&&pieceCount[1]["Bishop"]==1))
            {
                return true;
            }

            if (pieceCount[0]["Knight"] == 2 || pieceCount[1]["King"] == 1) {
                return true;
            }
        }


    return false; // No hay insuficiencia de material
}


bool Game::isCheck( Board* boar) {
    // Recorrer el tablero para verificar si alguna pieza del oponente puede atacar al rey
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = boar->getPieceAt(i, j);


            if (piece != nullptr && piece->getColor() != currentPlayer) {
                // Verificar si la pieza puede moverse a la posición del rey
                pair<int, int> piecePosition = make_pair(i, j);


                if (piece->validateMove(boar->getKingPosition(currentPlayer)) && boar->isValidMove(piecePosition, boar->getKingPosition(currentPlayer), (currentPlayer+1)%2  )) {
                    return true; // El rey está en jaque
                }
            }
        }
    }

    return false; // El rey no está en jaque
}




bool Game::isStalemate(int playerColor) {
    // Verificar si el rey del jugador está en jaque

    if (isCheck(board)) {
        return false; // El rey está en jaque, no es un empate por ahogado
    }

    // Comprobar si el jugador tiene alguna jugada legal disponible
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = board->getPieceAt(i, j);
            if (piece != nullptr && piece->getColor() == playerColor) {
                pair<int, int> piecePosition = make_pair(i, j);
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        pair<int, int> newPosition = make_pair(x, y);
                        if (isValidMove(piecePosition, newPosition, playerColor)) {
                            // Realizar una copia del tablero y simular el movimiento
                            Board * copyBoard = board->clone();
                            copyBoard->movePiece(piecePosition, newPosition, playerColor);

                            // Verificar si el rey del jugador está en jaque después del movimiento simulado
                            if (!isCheck(copyBoard)) {
                                return false; // El jugador tiene al menos un movimiento legal que evita el ahogado
                            }
                        }
                    }
                }
            }
        }
    }

    return true; // No hay movimientos legales disponibles para el jugador, es un empate por ahogado
}

bool Game::isDraw() {
    // Verificar empate por insuficiencia de material
    if (isInsufficientMaterial()) {
        return true;
    }

    // Verificar empate por regla de los 50 movimientos sin captura ni avance de peón
    if (moveCount >= 100) {
        return true; // Aquí el límite sería 100 movimientos, ya que cada movimiento cuenta para ambos jugadores
    }

    // Verificar empate por repetición de posiciones
    /*if(history_of_board[board][players[currentPlayer].getColor()]==3)
    {
        return true;
    }*/

    if(isStalemate(players[currentPlayer].getColor()))return true;


    return false; // No se cumplió ninguna condición de empate
}

void Game::switchTurn() {
    currentPlayer ++;
    currentPlayer%=2;
}

bool Game::isCheckmate(int playerColor) {
    // Verificar si el rey del jugador está en jaque
    pair<int, int> kingPosition = board->getKingPosition(playerColor);
    if (!isCheck(board) ){
        return false; // El rey no está en jaque, por lo que no es jaque mate
    }

    // Comprobar si el jugador tiene alguna jugada legal disponible para evitar el jaque mate
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = board->getPieceAt(i, j);
            if (piece != nullptr && piece->getColor() == playerColor) {
                pair<int, int> piecePosition = make_pair(i, j);
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        pair<int, int> newPosition = make_pair(x, y);
                        if (isValidMove(piecePosition, newPosition, playerColor )) {
                            // Realizar una copia del tablero y simular el movimiento
                            Board* copyBoard = board->clone();
                            copyBoard->movePiece(piecePosition, newPosition, playerColor);

                            // Verificar si el rey del jugador sigue estando en jaque después del movimiento simulado
                            pair<int, int> kingPosAfterMove = (playerColor == 0) ? copyBoard->getKingPosition(0) : copyBoard->getKingPosition(1);
                            if (!isCheck(copyBoard)) {
                                return false; // El jugador tiene al menos un movimiento legal que evita el jaque mate
                            }
                        }
                    }
                }
            }
        }
    }

    return true; // No hay movimientos legales disponibles para el jugador, es jaque mate
}


bool Game::isValidMove(pair<int, int> start,pair<int, int> end, int color) {
    // Verificar si la posición de inicio está dentro del tablero

    // Obtener la pieza en la posición de inicio
    Piece* piece = board->getPieceAt(start.first, start.second);

    //cout<<"PIECE NULL "<<(piece==nullptr)<<endl;


    if(piece==nullptr)
    {
        return false;
    }

   // cout<<"PIECE OTHERCOLOR "<<(piece->getColor() != color)<<endl;



    // Verificar si la pieza en la posición de inicio pertenece al jugador actual
    if (piece->getColor() != color) {
        return false; // La pieza en la posición de inicio no pertenece al jugador actual
    }

   // cout<<"PIECE VALID "<<(piece->validateMove(end))<<endl;


    // Verificar si el movimiento es válido según las reglas de la pieza
    if (!piece->validateMove(end)) {
        return false; // El movimiento no es válido según las reglas de la pieza
    }

   // cout<<"BOARD VALID "<<(board->isValidMove(start, end, color))<<endl;



    // Verificar si el camino está despejado para el movimiento
    if (!board->isValidMove(start, end, color)) {
        return false; // El camino no está despejado para el movimiento
    }

    // Verificar si el movimiento pone al rey en jaque


    Board* tempBoard = board->clone();

    tempBoard->movePiece(start, end, color); // Simular el movimiento en el tablero temporal

    //cout<<"IS CHECK : "<<(isCheck(tempBoard))<<endl;


    if (isCheck(tempBoard) ){
        return false; // El movimiento pone al rey en jaque
    }

    // Si todas las verificaciones pasan, el movimiento es válido
    return true;
}

bool Game::processMove( pair<char, int> start,  pair<char, int> end) {
    // Convertir las coordenadas de inicio y fin en índices de matriz



    int startRow = start.second - 1;
    int startCol = start.first - 'a';
    int endRow = end.second - 1;
    int endCol = end.first - 'a';

    bool flag = false;




    // Verificar si hay una pieza en la posición de inicio
    Piece* piece = board->getPieceAt(startRow, startCol);
    if (piece == nullptr) {
        cout<<"Invalid move . Try again\n";
        return false;
    }


    // Verificar si la pieza pertenece al jugador actual
    if (piece->getColor() != players[currentPlayer].getColor()) {
        cout<<"Invalid move . Try again\n";
        return false;
    }

    if(piece->getType()=="King")
    {
        if(detectCastle(make_pair(startRow,startCol), make_pair(endRow,endCol)))
        {

            if(isValidCastle(make_pair(endRow,endCol)))
            {
                makeCastle(make_pair(endRow,endCol));
                flag = 1;

            }

        }
    }

    if(!flag&&piece->getType()=="Pawn")
    {
        int direction = (players[currentPlayer].getColor()==0)? 1:-1;
        if(abs(end.second - start.second) == 1 && end.first == start.first+direction)
        {
            if(Pawn_enPassantable.first==startRow && abs(Pawn_enPassantable.second - startCol )==1)
            {
                board->movePiece({startRow, startCol}, {endRow, endCol}, players[currentPlayer].getColor());
                Piece* pawnToNull = board->getPieceAt(Pawn_enPassantable.first, Pawn_enPassantable.second);
                pawnToNull = nullptr;
                flag = 1;
            }
        }
    }

    if(!flag) {


        // Verificar si el movimiento es válido según las reglas del juego
        if (!isValidMove({startRow, startCol}, {endRow, endCol}, players[currentPlayer].getColor())) {
            cout << "Invalid move . Try again\n";
            return false;
        }


        // Realizar el movimiento en el tablero
        board->movePiece({startRow, startCol}, {endRow, endCol}, players[currentPlayer].getColor());

    }

    // Verificar si hay jaque mate

    //registerBoard(board,currentPlayer);
    // Verificar si hay empate


    // Cambiar al siguiente turno
    Pawn_enPassantable = {-1,-1};

    auto* updpiece = board->getPieceAt(endRow, endCol);
    if (updpiece->getType() == "Pawn") {
        Pawn* pawn = dynamic_cast<Pawn*>(updpiece); // Hacer un casteo dinámico a Pawn
        if (pawn != nullptr) {
            pawn->setMoved(true); // Usar setMoved en el peón
        }
    }


    if (updpiece->getType() == "King") {
        King* king = dynamic_cast<King*>(updpiece);
        if (king != nullptr) {
            king->setMoved(true);
        }
    }

    if (updpiece->getType() == "Rook") {
        Rook* rook = dynamic_cast<Rook*>(updpiece);
        if (rook != nullptr) {
            rook->setMoved(true);
        }
    }

    switchTurn();

    cout.flush();

    return true;
}

void Game::playMove() {
    // Obtener el nombre del jugador actual
    string currentPlayerName = players[currentPlayer].getNombre();

    // Imprimir el estado actual del tablero
    cout << "Turn of " << currentPlayerName << ":" << endl;
    board->print((currentPlayer==1));

    bool validinput=false;

    char startCol, endCol;
    int startRow, endRow;

    while(!validinput) {
        // Solicitar al jugador que ingrese un movimiento válido
        cout << "Play a move (example: e 2 e 4 ): \n";

        cin >> startCol >> startRow >> endCol >> endRow;

        startCol = tolower(startCol);
        endCol = tolower(endCol);

        if( (startCol>='a'&&startCol<='h'&&endCol>='a'&&endCol<='h') && (startRow>=1&&startRow<=8&&endRow>=1&&endRow<=8))
        {
            validinput = true;
        }

        if(!validinput)
        {
            cout<<"Invalid input . Try again \n";
            board->print(currentPlayer==1);
        }

        if(processMove(make_pair(startCol, startRow), make_pair(endCol, endRow))==false)
        {
            validinput=false;
        }

        if(validinput)
        {
            if (isCheckmate((currentPlayer) )) {
                cout << "¡CheckMate! Player " << players[(currentPlayer+1)%2].getNombre() << " has won!." << endl;
                gameOver = true;
            }

            if (isDraw()) {
                cout << "¡Draw!" << endl;
                gameOver = true;
            }
        }


    }

}

bool Game::getgameOver() {
    return gameOver;
}


bool Game::detectCastle(pair<int,int>start,pair<int, int> end) {

        // Verificar si la posición final es (1, 4) o (1, 6) para las blancas, o (7, 4) o (7, 6) para las negras
        if (players[currentPlayer].getColor()==0 && start == make_pair(0,4) && ( end== make_pair(0,2) || end == make_pair(0,6)) ) {
            return true; // Se detectó un intento de enroque
        }

        if (players[currentPlayer].getColor()==1 && start == make_pair(7,4) && ( end== make_pair(7,2) || end == make_pair(7,6)) ) {
            return true; // Se detectó un intento de enroque
        }

    return false; // No se detectó un intento de enroque
}


bool Game::isValidCastle(pair<int, int> end) {
    // Obtener la posición del rey
    pair<int, int> kingPos = board->getKingPosition(currentPlayer);

    // Verificar si el rey y la torre no se han movido
    Piece* kingPiece = board->getPieceAt(kingPos.first, kingPos.second);
    King* king = dynamic_cast<King*>(kingPiece);
    if (!king || king->getMoved()) {
        return false;
    }

    // Verificar si la torre objetivo no se ha movido
    pair<int, int> rookPos = (end.second == 2) ? make_pair(end.first, 0) : make_pair(end.first, 7);
    Piece* rookPiece = board->getPieceAt(rookPos.first, rookPos.second);
    //cout<<rookPos.first<<" "<<rookPos.second<< endl;
    Rook* rook = dynamic_cast<Rook*>(rookPiece);
    if (!rook || rook->getMoved()) {
        return false;
    }

    // Verificar que el camino entre la torre y el rey esté vacío
    int row = kingPos.first;
    int startCol = min(kingPos.second,rookPos.second);
    int endCol = max(kingPos.second,rookPos.second);
    for (int col = startCol+1; col <= endCol-1; ++col) {
        if (board->getPieceAt(row, col) != nullptr) {
            return false;
        }
    }

    // Verificar que no haya ningún movimiento válido de ninguna ficha enemiga a las casillas por las que pasa y en las que termina el rey
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = board->getPieceAt(i, j);
            if (piece != nullptr && piece->getColor() != currentPlayer) {
                pair<int, int> piecePosition = make_pair(i, j);
                for (int col = startCol+1; col <= endCol-1 ; ++col) {
                    pair<int, int> tempPos = make_pair(row, col);
                    if (piece->validateMove(tempPos) && board->isValidMove(piecePosition, tempPos, (currentPlayer + 1) %2)) {
                        return false;
                    }
                }
            }
        }
    }

    return true; // El enroque es válido
}



void Game::makeCastle(pair<int, int> end) {
        // Obtener la posición del rey
        pair<int, int> kingPos = board->getKingPosition(currentPlayer);

        // Determinar la posición final de la torre involucrada en el enroque
        pair<int, int> rookEnd,rookPos;

        if (end.second == 2) {
            rookEnd = make_pair(end.first,3 ); // Torre va a c1
            rookPos = make_pair(end.first,0);
        } else {
            rookEnd = make_pair(end.first, 5); // Torre va a f1
            rookPos = make_pair(end.first,7);
        }


        // Mover el rey a su posición final
        board->movePiece(kingPos, end, currentPlayer);
        board->movePiece(rookPos, rookEnd, currentPlayer);
    }

/*
void Game::registerBoard(Board* boardclone, int currentPlayer) { // Cambiar el parámetro boardclone a un puntero
    // Concatenar el jugador actual al tablero para distinguir entre tableros idénticos en diferentes turnos
    history_of_board[boardclone][players[currentPlayer].getColor()]++;
}
*/
