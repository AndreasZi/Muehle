#include <iostream>
using namespace std;

//map positions;
char field[3][8] = {'a'};






void setStone(string, char);

void moveStone(string);

void checkMill(string); //Überprüfen ob eine Mühle erzeugt wurde

char getStone(string); //Farbe (oder leer) eines Felds erfassen






void setStone(string coordinate, char color){
    field[int(coordinate[0])-65][coordinate[1]] = color;
}

char getStone(string coordinate){
    return field[int(coordinate[0])-65][coordinate[1]];
}