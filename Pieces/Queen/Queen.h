#ifndef QUEEN_H
#define QUEEN_H

#include "../Piece.h"
using namespace std;



class Queen : public Piece {
public:
    // Constructor
    Queen(int color);

    // Destructor
    ~Queen() override;
    bool validateMove(pair<int, int> new_position) override;
    string getSymbol() override ;

};

#endif // QUEEN_H
