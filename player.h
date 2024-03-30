#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <utility>

using namespace std;

class Player {
public:
    private:
        string nombre;
        int color;
    
    public:

    Player(string nombre,int color)
    {
        this->nombre = nombre;
        this->color = color;
    }

    int getColor()
    {
        return this->color;
    }

    string getNombre()
    {
        return this->nombre;
    }

    pair<int, int> choose_piece_position(){
        pair<int, int> position;
        cout << "Enter position of the piece to move (row, col): ";
        cin >> position.first >> position.second;
        return position;
    }

    pair<int, int> choose_new_position() {
        pair<int, int> position;
        cout << "Enter new position (row, col): ";
        cin >> position.first >> position.second;
        return position;
    }

};

#endif // PLAYER_H