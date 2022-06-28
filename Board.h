#include <iostream>
#include <list>
using namespace std;


class Board
{
private:
    char cells[3][8]; // Zweidimensionales Array, welches die Werte 'O', 'W' und 'B' speichern soll.
public:
    Board();

    
    void setChip(char, char, char);
    char getChip(char, char);

    void emptyBoard();
    void printBoard();
    int checkMill(char, char);
    bool checkNeighbour(char, char, char, char);
    std::list::list<string> getNeighbour(string);
};