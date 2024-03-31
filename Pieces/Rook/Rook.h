#ifndef ROOK_H
#define ROOK_H

#include "../Piece.h"

using namespace std;


class Rook : public Piece {

private:
    bool moved;
    bool crowned;


public:
    // Constructor
    Rook(int color, bool is_crowned = false);

    // Destructor
    ~Rook() override;

    bool validateMove(pair<int, int> new_position) override;
    string getSymbol() override;
    bool canCastle();

    // Gets
    bool getMoved();
    bool getCrowned();

    //Sets
    void setMoved(bool has_moved);
    void setCrowned(bool is_crowned);

};

#endif // ROOK_H
