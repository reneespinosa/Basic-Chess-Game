#ifndef KNIGHT_H
#define KNIGHT_H

#include "../Piece.h"

using namespace std;

class Knight : public Piece {
public:
    // Constructor
    Knight(int color);

    // Destructor
    ~Knight() override;

    bool validateMove(pair<int, int> new_position) override;

};

#endif // KNIGHT_H
