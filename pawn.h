#ifndef PAWN_H
#define PAWN_H

#include "piece.h";


class Pawn : public Piece {
public:
    // Constructor
    Pawn(int color) : Piece("Pawn", color) {}
    
    // Destructor
    ~Pawn() {}
};

#endif