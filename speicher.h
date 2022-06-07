#include <iostream>
using namespace std;

char field[3][8]; // Zweidimensionales Array, welches die Werte 'O', 'W' und 'B' speichern soll.

void setChip(string, char);
char getChip(string);
void resetField();

void setChip(string coordinate, char color)
{
    // Setter, um den Wert des Arrays field an der Stelle coordinate (zb. "A0") auf den Wert color (zb. 'W') zu setzen.
    field[int(coordinate[0]) - 65][coordinate[1]] = color;
}

char getChip(char orbit, int rotation)
{
    // Getter, der den Wert des Arrays field an der Stelle coordinate (zb. "A0") zu returnt.
    return field[int(orbit) - 65][rotation];
}

char getChip(char orbit, char rotation)
{
    // Getter, der den Wert des Arrays field an der Stelle coordinate (zb. "A0") zu returnt.
    return field[int(orbit) - 65][rotation];
}

char getChip(string coordinate)
{
    // Getter, der den Wert des Arrays field an der Stelle coordinate (zb. "A0") zu returnt.
    return field[int(coordinate[0]) - 65][coordinate[1]];
}
int checkMill(string position)
{
    // Coordinates from A0 to C7/
    int millsFound = 0;

    //  Checking if stone is placed in corner
    cout << "Modolo-Prüfung = " << int(position[1]) % 2 << endl;
    cout << "getChip(position) = " << getChip(position) << endl;
    cout << "getChip(position[0], int(position[1]) + 1) = " << getChip(position[0], int(position[1]) + 1) << endl;
    cout << "getChip(position[0], int(position[1]) + 2) = " << getChip(position[0], int(position[1]) + 2) << endl;
    // cout << "getChip(position[0], 0) = " << getChip(position[0], 0) << endl;
    // cout << "position[1] = " << position[1] << endl;

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
bool checkNeighbour(string originPosition, string targetPosition)
{
    // Prüfen, ob zwei Positionen benachbart sind
    //  A == A?
    if (originPosition[0] == targetPosition[0])
    {
        // AX-AY ==1 DISTANZ
        if (originPosition[1] - targetPosition[1] == 1 || targetPosition[1] - originPosition[1] == 1)
        {
            return true;
            break;
        //EXCEPTION FOR X0 & X7
        }else if(originPosition[1] == 0 && targetPosition[1] == 7 || originPosition[1] == 7 && targetPosition[1] == 0){
            return true;
            break;
        } 
    }else if(originPosition[1] == targetPosition[1]){
        //AB BC BA CB
        if(originPosition[0] == 'A' && targetPosition[0] == 'B'){
            return true;
        }else if(originPosition[0] == 'B' && targetPosition[0] == 'C'){
            return true;
        }else if(originPosition[0] == 'C' && targetPosition[0] == 'B'){
            return true;
        }else if(originPosition[0 == 'B' && targetPosition[0] == 'A']){
            return true;
        }else{
            return false;
        }
    }
}
/*
int removeChip(char activePlayer, string position)
{
    if (activePlayer != getChip(position))
    {
        setChip(position, O);

        if (activePlayer == 'W')
        {
            pBlack.lostChips++;
            return 1;
            break;
        }
        else
        {
            pWhite.lostChips++;
            return 1;
            break;
        }
    } // FEHLERFALL
    else if (getChip(position) == 'O')
    {
        cout << "Das Feld ist leer, bitte wähle ein anderes Feld." << endl;
        return 0;
        break;
    }
    else
    {
        cout << "Auf dem Feld steht dein eigener Stein, bitte wähle ein anderes Feld." << endl;
        return 0;
        break;
    }
}*/
void resetField()
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
