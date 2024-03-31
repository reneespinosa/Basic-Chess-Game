#include "Player.h"

// Constructor
Player::Player(string nombre, int color) {
    this->nombre = nombre;
    this->color = color;
}

// Método para obtener el color del jugador
int Player::getColor() {
    return color;
}

// Método para obtener el nombre del jugador
string Player::getNombre() {
    return nombre;
}

// Método para seleccionar la posición de la pieza a mover
pair<int, int> Player::choosePiecePosition() {
    pair<int, int> position;
    cout << "Enter position of the piece to move (row, col): ";
    cin >> position.first >> position.second;
    return position;
}

// Método para seleccionar la nueva posición
pair<int, int> Player::chooseNewPosition() {
    pair<int, int> position;
    cout << "Enter new position (row, col): ";
    cin >> position.first >> position.second;
    return position;
}
