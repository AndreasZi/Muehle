#include <iostream>
#include "Board.cpp"
//#include "gui.h"
#include "Player.cpp"

// dies ist ein sickes Mühlespiel!!!!!
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

/*
    // Spielmodus auswählen: 1V1 OR 1VBot
    for (int i = 10; i > 1; i--)
    {
        cout << "Wie viele Menschen spielen hier mit??? (1 oder 2 eingeben)" << endl;
        int spieleranzahl;
        cin >> spieleranzahl;

        if (spieleranzahl == 2)
        {
            Player pBlack('B'); // Spieler pWhite ist ein Objekt der Klasse Spieler
            Player pWhite('W'); // Spieler pBlack ist ein Objekt der Klasse Spieler
            break;
        }
        else if (spieleranzahl == 1)
        {
            Player pBlack('B'); // Spieler pWhite ist ein Objekt der Klasse Spieler
            //Bot pWhite('W');    // Spieler pBlack ist ein Objekt der Klasse Spieler
            break;
        }
        else
        {
            cout << "Ihre Eingabe ist fehlerhaft, bitte erneut eingeben" << endl;
        }
    }
    */


    cout << "der Gewinner ist " << getWinner(pBlack, pWhite, b).getColor() << " Herzlichen Glückwunsch!";

    return 0;
}

Player getWinner(Player& p1, Player& p2, Board& board){
    //Partie wird gestartet
    while (1) //Läuft durch bis ein Spieler den Loop bricht.
    {   
        board.printBoard();
        startTurn(p1, board);
        if(p2.getLostChips() > 7){
            return p1;
        }
        board.printBoard();
        startTurn(p2, board);
        if(p1.getLostChips() > 7){
            return p2;
        }
    
    }

    // getWinner(p1)

}



void startTurn(Player &player, Board &b)
{
    string targetPosition;
    cout << "Spieler " << player.getColor() << " ist am Zug" << endl;
    // Abfrage zu "Beginn" des Spiels: Sind noch Steine zum Setzen übrig?
    if (player.getUnusedChips() > 0)
    {
        do
        {

            // Spieler A soll die Position des Arrays angeben, an dem er den Stein plazieren will
            cout << "Bitte geben Sie die zu belegende Postion an!" << endl;
            cin >> targetPosition; //erwartet wird ein String bestehend aus einem Buchstabe und einer Zahl

        } while (b.getChip(targetPosition[0], targetPosition[1]) != 'O'); // Position abfragen - ist das Feld frei?

        // Stein auf gewählte Position setzen
        b.setChip(targetPosition[0], targetPosition[1], player.getColor());

        // cout:: //Spielfeld aktualisieren
        player.decrementUnusedChip();
        cout << "Sie haben noch " << player.getUnusedChips() << " ungesetzte Steine" << endl;
    }
    else // Einen Stein vom aktuellen Spieler verschieben
    {
        string originPosition;

        do
        {
            // cin Ursprungsposition
            // cin Zielposition
            // Springen nicht erlaubt?
            // Nachbarfeld?
            // Feld frei?

            // Welcher Stein soll verschoben werden?
            cout << "Bitte wählen Sie eine Position ihres Steins, um ihn zu verschieben" << endl;
            cin >> originPosition;

            // Wohin soll der Stein verschoben werden?
            cout << "Bitte wählen Sie die Position, an die der Stein verschoben werden soll" << endl;
            cin >> targetPosition; //(getChip(targetPosition) == 'O')

            if (b.checkNeighbour(originPosition[0], originPosition[1], targetPosition[0], targetPosition[1]) == false && (player.getLostChips() > 6))
                continue; //Felder sind nicht benachbart und Springen ist noch nicht erlaubt

            // Mühleabfrage

        } while (b.getChip(targetPosition[0], targetPosition[1]) != 'O'); // Position abfragen - ist das Feld frei?
        // oder nochmal probieren
        // Bedingung?
        // nach while: Zielposition besetzen?

        //Ursprungsposition zurücksetzen -> 'O'
        b.setChip(originPosition[0], originPosition[1], 'O');

        // Stein auf gewählte Position setzen
        b.setChip(targetPosition[0], targetPosition[1], player.getColor());

    }
    if (b.checkMill(targetPosition[0], targetPosition[1])  ){
        do{
        cout << "Wählen Sie einen gegnerischen Stein, um ihn zu entfernen." << endl;
        cin >> targetPosition;

        }while(b.getChip(targetPosition[0], targetPosition[1]) == player.getColor() || b.getChip(targetPosition[0], targetPosition[1]) == 'O');
        //Gewähltes Feld ist kein gegnerchip
        
        //Chip entfernen
        b.setChip(targetPosition[0], targetPosition[1], 'O');
        //opponent lostChips ++
    }
}