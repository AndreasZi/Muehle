#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
#include <vector>
#include <tuple>
#include "Player.h"
using namespace std;


class Board
{
private:
    Player empty;
    Player *cells[3][8]; // Zweidimensionales Array, welches die Werte 'O', 'W' und 'B' speichern soll.
public:

    Board();

    string Neighbours[4];
    
    void setChip(char, char, Player&);
    //Platziere einen Chip auf einem Feld des Spielfelds
    
    char getChip(char, char);
    //Gibt die Farbe des Spielers zurück, dem der Chip an einer gewissen Position gehört

    Player* getPlayer(char, char);
    //Gibt den Spieler zurück, dem der Chip an einer gewissen Position gehört

    char getEmptyColor();

    void emptyBoard();
    //Funktion zum Bereinigen des gesamten Spielfelds
    
    void deleteChip(char, char);
    //Funktion zum Bereinigen eines einzelnen Felds

    void printBoard();
    //Funktion zur graphischen Darstellung des Spielfelds

    int checkMill(char, char);
    //Prüft ob ein Feld Teil einer Mühle ist

    bool checkNeighbour(char, char, char, char);
    //Prüft ob zwei Felder benachbart sind

    tuple<string, string, string, string> getNeighbours(string);
    void printNeighbours(string);

    //BOT Funktionen
    string generateChipPlacement();
    tuple<string, string> generateChipMovement(char);
    string generateChipDeletion(char);

};
#endif