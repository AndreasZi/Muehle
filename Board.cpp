#include "Board.h"

Board::Board(/* args */)
{
    // Leerem "Player" einen Char zuweisen
    empty.setColor('O');

    // Spielfeld vor Spielstart leeren
    emptyBoard();
}

char Board::getEmptyColor()
{
    return empty.getColor();
}

void Board::setChip(char orbit, char rotation, Player &player)
{
    // Setter, um den Wert des Arrays cells an der Stelle coordinate (zb. "A0") auf den Wert player zu setzen.
    cells[int(orbit) - 65][int(rotation) - 48] = &player;
}

void Board::deleteChip(char orbit, char rotation)
{
    // Setter, um den Wert des Arrays cells an der Stelle coordinate (zb. "A0") auf den Wert empty zu setzen.
    cells[int(orbit) - 65][int(rotation) - 48] = &empty;
}

char Board::getChip(char orbit, char rotation)
{
    // Getter, der den Wert des Arrays cells an der Stelle coordinate (zb. "A0") zu returnt.
    return cells[int(orbit) - 65][int(rotation) - 48]->getColor();
}

Player *Board::getPlayer(char orbit, char rotation)
{
    // Getter, der den Wert des Arrays cells an der Stelle coordinate (zb. "A0") zu returnt.
    return cells[int(orbit) - 65][int(rotation) - 48];
}

void Board::emptyBoard()
{
    // Alle Felder mit empty zu füllen
    Player **ptr = &cells[0][0]; // pointer um die Mehrdimensionalität zu überspringen
    for (int i = 0; i < 24; i++)
    {
        *(ptr + i) = &empty;
    }
}

int Board::checkMill(char orbit, char rotation)
{
    if (getPlayer(orbit, rotation) == &empty)
    {
        // Wenn das geprüfte Feld Leer ist, ist definitiv keine Mühle vorhanden :P
        return 0;
    }

    // Coordinates from A0 to C7/
    if (int(rotation) % 2 == 0) //  Checking if stone is placed in corner
    {
        if ((rotation == '0' || rotation == '6'))
        // Ausnahme für Nulldurchgang:
        {
            // Der Chip liegt auf Feld 0 oder 6 und könnte Somit durch Null gehen
            if (getChip(orbit, '0') == getChip(orbit, '7') && getChip(orbit, '6') == getChip(orbit, '7'))
            {
                // 0, 7 und 6 sind von gleichfarbigen Steinen besetzt. -> Mühle
                return 1;
            }
        }
        if (getChip(orbit, rotation) == getChip(orbit, rotation + 1) && getChip(orbit, rotation) == getChip(orbit, rotation + 2) && rotation != '6')
        //+dir Standardprüfung für Ecksteine
        {
            // der IM Uhrzeigersinn befindliche Nachbar, sowie dessen Nachbar sind gleich der Farbe des gesetzten Steins
            return 1;
        }

        if (getChip(orbit, rotation) == getChip(orbit, rotation - 1) && getChip(orbit, rotation) == getChip(orbit, rotation - 2) && rotation != '0')
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
        if (rotation == '7')
        // Ausnahme für Nulldurchgang:
        {
            // Der Chip liegt auf Feld 0, 7 oder 6
            if (getChip(orbit, '0') == getChip(orbit, '7') && getChip(orbit, '6') == getChip(orbit, '7'))
            // 0, 7 und 6 sind von gleichfarbigen Steinen besetzt.
            {
                return 1;
            }
        }
        else if (getChip(orbit, rotation) == getChip(orbit, rotation - 1) && getChip(orbit, rotation) == getChip(orbit, rotation + 1))
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
    // FEHLEINGABE WIRD NICHT BERÜCKSICHTIGT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //  Checking for same orbit (A == A?)
    if (orbitOrigin == orbitTarget)
    {
        if (abs(rotationOrigin - rotationTarget) == 1 || abs(rotationOrigin - rotationTarget) == 7)
        {
            // Die Distanz zwischen den Beiden Punkten hat den Betrag 1 oder 7 (0-7 oder 7-0)
            // AX-AY ==1 DISTANZ
            return true;
        }
    }
    else if (rotationOrigin == rotationTarget && rotationOrigin % 2 != 0)
    {
        // Cases: AB BC  BA CB
        if (abs(orbitOrigin - orbitTarget) == 1)
        {
            // Die Distanz zwischen den Beiden Punkten hat den Betrag 1
            return true;
        }
    }
    return false;
}

string Board::generateChipPlacement()
{
    char currentOrdbit = 'A';
    string placementPosition = "C6";
    // ERSTE FREIE POSITION WIRD VON BOT BESETZT
    for (int i = 0; i < 3; i++)
    {

        for (char j = '0'; j <= '7'; j++)
        {

            if (getChip(currentOrdbit, j) == getEmptyColor())
            {
                placementPosition = string({currentOrdbit, j});
                goto label;
            }
        }

        if (i == 1)
        {
            currentOrdbit = 'B';
        }
        else if (i == 2)
        {
            currentOrdbit = 'C';
        }
    }
label:
    return placementPosition;
}

tuple<string, string> Board::generateChipMovement(char activePlayerColor)
{
    char currentOrdbit = 'A';
    char currentNeighbourOrbit;
    string origin;
    string target;

    // Gesamtes Feld von A0 bis C7 durchscannen nach eigenen Chips
    for (int i = 0; i < 3; i++)
    {

        for (char j = '0'; j < '7'; j++)
        {
            // Prüfen, wo weisse Steine liegen
            if (getChip(currentOrdbit, j) == activePlayerColor)
            {

                // Gesamtes Feld von A0 bis C7 durchscannen nach leeren Nachbarfeldern
                for (int k = 0; k < 3; k++)
                {
                    for (char l = '0'; l < '7'; l++)
                    {

                        // Prüfen, ob Zelle frei ist
                        if (getChip(currentNeighbourOrbit, l) == getEmptyColor())
                        {
                            // Prüfen, ob Zelle ein Nachbar zu Origin ist.
                            if (checkNeighbour(currentOrdbit, j, currentNeighbourOrbit, l))
                            {
                                target = string(currentNeighbourOrbit, l);
                                goto label3;
                            }
                        }
                    }
                    if (k == 1)
                    {
                        currentNeighbourOrbit = 'B';
                    }
                    else if (k == 2)
                    {
                        currentNeighbourOrbit = 'C';
                    }
                }

            label3:
                origin = string({currentOrdbit, j});
                goto label2;
            }
        }
        if (i == 1)
        {
            currentOrdbit = 'B';
        }
        else if (i == 2)
        {
            currentOrdbit = 'C';
        }
    }

label2:
    return make_tuple(origin, target);
}

string Board::generateChipDeletion(char enemyPlayerColor)
{
    char currentOrdbit = 'A';
    string deletionPosition;

    for (int i = 0; i < 3; i++)
    {

        for (char j = '0'; j < '7'; j++)
        {

            if (getChip(currentOrdbit, j) == enemyPlayerColor)
            {
                deletionPosition = string({currentOrdbit, j});
                goto label1;
            }
        }
        if (i == 1)
        {
            currentOrdbit = 'B';
        }
        else if (i == 2)
        {
            currentOrdbit = 'C';
        }
    }
label1:
    return deletionPosition;
}

tuple<string, string, string, string> Board::getNeighbours(string origin)
{
    // Möglich sind 2, 3 ODER 4 Neighbours

    // FUNKTIONIER NICHT WEGEN BERECHNUNGSFEHLER VON string origin!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! =(

    string n0;
    string n1;
    string n2;
    string n3;

    if (int(origin[1]) % 2 == 0) //  Checking if origin is in CORNER
    {
        if (origin[1] == 0) //  Checking if origin is at X0
        {
            n0 = string(origin[0], origin[1]++);
            n1 = string(origin[0], '7');
            n2 = "O";
            n3 = "O";
        }
        else
        {
            n0 = string(origin[0], origin[1]++);
            n1 = string(origin[0], origin[1]--);
            n2 = "O";
            n3 = "O";
        }
    }
    else if (origin[0] == 'A') // NOT IN CORNER && IN ORBIT A
    {
        // NEIGHBOURS ON SAME ORBIT
        n0 = string(origin[0], origin[1]++);
        n1 = string(origin[0], origin[1]--);
        n2 = string(origin[0]++, origin[1]);
        n3 = "O";
    }
    else if (origin[0] == 'B') //   NOT IN CORNER && IN ORBIT B
    {
        // NEIGHBOURS ON SAME ORBIT
        n0 = string(origin[0], origin[1]++);
        n1 = string(origin[0], origin[1]--);
        // NEIGHBOURS ON SAME ROTATION
        n2 = string(origin[0]++, origin[1]);
        n3 = string(origin[0]--, origin[1]);
    }
    else // NOT IN CORNER && IN ORBIT C
    {
        // NEIGHBOURS ON SAME ORBIT
        n0 = string(origin[0], origin[1]++);
        n1 = string(origin[0], origin[1]--);
        n2 = string(origin[0]--, origin[1]);
        n3 = "O";
    }

    // return make_tuple(n0, n1, n2, n3);
    return make_tuple(string(n0), string(n1), string(n2), string(n3));
}

void Board::printBoard()
{
    // Ausgabe des Mühlefelds in der Console
    cout << "Mühle:" << endl;
    cout << getChip('A', '0') << "------------" << getChip('A', '1') << "------------" << getChip('A', '2') << "       "
         << "A0"
         << "------------"
         << "A1"
         << "-----------"
         << "A2" << endl;
    cout << "|"
         << "            "
         << "|"
         << "            "
         << "|"
         << "       "
         << "|"
         << "             "
         << "|"
         << "            "
         << "|" << endl;
    cout << "|    " << getChip('B', '0') << "-------" << getChip('B', '1') << "-------" << getChip('B', '2') << "    |"
         << "       "
         << "|    "
         << "B0"
         << "-------"
         << "B1"
         << "-------"
         << "B2"
         << "  |" << endl;
    cout << "|"
         << "    |       "
         << "|"
         << "       |  "
         << "  |"
         << "       "
         << "|"
         << "    |        "
         << "|"
         << "        | "
         << "  |" << endl;
    cout << "|    |   " << getChip('C', '0') << "---" << getChip('C', '1') << "---" << getChip('C', '2') << "   |"
         << "    |"
         << "       "
         << "|    |   "
         << "C0"
         << "---"
         << "C1"
         << "---"
         << "C2"
         << "  |"
         << "   |" << endl;
    cout << "|"
         << "    |   |       |   |  "
         << "  |"
         << "       "
         << "|"
         << "    |   |          |  |  "
         << " |" << endl;
    cout << getChip('A', '7') << "----" << getChip('B', '7') << "---" << getChip('C', '7') << "       " << getChip('C', '3') << "---" << getChip('B', '3') << "----" << getChip('A', '3') << "       "
         << "A7"
         << "---"
         << "B7"
         << "-"
         << "C7"
         << "         "
         << "C3"
         << "-"
         << "B3"
         << "---"
         << "A3" << endl;
    cout << "|"
         << "    |   |    "
         << " "
         << "  |   |  "
         << "  |"
         << "       "
         << "|"
         << "    |   |          |  |  "
         << " |" << endl;
    cout << "|    |   " << getChip('C', '6') << "---" << getChip('C', '5') << "---" << getChip('C', '4') << "   |"
         << "    |"
         << "       "
         << "|    |   "
         << "C6"
         << "---"
         << "C5"
         << "---"
         << "C4"
         << "  |"
         << "   |" << endl;
    cout << "|"
         << "    |       "
         << "|"
         << "       |  "
         << "  |"
         << "       "
         << "|"
         << "    |        "
         << "|"
         << "        |  "
         << " |" << endl;
    cout << "|    " << getChip('B', '6') << "-------" << getChip('B', '5') << "-------" << getChip('B', '4') << "    |"
         << "       "
         << "|    "
         << "B6"
         << "-------"
         << "B5"
         << "-------"
         << "B4"
         << "  |" << endl;
    cout << "|"
         << "            "
         << "|"
         << "            "
         << "|"
         << "       "
         << "|"
         << "             "
         << "|"
         << "           "
         << " |" << endl;
    cout << getChip('A', '6') << "------------" << getChip('A', '5') << "------------" << getChip('A', '4') << "       "
         << "A6"
         << "------------"
         << "A5"
         << "-----------"
         << "A4" << endl;
}
