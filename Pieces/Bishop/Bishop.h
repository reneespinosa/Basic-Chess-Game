#ifndef BISHOP_H
#define BISHOP_H

#include "../Piece.h"
using namespace std;

class Bishop : public Piece {
public:
    // Constructor
    Bishop(int color);

    // Destructor
    ~Bishop() override;

    string getSymbol() override;
    bool validateMove(pair<int, int> new_position) override;
};

#endif // BISHOP_H
