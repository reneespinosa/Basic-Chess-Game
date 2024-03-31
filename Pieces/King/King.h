#ifndef KING_H
#define KING_H

#include <iostream>
#include "../Piece.h"

class King : public Piece {
public:
    // Constructor
    King(int color);

    // Destructor
    ~King() override;
};

#endif // KING_H
