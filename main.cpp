#include <iostream>
#include "Board.cpp"
//#include "gui.h"
#include "Player.cpp"

// dies ist ein sickes Mühlespiel!
using namespace std;

// FUNKTIONEN FÜR BOT MÜSSEN ÜBER MAIN ABGEWICKELT WERDEN
// EG: FELDSCANS MÜSSEN ÜBER MAIN LAUFEN, BOT KANN NICHT DIREKT AUF BOARD ZUGREIFEN



//Funktion die den Ablauf eines Zuges Beschreibt
bool startTurn(Player&, Board&);

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
        if (startTurn(p1, board))
        // Zug wird gestartet
        {
            // Eine Mühle wurde erkannt, der Gegner verliert einen Stein
            p2.loseChip();
        }

        if(p2.getLostChips() >= 7)
        {
            // Spieler 2 hat verloren, Spieler 1 wird als Gewinner returned
            return p1;
        }

        // ...und für Spieler 2 ausgeführt
        if (startTurn(p2, board))
        // Zug wird gestartet
        {
            // Eine Mühle wurde erkannt, der Gegner verliert einen Stein
            p1.loseChip();
        }
        if(p1.getLostChips() >= 7)
        {
            //Spieler 1 hat verloren, Spieler 2 wird als Gewinner returned
            return p2;
        }
    
    }

}



bool startTurn(Player &player, Board &b)
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
        while (b.getChip(targetPosition[0], targetPosition[1]) != 'O');

        // Stein auf gewählte Position setzen
        b.setChip(targetPosition[0], targetPosition[1], player.getColor());

        player.decrementUnusedChip();
        cout << "Sie haben noch " << player.getUnusedChips() << " ungesetzte Steine" << endl;
    }
    else 
    {
        // Einen Stein vom aktuellen Spieler verschieben
        string originPosition;

        do
        {
            // Welcher Stein soll verschoben werden?
            cout << "Ursprungsposition des zu verschiebenden Steins wählen" << endl;
            cin >> originPosition;

            // Wohin soll der Stein verschoben werden?
            cout << "Zielposition eingeben" << endl;
            cin >> targetPosition;
        } 
        // Das Ursprungsfeld muss vom Spieler besetzt sein, das Zielfeld muss leer sein, das Zielfeld darf nur einen Schritt entfernt sein - andernfalls werden die obigen Schritte wiederholt
        while (b.getChip(originPosition[0], originPosition[1]) != player.getColor()||b.getChip(targetPosition[0], targetPosition[1]) != 'O'||!b.checkNeighbour(originPosition[0], originPosition[1], targetPosition[0], targetPosition[1])); // Position abfragen - ist das Feld frei?

        // Ursprungsposition zurücksetzen -> 'O'
        b.setChip(originPosition[0], originPosition[1], 'O');

        // Stein auf gewählte Position setzen
        b.setChip(targetPosition[0], targetPosition[1], player.getColor());

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
        while(b.getChip(targetPosition[0], targetPosition[1]) == player.getColor() || b.getChip(targetPosition[0], targetPosition[1]) == 'O'|| b.checkMill(targetPosition[0], targetPosition[1]));

        // Gegnerchip wurde ausgewählt und entfernt -> Feld ist nun leer (O)
        b.setChip(targetPosition[0], targetPosition[1], 'O');

        // Mit "return true" wird eine gefundene Mühle signalisiert
        return true;
    }
    // Falls keine Mühle gefunden wird, wird "false" returned
    return false;
}