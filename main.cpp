#include <iostream>
#include "speicher.h"
#include "gui.h"
#include "player.h"

// dies ist ein sickes Mühlespiel!!!!!
using namespace std;




void startTurn(Player &player)
{
    string targetPosition;
    cout << "Spieler " << player.color << " ist am Zug" << endl;
    // Abfrage zu "Beginn" des Spiels: Sind noch Steine zum Setzen übrig?
    if (player.unusedChips > 0)
    {
        do{

            // Spieler A soll die Position des Arrays angeben, an dem er den Stein plazieren will
            cout << "Bitte geben Sie die zu belegende Postion an!" << endl;
            cin >> targetPosition;

        } while (getChip(targetPosition) != 'O'); // Position abfragen - ist das Feld frei?

        // Stein auf gewählte Position setzen
        setChip(targetPosition, player.color);

        // cout:: //Spielfeld aktualisieren
        cout << "Sie haben noch " << --player.unusedChips << " ungesetzte Steine" << endl;
    }
    else // Einen Stein vom aktuellen Spieler verschieben
    {
        string originPosition;

        do {
            //cin Ursprungsposition
            //cin Zielposition
            //Springen nicht erlaubt?
            //Nachbarfeld?
            //Feld frei?

            // Welcher Stein soll verschoben werden?
            cout << "Bitte wählen Sie eine Position ihres Steins, um ihn zu verschieben" << endl;
            cin >> originPosition;

            // Wohin soll der Stein verschoben werden?
            cout << "Bitte wählen Sie die Position, an die der Stein verschoben werden soll" << endl;
            cin >> targetPosition;//(getChip(targetPosition) == 'O')

            if (checkNeighbour(originPosition, targetPosition) == false && (player.lostChips > 6))
                continue; //Felder sind nicht benachbart und Springen ist noch nicht erlaubt

            //Mühleabfrage

        } while (getChip(targetPosition) != 'O'); // Position abfragen - ist das Feld frei?
        // oder nochmal probieren
        //Bedingung?
        //nach while: Zielposition besetzen?

        //Ursprungsposition zurücksetzen -> 'O'
        setChip(originPosition, 'O');

        // Stein auf gewählte Position setzen
        setChip(targetPosition, player.color);

    }
    /* if (checkMill(targetPosition)  ){
        string targetPosition;
        do{
        cout << "Wählen Sie einen gegnerischen Stein, um ihn zu entfernen." << endl;
        cin >> targetPosition;

        }while(getChip(targetPosition) != player.color && getChip(targetPosition) != 'O'){
            cout << "Auf dem gewählten Feld befindet sich kein gegnerischer Chip" <<endl;
        }
        
        //Chip entfernen
        setChip(targetPosition, 'O')
        
        //Stein entfernen


        //lostChips 
    } */
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