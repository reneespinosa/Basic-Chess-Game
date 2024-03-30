#ifndef GAME_H
#define GAME_H

#include "board.h" // Incluimos el archivo de encabezado de la clase Board
#include "player.h" // Incluimos el archivo de encabezado de la clase Player

class Game {
private:
    Board board; // Tablero de juego
    Player players[2]; // Jugadores (en un juego de dos jugadores)
    int currentPlayer; // Índice del jugador actual (0 o 1)
    bool gameOver; // Indica si el juego ha terminado

public:
    // Constructor
    Game(const std::string& player1Name, const std::string& player2Name);

    // Método para iniciar el juego
    void start();

private:
    // Método para cambiar el turno al siguiente jugador
    void nextTurn();

    // Método para verificar si hay un ganador
    bool checkWinner() const;

    // Método para imprimir el estado actual del juego
    void printGameState() const;

    // Método para procesar el turno del jugador actual
    void processTurn();
};

#endif // GAME_H
