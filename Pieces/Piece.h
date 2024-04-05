#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Piece {
protected:
    string type;
    int color;
    pair<int, int> position;

public:
    // Constructor
    Piece(string type, int color);

    // Destructor virtual
    virtual ~Piece();


    Piece(const Piece& other);
    //Piece& operator=(const Piece& other);


    // Método virtual puro para validar un movimiento
    virtual bool validateMove(pair<int, int> new_position) = 0;
    virtual string getSymbol() = 0;


    // Métodos Get para acceder a los atributos
    string getType();
    int getColor();
    pair<int,int> getPosition();


    // Métodos Set para acceder a los atributos

    void setPosition(pair<int, int> new_position);
    void setType(string new_type);
    void setColor(int new_color);

};

#endif // PIECE_H
