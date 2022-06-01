#include <iostream>
#include "speicher.h"
#include "gui.h"

//dies ist ein sickes Mühlespiel!!!!!
using namespace std;

struct player{
    int unusedChips;
    int lostChips;
    char color;
};

/*player black{
        this->unusedChips = 9
        this->lostChips = 0
        this->color = 'B'
}

player white {
    int unusedChips = 9;
    int lostChips = 0;
    char color = 'W';
}*/

void startTurn (player player)
{
        //Abfrage zu "Beginn" des Spiels: Sind noch Steine zum Setzen übrig?
        if (player.unusedChips > 0)
        {
            string position;

            do {

                //Spieler A soll die Position des Arrays angeben, an dem er den Stein plazieren will
                cout << "Bitte geben Sie die zu belegende Postion an!" << endl;

                //worin soll das gespeichert werden?
                cin >> position;

            }
            //Position abfragen - ist das Feld frei?
            while (getChip(position) != 'O');

            // Stein auf gewählte Position setzen
            setChip(position, player.color);

                  //cout:: //Spielfeld aktualisieren
                  player.unusedChips--;
        }
       /* else
        {
            //Stein wählen
            cout << "Bitte wählen Sie eine Position ihres Steins um ihn zu verschieben" << endl;
            cin >> //Arrayposition eingeben
            //neue Position wählen
            cout << "Bitte wählen Sie eine Position ihres Steins um ihn zu verschieben" << endl;
            cin >> //Neue Position angeben
            //Distanz prüfen (gültig nur wenn ToteSteine >= 6?)
            //Position frei?
            //Stein verschieben
            //oder nochmal probieren
        }*/

        //umliegende Felder prüfen - ist eine neue Mühle entstanden?

}


int main ()
{
    resetField();

    printField();

    cout << getChip ("C2");

    return 0;
}