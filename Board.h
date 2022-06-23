#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
using namespace std;


class Board
{
private:
    
public:
char cells[3][8]; // Zweidimensionales Array, welches die Werte 'O', 'W' und 'B' speichern soll.
    Board();

    
    void setChip(char, char, char);
    char getChip(char, char);

    void emptyBoard();
    void printBoard();
    int checkMill(char, char);
    bool checkNeighbour(char, char, char, char);
};


#endif