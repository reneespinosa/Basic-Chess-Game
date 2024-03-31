#ifndef KING_H
#define KING_H

#include <iostream>
#include "../Piece.h"

using namespace std;

class King : public Piece {
public:
    // Constructor
    King(int color);

    bool moved;

    // Destructor
    ~King() override;


    bool validateMove(pair<int, int> new_position) override;

    // Método para obtener el estado de movimiento del rey
    bool getMoved();

    // Método para establecer el estado de movimiento del rey
    void setMoved(bool moved_status);


};

#endif // KING_H
