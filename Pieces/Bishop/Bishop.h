#ifndef BISHOP_H
#define BISHOP_H

#include "../Piece.h"

class Bishop : public Piece {
public:
    // Constructor
    Bishop(int color);

    // Destructor
    ~Bishop() override;
};

#endif // BISHOP_H
