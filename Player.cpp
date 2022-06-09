#include "Player.h"
#include "Chip.h"
#include <iostream>
using namespace std;
Player :: Player(char COLOR)
{
    color = COLOR;
}

void Player :: startTurn(int &phase){
    string targetPosition;
    cout << "Spieler " << color << " ist am Zug" << endl;
    // Abfrage zu "Beginn" des Spiels: Sind noch Steine zum Setzen übrig?
    switch(phase){
        case 0:
            do{

                // Spieler A soll die Position des Arrays angeben, an dem er den Stein plazieren will
                cout << "Bitte geben Sie die zu belegende Postion an!" << endl;
                cin >> targetPosition;

            } while (Chip::getChip(targetPosition).player != this); // Position abfragen - ist das Feld frei?

            // Stein auf gewählte Position setzen
            Chip(targetPosition, this);

            // cout:: //Spielfeld aktualisieren
            //cout << "Sie haben noch " << --player.unusedChips << " ungesetzte Steine" << endl;
    }
}