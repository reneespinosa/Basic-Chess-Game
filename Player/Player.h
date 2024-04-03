#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <utility>

using namespace std;

class Player {
private:
    string nombre;
    int color;

public:
    // Constructor
    Player(string nombre, int color);

    // Métodos para obtener información del jugador
    int getColor();
    string getNombre();


};

#endif // PLAYER_H
