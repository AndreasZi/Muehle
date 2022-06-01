#include <iostream>
using namespace std;

//map positions;
char field[3][8];




void setChip(string, char);

void moveChip(string);

void checkMill(string); //Überprüfen ob eine Mühle erzeugt wurde

char getChip(string); //Farbe (oder leer) eines Felds erfassen



void setChip(string coordinate, char color){
    field[int(coordinate[0])-65][coordinate[1]] = color; //field Array an der Stelle "BuchstabeZahl" den Char color zuweisen
}

char getChip(string coordinate){
    return field[int(coordinate[0])-65][coordinate[1]];
}


void resetField (){
    //Feld leeren (mit 'O's füllen)
    string a = "A0";
    while(a[0] != 'D'){ //Alle Buchstaben von A bis C
        while(a[1] != '8'){ //Alle Zahlen von 0 bis 7
            setChip(a, 'O'); // Feld auf 'O' setzen
            a[1]++; //Zahl um 1 ERhöhen
        }
        a[1]='0'; //Zahl zurück auf 0 setzen
        a[0]++; //Buchstabe erhöhen
    }
}
