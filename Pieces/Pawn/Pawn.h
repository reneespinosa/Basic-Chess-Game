#ifndef PAWN_H
#define PAWN_H

#include "../Piece.h"
using namespace std;


class Pawn : public Piece {

private:

    bool moved;
    bool enPassantable;

public:
    // Constructor
    Pawn(int color);

    // Destructor
    ~Pawn();

    // Método para validar un movimiento del peón
    bool validateMove(pair<int, int> new_position) override;

    string getSymbol() override;

    bool getenPassantable();

    void setenPassantable(bool enPassantable);

    bool getMoved();

    void setMoved(bool has_moved);

};

#endif // PAWN_H
