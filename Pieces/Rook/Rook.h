#ifndef ROOK_H
#define ROOK_H

#include "../Piece.h"

class Rook : public Piece {
public:
    // Constructor
    Rook(int color);

    // Destructor
    ~Rook() override;
};

#endif // ROOK_H
