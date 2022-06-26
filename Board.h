#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
#include "Player.h"
using namespace std;


class Board
{
private:
    Player empty;
    Player *cells[3][8]; // Zweidimensionales Array, welches die Werte 'O', 'W' und 'B' speichern soll.
public:

    Board();

    
    void setChip(char, char, Player&);
    void deleteChip(char, char);
    char getChip(char, char);
    Player* getPlayer(char, char);

    char getEmptyColor();

    void emptyBoard();
    void printBoard();
    int checkMill(char, char);
    bool checkNeighbour(char, char, char, char);
};


#endif