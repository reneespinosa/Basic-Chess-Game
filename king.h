#ifndef KING_H
#define KING_H

#include "piece.h";

class King : public Piece {
public:
    // Constructor
    King(int color) : Piece("King", color) {}

    // Destructor
    ~King() {}
};


#endif