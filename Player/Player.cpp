#include "Player.h"

// Constructor
Player::Player(string nombre, int color) : nombre(nombre), color(color) {}

// Métodos para obtener información del jugador
int Player::getColor() {
    return color;
}

string Player::getNombre() {
    return nombre;
}



