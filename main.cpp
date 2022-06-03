#include <iostream>
#include "speicher.h"
#include "gui.h"
#include "player.h"

// dies ist ein sickes Mühlespiel!!!!!
using namespace std;

/* struct player{
    int unusedChips;
    int lostChips;
    char color;
}; */

void startTurn(Player &player)
{
    string position;
    cout << "Spieler " << player.color << " ist am Zug" << endl;
    // Abfrage zu "Beginn" des Spiels: Sind noch Steine zum Setzen übrig?
    if (player.unusedChips > 0)
    {

        do
        {
            // Spieler A soll die Position des Arrays angeben, an dem er den Stein plazieren will
            cout << "Bitte geben Sie die zu belegende Postion an!" << endl;

            // worin soll das gespeichert werden?
            cin >> position;
        } while (getChip(position) != 'O'); // Position abfragen - ist das Feld frei?

        // Stein auf gewählte Position setzen
        setChip(position, player.color);

        // cout:: //Spielfeld aktualisieren
        cout << "Sie haben noch " << --player.unusedChips << " ungesetzte Steine" << endl;
    }
    /*else
    {
        // Stein wählen
        cout << "Bitte wählen Sie eine Position ihres Steins um ihn zu verschieben" << endl;
        cin >> // Arrayposition eingeben

        if(player.color == getChip(position)){

            // neue Position wählen
            cout << "Bitte wählen Sie eine Position ihres Steins um ihn zu verschieben" << endl;
        cin >> // Neue Position angeben
        // Distanz prüfen (gültig nur wenn ToteSteine >= 6?)
        // Position frei?
        // Stein verschieben
        // oder nochmal probieren
        }
    }*/

    // umliegende Felder prüfen - ist eine neue Mühle entstanden?
    // umliegende Felder prüfen - ist eine neue Mühle entstanden?
    cout << checkMill(position) << " <----- checkMill()>" << endl;
}

int main()
{

    Player pBlack('B'); // Spieler pWhite ist ein Objekt der Klasse Spieler
    Player pWhite('W'); // Spieler pBlack ist ein Objekt der Klasse Spieler

    resetField();
    printField();

    while (pWhite.lostChips < 7 && pBlack.lostChips < 7)
    {
        startTurn(pWhite);
        printField();
        startTurn(pBlack);
        printField();
    }

    return 0;
}