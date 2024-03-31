#ifndef KNIGHT_H
#define KNIGHT_H

#include "../Piece.h"

class Knight : public Piece {
public:
    // Constructor
    Knight(int color);

    // Destructor
    ~Knight() override;
};

#endif // KNIGHT_H
