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

Board::Board(/* args */)
{
    emptyBoard();
}

Board::~Board()
{
}

char cellPositions[3][8]; // Zweidimensionales Array, welches die Werte 'O', 'W' und 'B' speichern soll.


void Board::setChip(string coordinate, char color)
{
    // Setter, um den Wert des Arrays cellPositions an der Stelle coordinate (zb. "A0") auf den Wert color (zb. 'W') zu setzen.
    cellPositions[int(coordinate[0]) - 65][coordinate[1]] = color;
}

char Board::getChip(char orbit, int rotation)
{
    // Getter, der den Wert des Arrays cellPositions an der Stelle coordinate (zb. "A0") zu returnt.
    return cellPositions[int(orbit) - 65][rotation];
}

char Board::getChip(char orbit, char rotation)
{
    // Getter, der den Wert des Arrays cellPositions an der Stelle coordinate (zb. "A0") zu returnt.
    return cellPositions[int(orbit) - 65][rotation];
}

char Board::getChip(string coordinate)
{
    // Getter, der den Wert des Arrays cellPositions an der Stelle coordinate (zb. "A0") zu returnt.
    return cellPositions[int(coordinate[0]) - 65][coordinate[1]];
}

void Board::emptyBoard()
{   
    // Feld leeren (mit 'O's füllen)
    string a = "A0";
    while (a[0] != 'D')
    { // Alle Buchstaben von A bis C
        while (a[1] != '8')
        {                    // Alle Zahlen von 0 bis 7
            setChip(a, 'O'); // Feld auf 'O' setzen
            a[1]++;          // Zahl um 1 ERhöhen
        }
        a[1] = '0'; // Zahl zurück auf 0 setzen
        a[0]++;     // Buchstabe erhöhen
    }
}

int Board::checkMill(string position)
{
    // Coordinates from A0 to C7/
    int millsFound = 0;

    //  Checking if stone is placed in corner
    if (int(position[1]) % 2 == 0 || position[1] == '0')
    {
        if (position[1] == '6' && getChip(position) == getChip(position[0], 7 + 48) && getChip(position) == getChip(position[0], 0 + 48))
        {
            millsFound++;
        }
        else if (getChip(position) == getChip(position[0], int(position[1]) + 1) && getChip(position) == getChip(position[0], int(position[1]) + 2))
        {
            millsFound++;
        }

        if (position[1] == '0' && getChip(position) == getChip(position[0], 6 + 48) && getChip(position) == getChip(position[0], 7 + 48))
        {
            millsFound++;
        }
        else if (getChip(position) == getChip(position[0], int(position[1]) - 1) && getChip(position) == getChip(position[0], int(position[1]) - 2))
        {
            millsFound++;
        }
    }
    else
    {
        // This is executed, when stone is not placed in corner

        // checking for radial mill
        if (getChip(position) == getChip('A', position[1]) && getChip(position) == getChip('B', position[1]) && getChip(position) == getChip('C', position[1]))
        {
            millsFound++;
        }
        // checking for tangential mill
        if (getChip(position) == getChip(position[0], int(position[1]) - 1) && getChip(position) == getChip(position[0], int(position[1]) + 1))
        {
            millsFound++;
        }
    }
    return millsFound;
}
bool Board::checkNeighbour(string originPosition, string targetPosition)
{
    // Checking for same orbit (A == A?)
    if (originPosition[0] == targetPosition[0])
    {
        // AX-AY ==1 DISTANZ
        if (abs(originPosition[1] - targetPosition[1]) == 1 || abs(originPosition[1] - targetPosition[1]) == 7)
        {
            return true;
            // EXCEPTION FOR X0 & X7
        }/* 
        else if (originPosition[1] == 0 && targetPosition[1] == 7 || originPosition[1] == 7 && targetPosition[1] == 0)
        {
            return true;
        } */
    }
    else if (originPosition[1] == targetPosition[1])
    {
        // Cases: AB BC  BA CB
        if (originPosition[0] == 'A' && targetPosition[0] == 'B')
        {
            return true;
        }
        else if (originPosition[0] == 'B' && targetPosition[0] == 'C')
        {
            return true;
        }
        else if (originPosition[0] == 'C' && targetPosition[0] == 'B')
        {
            return true;
        }
        else if (originPosition[0] == 'B' && targetPosition[0] == 'A')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
    
}
/* int removeChip(char activePlayer, string position)
{
    //!!!Fehlerfall muss beim Funktionsaufruf berücksichtigt werden und kann nicht von removeChip() gehandelt werden!!!
    if (activePlayer != getChip(position))
    {
        setChip(position, 'O');

        if (activePlayer == 'W')
        {
            pBlack.lostChips++;
            cout << "Ein schwarzer Stein wurde von " << position << " entfernt." << endl;
            return 1;
        }
        else
        {
            pWhite.lostChips++;
            cout << "Ein weißer Stein wurde von " << position << " entfernt." << endl;
            return 1;
        }
    }
    // FEHLERFALL
    else if (getChip(position) == 'O')
    {
        cout << "Das Feld ist leer, bitte wähle ein anderes Feld." << endl;
        return 0;
    }
    else
    {
        cout << "Auf dem Feld steht dein eigener Stein, bitte wähle ein anderes Feld." << endl;
        return 0;
    }
} */

void Board::printBoard(){
    cout << "Mühle:" << endl;
    cout << getChip("A0") << "------------" << getChip("A1") <<"------------"<<getChip("A2")<< endl;
    cout <<"|" <<"            " <<"|"<< "            "<<"|"<< endl;
    cout <<"|    "<< getChip("B0")<< "-------" << getChip("B1") <<"-------"<<getChip("B2")<< "    |"<<endl;
    cout <<"|" <<"    |       " <<"|"<< "       |  "<<"  |"<< endl;
    cout <<"|    |   "<<getChip("C0")<<"---"<<getChip("C1")<<"---"<<getChip("C2")<<"   |"<<"    |"<<endl;
    cout <<"|" <<"    |   |       |   |  "<<"  |"<< endl;
    cout <<getChip("A7")<<"----"<<getChip("B7")<<"---"<<getChip("C7")<<"       "<<getChip("C3")<<"---"<<getChip("B3")<<"----"<<getChip("A3")<<endl;
    cout <<"|" <<"    |   |    " <<" "<< "  |   |  "<<"  |"<< endl;
    cout <<"|    |   "<<getChip("C6")<<"---"<<getChip("C5")<<"---"<<getChip("C4")<<"   |"<<"    |"<<endl;
    cout <<"|" <<"    |       " <<"|"<< "       |  "<<"  |"<< endl;
    cout <<"|    "<< getChip("B6")<< "-------" << getChip("B5") <<"-------"<<getChip("B4")<< "    |"<<endl;
    cout <<"|" <<"            " <<"|"<< "            "<<"|"<< endl;
    cout << getChip("A6")<< "------------" << getChip("A5") <<"------------"<<getChip("A4")<< endl;
    }