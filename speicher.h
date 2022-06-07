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
    //cout << "getChip(position[0], 0) = " << getChip(position[0], 0) << endl;
    //cout << "position[1] = " << position[1] << endl;

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
        else if (getChip(position) == getChip(position[0],  int(position[1]) - 1) && getChip(position) == getChip(position[0],  int(position[1]) - 2))
        {
            millsFound++;
        }
    }
    /* else
    {
        // This is executed, when stone is not placed in corner

        // checking for radial mill
        if (getChip(position) == getChip(string({'A' + position[1]})) == getChip(string({'B' + position[1]})) == getChip(string({'A' + position[1]})))
        {
            millsFound += 1;
        }
        // checking for tangential mill
        if (getChip(position) == getChip(orbit + rotation - 1) == getChip(orbit + rotation + 1))
        {
            millsFound += 1;
        }
    } */
    return millsFound;
}
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
