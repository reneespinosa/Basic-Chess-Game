#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Piece {

protected :
    string type;
    int color;
    pair<int, int> position;


public:
    // Constructor
    Piece(string type , int color);

    // Destructor virtual
    virtual ~Piece();

    // Método virtual para mover la pieza
    virtual void move(pair<int, int> new_position);

    // Métodos Get para acceder a los atributos

    string getType();

    int getColor();

    pair<int,int> getPosition();

};

#endif
