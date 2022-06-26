/* 
Spiel Mühle:
• Regeln werden eingehalten
• Ich möchte gegen meine Freundin spielen
• Ich möchte auch alleine Spielen können
• Ich möchte den aktuellen Spielstand sehen können
• Es soll spaß machen
• git soll genutzt werden

Anforderungen die HART sind:
• Kommentare müssen vorhanden sein
• Dokumentation 
*/

#include <iostream>
#include "Board.cpp"
//#include "gui.h"
#include "Player.cpp"

// dies ist ein sickes Mühlespiel!
using namespace std;

// FUNKTIONEN FÜR BOT MÜSSEN ÜBER MAIN ABGEWICKELT WERDEN
// EG: FELDSCANS MÜSSEN ÜBER MAIN LAUFEN, BOT KANN NICHT DIREKT AUF BOARD ZUGREIFEN



//Funktion die den Ablauf eines Zuges Beschreibt
void startTurn(Player&, Board&);

//Das tatsächliche Spiel wird gespielt. Am Ende wird der Gewinner returnt
Player getWinner(Player&, Player&, Board&);

int main()
{
    Player pBlack('B'); // Spieler pWhite ist ein Objekt der Klasse Spieler
    Player pWhite('W'); // Spieler pBlack ist ein Objekt der Klasse Spieler
    Board b; // Spielfeld auf dem die Partie gspielt werden soll

    //Bot testingBOT('T');
    //testingBOT.printTest();


    // Spielmodus auswählen: 1 vs. 1 || 1 vs. Bot
    for (int i = 10; i > 1; i--)
    {
        cout << "Bitte Spielmodul wählen!\n [1] = Singleplayer\n [2] = Multiplayer" << endl;
        int spieleranzahl;
        cin >> spieleranzahl;

        if (spieleranzahl == 2)
        {
            Player pBlack('B'); // Spieler pWhite ist ein Objekt der Klasse Spieler
            Player pWhite('W'); // Spieler pBlack ist ein Objekt der Klasse Spieler
            break;
        }

/*         else if (spieleranzahl == 1)
        {
            Player pBlack('B'); // Spieler pWhite ist ein Objekt der Klasse Spieler
            //Bot pWhite('W');    // Spieler pBlack ist ein Objekt der Klasse Spieler
            break;
        } */
    else
        {
            cout << "Fehlerhafte Eingabe! Bitte die Zahl 1 oder 2 eingeben!" << endl;
        }
    }

    char winner = getWinner(pBlack, pWhite, b).getColor();

    cout << "der Gewinner ist " << winner << " Herzlichen Glückwunsch!";

    return 0;
}

Player getWinner(Player& p1, Player& p2, Board& board)
{
    // Partie wird gestartet

    while (true)
    // Loop wird unterbrochen, wenn ein Spieler verliegt (nur noch 2 Steine hat)
    {
        // Zug wird für Spieler 1 ...
        startTurn(p1, board);
        if(p2.getLostChips() >= 7)
        {
            // Spieler 2 hat verloren, Spieler 1 wird als Gewinner returned
            return p1;
        }

        // ...und für Spieler 2 ausgeführt
        startTurn(p2, board);
        if(p1.getLostChips() >= 7)
        {
            //Spieler 1 hat verloren, Spieler 2 wird als Gewinner returned
            return p2;
        }
    
    }

}



void startTurn(Player &player, Board &b)
{
    // Das aktuelle Spielfeld wird dargestellt
    b.printBoard();

    // targetPosition wird für alle Fälle benötigt
    string targetPosition;

    // Der Spieler, welcher am Zug ist, wird benannt
    cout << "Spieler " << player.getColor() << " ist am Zug" << endl;

    // Abfrage zu "Beginn" des Spiels: Sind noch Steine zum Setzen übrig?
    if (player.getUnusedChips() > 0)
    {
        // Der Spieler hat noch ungesetzte Steine, die er auf freie Felder setzten darf
        do
        {

            // Spieler A soll die Position des Arrays angeben, an dem er den Stein plazieren will
            cout << "Bitte geben Sie die zu belegende Postion an!" << endl;
            cin >> targetPosition; // erwartet wird ein String bestehend aus einem Buchstabe und einer Zahl
        } 
        // Position abfragen - ist das Feld frei?
        while (b.getChip(targetPosition[0], targetPosition[1]) != b.getEmptyColor());

        // Stein auf gewählte Position setzen
        b.setChip(targetPosition[0], targetPosition[1], player);

        player.decrementUnusedChip();
        cout << "Sie haben noch " << player.getUnusedChips() << " ungesetzte Steine" << endl;
    }
    else 
    {
        // Einen Stein vom aktuellen Spieler verschieben
        string originPosition;
        bool neighbourCondition;

        do
        {
            // Welcher Stein soll verschoben werden?
            cout << "Ursprungsposition des zu verschiebenden Steins wählen" << endl;
            cin >> originPosition;

            // Wohin soll der Stein verschoben werden?
            cout << "Zielposition eingeben" << endl;
            cin >> targetPosition;

            //
            if (player.getLostChips() == 6)
            {
                // Wenn der Spieler nur noch 3 Chips hat, ist die neighbourCondition immer erfüllt
                neighbourCondition = true;
            }
            else
            {
                // Wenn der Spieler mehr als 3 Chips hat muss geprüft werden, ob das gewählte Feld ein Nachbarfeld ist
                neighbourCondition = b.checkNeighbour(originPosition[0], originPosition[1], targetPosition[0], targetPosition[1]);
            }
           
        } 
        // Das Ursprungsfeld muss vom Spieler besetzt sein, das Zielfeld muss leer sein, das Zielfeld darf nur einen Schritt entfernt sein - andernfalls werden die obigen Schritte wiederholt
        while (b.getChip(originPosition[0], originPosition[1]) != player.getColor()||b.getChip(targetPosition[0], targetPosition[1]) != b.getEmptyColor()||!neighbourCondition);

        // Ursprungsposition zurücksetzen -> b.getEmptyColor(
        b.deleteChip(originPosition[0], originPosition[1]);

        // Stein auf gewählte Position setzen
        b.setChip(targetPosition[0], targetPosition[1], player);

    }
    if (b.checkMill(targetPosition[0], targetPosition[1]))
    {
        // Der gesetzte oder verschobene Stein bildet eine Mühle :-) 
        do{
        // Die Position des zu entfernenden Steins wird eingelesen
        cout << "Wählen Sie einen gegnerischen Stein, um ihn zu entfernen." << endl;
        cin >> targetPosition;
        }
        // Wird wiederholt solange man keinen Gengerchip ausgewählt hat || der ausgewählte Gegnerchip einer geschlossenen Mühle angehört
        while(b.getChip(targetPosition[0], targetPosition[1]) == player.getColor() || b.getChip(targetPosition[0], targetPosition[1]) == b.getEmptyColor()|| b.checkMill(targetPosition[0], targetPosition[1]));

        // Gegnerische LostChips werden erhöht

        b.getPlayer(targetPosition[0], targetPosition[1])->loseChip();

        // Gegnerchip wurde ausgewählt und entfernt -> Feld ist nun leer (O) und Spieler verliert einen Stein
        b.deleteChip(targetPosition[0], targetPosition[1]);
    }
}