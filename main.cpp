/*
Spiel Mühle:
• Regeln werden eingehalten
• Ich möchte gegen meine FreundIn spielen
• Ich möchte auch alleine Spielen können
• Ich möchte den aktuellen Spielstand sehen können
• Es soll Spaß machen
• git soll genutzt werden

Anforderungen die HART sind:
• Kommentare müssen vorhanden sein
• Dokumentation
*/
//unschuldiger Testcommentar
#include <iostream>
#include "Board.cpp"
#include "Player.cpp"
#include <tuple>
#include <vector>

// dies ist ein sickes Mühlespiel!
using namespace std;

// FUNKTIONEN FÜR BOT MÜSSEN ÜBER MAIN ABGEWICKELT WERDEN
// EG: FELDSCANS MÜSSEN ÜBER MAIN LAUFEN, BOT KANN NICHT DIREKT AUF BOARD ZUGREIFEN

// Funktion die den Ablauf eines Zuges Beschreibt
void startTurn(Player &, Board &);

// Das tatsächliche Spiel wird gespielt. Am Ende wird der Gewinner returnt
Player getWinner(Player &, Player &, Board &);

int main()
{

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
            Board b;            // Spielfeld auf dem die Partie gspielt werden soll

            char winner = getWinner(pBlack, pWhite, b).getColor();
            cout << "der Gewinner ist " << winner << " Herzlichen Glückwunsch!" << endl;

            break;
        }
        else if (spieleranzahl == 1)
        {
            Player pBlack('B'); // Spieler pWhite ist ein Objekt der Klasse Spieler
            Bot pWhite('W');    // Spieler pBlack ist ein Objekt der SubKlasse Bot
            Board b;            // Spielfeld auf dem die Partie gspielt werden soll

            cout << "Sie haben den Singleplayer-Modus gewählt!!!" << endl;

            char winner = getWinner(pBlack, pWhite, b).getColor();
            cout << "der Gewinner ist " << winner << " Herzlichen Glückwunsch!" << endl;

            if (winner == 'W')
            {
                cout << "Leider hattest Du gegen unseren megastarken Bot keine Chance =(" << endl;
            }

            break;
        }
        else
        {
            cout << "Fehlerhafte Eingabe! Bitte die Zahl 1 oder 2 eingeben!" << endl;
        }
    }

    // char winner = getWinner(pBlack, pWhite, b).getColor();
    // cout << "der Gewinner ist " << winner << " Herzlichen Glückwunsch!";
    return 0;
}
Player getWinner(Player &p1, Player &p2, Board &board)
{
    // Partie wird gestartet

    while (true)
    // Loop wird unterbrochen, wenn ein Spieler verliert (nur noch 2 Steine hat)
    {
        // Zug wird für Spieler 1 ...
        startTurn(p1, board);
        if (p2.getLostChips() >= 7)
        {
            // Spieler 2 hat verloren, Spieler 1 wird als Gewinner returned
            return p1;
        }

        // ...und für Spieler 2 ausgeführt
        startTurn(p2, board);
        if (p1.getLostChips() >= 7)
        {
            // Spieler 1 hat verloren, Spieler 2 wird als Gewinner returned
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

    // Wird ausgeführt, wenn der Bot spielt
    if (player.isBot)
    {
        cout << "Der Bot ist am Zug" << endl;
    }
    else
    {
        // Der Spieler, welcher am Zug ist, wird benannt
        cout << "Spieler " << player.getColor() << " ist am Zug" << endl;
    }

    // Abfrage zu "Beginn" des Spiels: Sind noch Steine zum Setzen übrig?
    if (player.getUnusedChips() > 0)
    {
        // Der Spieler hat noch ungesetzte Steine, die er auf freie Felder setzten darf

        do
        {
            if (player.isBot == false)
            {
                // Spieler A soll die Position des Arrays angeben, an dem er den Stein plazieren will
                cout << "Bitte geben Sie die zu belegende Postion an!" << endl;
                cin >> targetPosition; // erwartet wird ein String bestehend aus einem Buchstabe und einer Zahl
            }
            else
            {

                // Position von board erfragen
                targetPosition = b.generateChipPlacement();

                cout << "Der Bot setzt einen Chip auf: " << b.generateChipPlacement() << endl;
            }

        }
        // Position abfragen - ist das Feld frei?
        while (b.getChip(targetPosition[0], targetPosition[1]) != b.getEmptyColor());

        // Stein auf gewählte Position setzen
        b.setChip(targetPosition[0], targetPosition[1], player);

        player.decrementUnusedChip();

        if(player.isBot){
            cout << "Der Bot hat noch " << player.getUnusedChips() << " ungesetze Steine" << endl;
        }else {

            cout << "Sie haben noch " << player.getUnusedChips() << " ungesetzte Steine" << endl;
        }
        
    }
    else
    {
        // Einen Stein vom aktuellen Spieler verschieben
        string originPosition;
        bool neighbourCondition;

        do
        {
            if (player.isBot)
            {
                //Koordinaten für Verschiebung von Bot erfragen
                //!!!!!!!!Hier passieren Fehler mit dem Speicherzugriff!!!!!!!!!!!!!!!!!!
                tuple<string, string> movingCoordinates = b.generateChipMovement(player.getColor());
                // TUPLE MUSS IN ORIGIN UND TARGET ÜBERFÜHRT WERDEN
                originPosition = get<0>(movingCoordinates);
                targetPosition = get<1>(movingCoordinates);

                cout << "Der Bot verschiebt einen Chip von " << originPosition << " nach " << targetPosition << endl;
            }
            else
            {
                // Welcher Stein soll verschoben werden?
                cout << "Ursprungsposition des zu verschiebenden Steins wählen" << endl;
                cin >> originPosition;

                // Wohin soll der Stein verschoben werden?
                cout << "Zielposition eingeben" << endl;
                cin >> targetPosition;
            }
            //
            if (player.getLostChips() == 6)
            {
                // Wenn der Spieler nur noch 3 Chips hat, ist die neighbourCondition immer erfüllt
                neighbourCondition = true;
            }
            else
            {
                // Wenn der Spieler mehr als 3 Chips hat muss geprüft werden, ob das gewählte Feld ein Nachbarfeld ist

                while (neighbourCondition == false)
                {

                    neighbourCondition = b.checkNeighbour(originPosition[0], originPosition[1], targetPosition[0], targetPosition[1]);

                    if (neighbourCondition == true)
                    {
                        break;
                    }
                    else
                    {
                        // FEHLER: targetPosition ist kein Nachbarfeld oder Besetzt --> loop wiederholen
                    }
                }
            }

        }
        // Das Ursprungsfeld muss vom Spieler besetzt sein, das Zielfeld muss leer sein, das Zielfeld darf nur einen Schritt entfernt sein - andernfalls werden die obigen Schritte wiederholt
        while (b.getChip(originPosition[0], originPosition[1]) != player.getColor() || b.getChip(targetPosition[0], targetPosition[1]) != b.getEmptyColor() || !neighbourCondition);

        // Ursprungsposition zurücksetzen -> b.getEmptyColor(
        b.deleteChip(originPosition[0], originPosition[1]);

        // Stein auf gewählte Position setzen
        b.setChip(targetPosition[0], targetPosition[1], player);
    }
    if (b.checkMill(targetPosition[0], targetPosition[1]))
    {
        // Der gesetzte oder verschobene Stein bildet eine Mühle :-)
        b.printBoard();

        do
        {
            if (player.isBot)
            {
                if (player.getColor() == 'W')
                {

                    targetPosition = b.generateChipDeletion('B');
                }
                else
                {
                    targetPosition = b.generateChipDeletion('W');
                }
            }
            else
            {
                // Die Position des zu entfernenden Steins wird eingelesen
                cout << "Wählen Sie einen gegnerischen Stein, um ihn zu entfernen." << endl;
                cin >> targetPosition;
            }
        }
        // Wird wiederholt solange man keinen Gengerchip ausgewählt hat || der ausgewählte Gegnerchip einer geschlossenen Mühle angehört
        // LEIDER WERDEN KEINE FEHLERCODES AUSGEGEBEN
        while (b.getChip(targetPosition[0], targetPosition[1]) == player.getColor() || b.getChip(targetPosition[0], targetPosition[1]) == b.getEmptyColor() || b.checkMill(targetPosition[0], targetPosition[1]));

        // Gegnerische LostChips werden erhöht

        b.getPlayer(targetPosition[0], targetPosition[1])->loseChip();

        // Gegnerchip wurde ausgewählt und entfernt -> Feld ist nun leer (O) und Spieler verliert einen Stein
        b.deleteChip(targetPosition[0], targetPosition[1]);
    }
}
