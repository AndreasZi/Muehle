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

char getChip(string coordinate)
{
    // Getter, der den Wert des Arrays field an der Stelle coordinate (zb. "A0") zu returnt.
    return field[int(coordinate[0]) - 65][coordinate[1]];
}
//------------------------BAUSTELLE WOLFI-------------------------------------(und Andireas)-----------
int checkMill(string position)
{
    // Coordinates from A0 to C7
    int millsFound = 0;
    // parsing coordinates
    char orbit(position[0]);
    int rotation(position[1]);
    // Checking if stone is placed in corner
    if (rotation % 2 == true || rotation == 0)
    {
        // from start position checking in positive direction
        for (int i = rotation; i <= rotation + 2; i++)
        {
            // Comparing neigbour field to starting field
            // Vielleicht geht das parsen hier schief???
                if(getChip(orbit + string (position[1] + i)) != getChip(position){
                // Schleife beenden
                i = rotation + 4;
                }
                if(i-rotation == 2){
                millsFound += 1;
                }
        }
        // from start position checking in negative direction EXCEPTION for A0, B0, C0 required
        for (int i = rotation; i > rotation - 2; i--)
        {
            if (getChip(orbit + string(position[1] - i)) != getChip(position))
            {
                i = rotation - 4;
            }
            if (i + rotation == -2)
            {
                millsFound += 1;
            }
        }
    }
    else
    {
        // This is executed, when stone is not placed in corner

        // checking for radial mill
        if (getChip(position) == getChip('A' + position(1)) == getChip('B' + position(1)) == getChip('C' + position(1)))
        {
            millsFound += 1;
        }
        // checking for tangential mill
        if (getChip(position) == getChip(orbit + rotation - 1) == getChip(orbit + rotation + 1))
        {
            millsFound += 1;
        }
    }
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
