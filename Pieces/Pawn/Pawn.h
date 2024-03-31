#ifndef PAWN_H
#define PAWN_H

#include "../Piece.h"
using namespace std;


class Pawn : public Piece {
public:
    // Constructor
    Pawn(int color);

    // Destructor
    ~Pawn();

    // Método para validar un movimiento del peón
    bool validateMove(pair<int, int> new_position) override;

    string getSymbol() override;
};

#endif // PAWN_H
