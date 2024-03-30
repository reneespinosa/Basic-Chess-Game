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
        Piece(string type , int color){
            this->type = type;
            this->color = color;
        }

    // Destructor virtual
         virtual ~Piece() {}

    // Método virtual para mover la pieza
         virtual void move(pair<int, int> new_position) {
        position = new_position;
        }

    // Métodos Get para acceder a los atributos

    string getType()
    {
        return this->type;
    }

    int getColor()
    {
        return this->color;
    }

    pair<int,int> getPosition()
    {
        return this->position;
    }

};

class Pawn : public Piece {
public:
    // Constructor
    Pawn(int color) : Piece("Pawn", color) {}
    
    // Destructor
    ~Pawn() {}
};

class Rook : public Piece {
public:
    // Constructor
    Rook(int color) : Piece("Rook", color) {}

    // Destructor
    ~Rook() {}
};

class Bishop : public Piece {
public:
    // Constructor
    Bishop(int color) : Piece("Bishop", color) {}

    // Destructor
    ~Bishop() {}
};

class Queen : public Piece {
public:
    // Constructor
    Queen(int color) : Piece("Queen", color) {}

    // Destructor
    ~Queen() {}
};

class Knight : public Piece {
public:
    // Constructor
    Knight(int color) : Piece("Knight", color) {}

    // Destructor
    ~Knight() {}
};

class King : public Piece {
public:
    // Constructor
    King(int color) : Piece("King", color) {}

    // Destructor
    ~King() {}
};



