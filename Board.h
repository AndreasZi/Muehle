#include <iostream>
using namespace std;


class Board
{
private:
    char cellPositions[3][8]; // Zweidimensionales Array, welches die Werte 'O', 'W' und 'B' speichern soll.
    /* data */
public:
    Board(/* args */);
    ~Board();
    void setChip(string, char);
    char getChip(string);
    char getChip(char, int);
    char getChip(char, char);

    void emptyBoard();
    void printBoard();
    int checkMill(string);
    bool checkNeighbour(string, string);
};

