#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h";


class Bishop : public Piece {
public:
    // Constructor
    Bishop(int color) : Piece("Bishop", color) {}

    // Destructor
    ~Bishop() {}
};

#endif

