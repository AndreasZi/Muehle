#include <iostream>
#include "Player.h"
#include "Chip.h"


Chip::Chip(std::string coordinate, Player &player)
    {
        // Setter, um den Wert des Arrays field an der Stelle coordinate (zb. "A0") auf den Wert color (zb. 'W') zu setzen.
        field[int(coordinate[0]) - 65][coordinate[1]];
    }

Chip Chip::getChip(std::string coordinate)
    {
        // Getter, der den Wert des Arrays field an der Stelle coordinate (zb. "A0") zu returnt.
        return *field[int(coordinate[0]) - 65][coordinate[1]];
    }

void Chip::resetField()
    {
       /*  // Feld leeren (mit 'O's füllen)
        std::string a = "A0";
        while (a[0] != 'D')
        { // Alle Buchstaben von A bis C
            while (a[1] != '8')
            {                    // Alle Zahlen von 0 bis 7
                setChip(a, 'O'); // Feld auf 'O' setzen
                a[1]++;          // Zahl um 1 ERhöhen
            }
            a[1] = '0'; // Zahl zurück auf 0 setzen
            a[0]++;     // Buchstabe erhöhen
        } */
    }