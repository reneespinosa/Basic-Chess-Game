#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h";


class Knight : public Piece {
public:
    // Constructor
    Knight(int color) : Piece("Knight", color) {}

    // Destructor
    ~Knight() {}
};

#endif