#include "Board.h"

Board::Board(/* args */)
{

    //*cells = ;
    emptyBoard();
}

void Board::setChip(char orbit, char rotation, char color)
{
    // Setter, um den Wert des Arrays cells an der Stelle coordinate (zb. "A0") auf den Wert color (zb. 'W') zu setzen.
    cells[orbit][rotation] = color;
}

char Board::getChip(char orbit, char rotation)
{
    // Getter, der den Wert des Arrays cells an der Stelle coordinate (zb. "A0") zu returnt.
    return cells[orbit][rotation];
}

void Board::emptyBoard()
{
    for (char a = 'A'; a < 'D'; a++)
    {
        // Alle Buchstaben von A bis C
        for (char b = '0'; b < '8'; b++)
        {
            // Alle Zahlen von 0 bis 7
            // Feld auf 'O' setzen
            setChip(a, b, 'O');
        }
    }
}

int Board::checkMill(char orbit, char rotation)
{
    if (getChip(orbit, rotation) == 'O')
    {
        return 0;
    }
    // Coordinates from A0 to C7/
    if (int(rotation) % 2 == 0) //  Checking if stone is placed in corner
    {

        if (getChip(orbit, rotation) == getChip(orbit, rotation + 1) && getChip(orbit, rotation) == getChip(orbit, rotation + 2))
        //+dir Standardprüfung für Ecksteine
        {
            // der IM Uhrzeigersinn befindliche Nachbar, sowie dessen Nachbar sind gleich der Farbe des gesetzten Steins
            return 1;
        }

        if (getChip(orbit, rotation) == getChip(orbit, rotation - 1) && getChip(orbit, rotation) == getChip(orbit, rotation - 2))
        //-dir Standardprüfung für Ecksteine
        {
            // der GEGEN den Uhrzeigersinn befindliche Nachbar, sowie dessen Nachbar sind gleich der Farbe des gesetzten Steins
            return 1;
        }
    }
    else
    {
        // Der neugesetzte Stein ist ein Mittelstein

        if (getChip('A', rotation) == getChip('B', rotation) && getChip('B', rotation) == getChip('C', rotation))
        // Mühle auf Steg
        {
            // Alle Steine auf dem Betroffenen Steg sind gleichfarbig.
            return 1;
        }
        // checking for tangential mill

        if (getChip(orbit, rotation) == getChip(orbit, rotation - 1) && getChip(orbit, rotation) == getChip(orbit, rotation + 1))
        // Mühle auf dem Rechteck
        {
            // Farbe des neugestzten Steins ist gleich den auf den Nachbarfeldern auf dem jeweilligen Rechteck
            return 1;
        }
    }

    if ((rotation == '0' || rotation == '7' || rotation == '6'))
    // Ausnahme für Nulldurchgang:
    {
        // Der Chip liegt auf Feld 0, 7 oder 6
        if (getChip(orbit, '0') == getChip(orbit, '7') && getChip(orbit, '6') == getChip(orbit, '7'))
        // 0, 7 und 6 sind von gleichfarbigen Steinen besetzt.
        {
            return 1;
        }
    }
    return 0;
}
bool Board::checkNeighbour(char orbitOrigin, char rotationOrigin, char orbitTarget, char rotationTarget)
{
    // Checking for same orbit (A == A?)
    if (orbitOrigin == orbitTarget)
    {
        // AX-AY ==1 DISTANZ
        if (abs(rotationOrigin - rotationTarget) == 1 || abs(rotationOrigin - rotationTarget) == 7)
        {
            // EXCEPTION für Ecksteine FOR X0 & X7
            return true;

        } /*
         else if (rotationOrigin == 0 && rotationTarget == 7 || rotationOrigin == 7 && rotationTarget == 0)
         {
             return true;
         } */
    }
    else if (rotationOrigin == rotationTarget)
    {
        // Cases: AB BC  BA CB
        if (abs(orbitOrigin - orbitTarget) == 1)
        {
            return true;
        }
    }
    return false;
}
std::list<string> getNeighbour(string origin)
{
    list<string> neighbours;

    if (int(origin[1]) % 2 == 0) //  Checking if origin is in CORNER
    {
        if (origin.[1] == 0) //  Checking if origin is at X0
        {
            neighbours<0> = string(origin[0], origin[1]++);
            neighbours<1> = string(origin[0], '7');
        }
        else
        {
            neighbours<0> = string(origin[0], origin[1]++);
            neighbours<1> = string(origin[0], origin[1]--);
        }
    }
    else if (origin[0] == 'A') // NOT IN CORNER && IN ORBIT A
    {
        // NEIGHBOURS ON SAME ORBIT
        neighbours<0> = string(origin[0], origin[1]++);
        neighbours<1> = string(origin[0], origin[1]--);
        neighbours<2> = string(origin[0]++, origin[1]);
    }
    else if (origin[0] == 'B') //   NOT IN CORNER && IN ORBIT B
    {
        // NEIGHBOURS ON SAME ORBIT
        neighbours<0> = string(origin[0], origin[1]++);
        neighbours<1> = string(origin[0], origin[1]--);
        // NEIGHBOURS ON SAME ROTATION
        neighbours<2> = string(origin[0]++, origin[1]);
        neighbours<3> = string(origin[0]--, orignin[1]);
    }
    else //NOT IN CORNER && IN ORBIT C
    {
        // NEIGHBOURS ON SAME ORBIT
        neighbours<0> = string(origin[0], origin[1]++);
        neighbours<1> = string(origin[0], origin[1]--);
        neighbours<2> = string(origin[0]--, origin[1]);
    }
    return neighbours;
}

void Board::printBoard()
{
    cout << "Mühle:" << endl;
    cout << getChip('A', '0') << "------------" << getChip('A', '1') << "------------" << getChip('A', '2') << endl;
    cout << "|"
         << "            "
         << "|"
         << "            "
         << "|" << endl;
    cout << "|    " << getChip('B', '0') << "-------" << getChip('B', '1') << "-------" << getChip('B', '2') << "    |" << endl;
    cout << "|"
         << "    |       "
         << "|"
         << "       |  "
         << "  |" << endl;
    cout << "|    |   " << getChip('C', '0') << "---" << getChip('C', '1') << "---" << getChip('C', '2') << "   |"
         << "    |" << endl;
    cout << "|"
         << "    |   |       |   |  "
         << "  |" << endl;
    cout << getChip('A', '7') << "----" << getChip('B', '7') << "---" << getChip('C', '7') << "       " << getChip('C', '3') << "---" << getChip('B', '3') << "----" << getChip('A', '3') << endl;
    cout << "|"
         << "    |   |    "
         << " "
         << "  |   |  "
         << "  |" << endl;
    cout << "|    |   " << getChip('C', '6') << "---" << getChip('C', '5') << "---" << getChip('C', '4') << "   |"
         << "    |" << endl;
    cout << "|"
         << "    |       "
         << "|"
         << "       |  "
         << "  |" << endl;
    cout << "|    " << getChip('B', '6') << "-------" << getChip('B', '5') << "-------" << getChip('B', '4') << "    |" << endl;
    cout << "|"
         << "            "
         << "|"
         << "            "
         << "|" << endl;
    cout << getChip('A', '6') << "------------" << getChip('A', '5') << "------------" << getChip('A', '4') << endl;
}