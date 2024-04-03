#ifndef GAME_H
#define GAME_H

#include "../Board/Board.h"
#include "../Player/Player.h"
#include <map>

class Game {
private:
    Board* board;
    Player players[2];
    int currentPlayer;
    bool gameOver;
    int moveCount; // Contador de movimientos para el empate por 50 movimientos sin captura
    map<Board*, int[2]> history_of_board; // Cambiar el tipo de datos clave del mapa
    pair<int,int> Pawn_enPassantable;

public:
    Game(string player1Name, string player2Name);
    ~Game();

    void playMove(); // Método para manejar el turno del jugador actual
    bool isDraw(); // Método para verificar si hay empate
    bool isInsufficientMaterial(); // Método para verificar si hay insuficiencia de material
    bool isStalemate(int Playercolor); // Método para verificar si hay jaque al rey
    bool isCheckmate(int color ); // Método para verificar si hay jaque mate
    bool getgameOver();

private:
    void switchTurn(); // Método para cambiar el turno al siguiente jugador
    bool isValidMove(pair<int, int> start,pair<int, int> end, int color);  // Método para verificar si un movimiento es válido
    bool processMove(pair<char, int> start, pair<char, int> end); // Método para procesar un movimiento dado
    bool isCheck(Board* board1); // Método para verificar si el rey actual está en jaque
    bool detectCastle(pair<int,int>start,pair<int,int>end); //Metodo para detectar enroque
    bool isValidCastle(pair<int, int> end);
    void makeCastle(pair<int, int> end);
    void registerBoard(Board* boardclone, int currentPlayer);
};

#endif // GAME_H
