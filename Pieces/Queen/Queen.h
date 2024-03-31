#ifndef QUEEN_H
#define QUEEN_H

#include "../Piece.h"

class Queen : public Piece {
public:
    // Constructor
    Queen(int color);

    // Destructor
    ~Queen() override;
};

#endif // QUEEN_H
