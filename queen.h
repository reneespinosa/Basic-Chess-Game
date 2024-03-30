#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h";


class Queen : public Piece {
public:
    // Constructor
    Queen(int color) : Piece("Queen", color) {}

    // Destructor
    ~Queen() {}
};

#endif