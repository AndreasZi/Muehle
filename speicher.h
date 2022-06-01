#include <iostream>
using namespace std;

//map positions;
char field[3][8]; //= {{'O'}};




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


void resetField (){
    string a = "A0";
    while(a[0] != 'D'){
        while(a[1] != '8'){
        
            setChip(a, 'O');
            a[1]++;
        }
        a[1]='0';
        a[0]++;
    }
}
