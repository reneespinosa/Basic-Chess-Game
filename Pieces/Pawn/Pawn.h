#ifndef PAWN_H
#define PAWN_H

#include "../Piece.h"

class Pawn : public Piece {
public:
    // Constructor
    Pawn(int color);

    // Destructor
    ~Pawn() override;
};

#endif // PAWN_H
