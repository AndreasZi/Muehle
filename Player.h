#ifndef PLAYERH
#define PLAYERH

#include <iostream>
#include <string>
using namespace std;



class Player
{
private:
    
    int unusedChips;
    int lostChips;
    char color;

public:
    string name;
    // Constructors
    Player();
    Player(char);
    Player(string, char);
    // Functions
    void startTurn();
    //UNUSED CHIPS
    int getUnusedChips();
    void decrementUnusedChip();
    //LOST CHIPS
    void loseChip();
    int getLostChips();
    char getColor();
    //NAME
    void setName(string);
    void generateName();
    string getName();
    //COLOR
    void setColor(char);
};

class Bot : public Player
{
private:
    string globalMills[16][3];
    string neighbours[24][4];

public:
    void fillGMarray(void);
    void fillNeighbourArray(void);

    // SCHNITSTELLE MAIN-BOT NOCH UNKLAR
    string genereateChipPlacement();
    string genereateChipMovement();
    string generateRemoveChipPosition();

    void printTest();

    Bot(char COLOR) : Player(COLOR)
    {
        setName("Bot");
        fillGMarray();
        fillNeighbourArray();
    }
};

#endif