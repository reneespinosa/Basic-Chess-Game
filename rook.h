#ifndef ROOK_H
#define ROOK_H

#include "piece.h";


class Rook : public Piece {
public:
    // Constructor
    Rook(int color) : Piece("Rook", color) {}

    // Destructor
    ~Rook() {}
};

#endif