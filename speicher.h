#include <iostream>
using namespace std;

//map positions;
char field[3][8] = {{'O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O'}};




void resetField ()
{
    for (int c = 0; c <= 2; ++c) {
        for (int i = 0; i <= 7; i++) {

            field[c][i] = 'O';
        }
    }
}

void setChip(string, char);

void moveChip(string);

void checkMill(string); //Überprüfen ob eine Mühle erzeugt wurde

char getChip(string); //Farbe (oder leer) eines Felds erfassen






void setChip(string coordinate, char color){
    field[int(coordinate[0])-65][coordinate[1]] = color;
}

char getChip(string coordinate){
    return field[int(coordinate[0])-65][coordinate[1]];
}