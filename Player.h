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
    // UNUSED CHIPS
    int getUnusedChips();
    void decrementUnusedChip();
    // LOST CHIPS
    void loseChip();
    int getLostChips();
    char getColor();
    // NAME
    void setName(string);
    void generateName();
    string getName();
    // COLOR
    void setColor(char);
};

class Bot : public Player
{
private:
    // string globalMills[16][3];
    string globalMills[16][3] = {{"A0", "A1", "A2"},
                                 {"A2", "A3", "A4"},
                                 {"A4", "A5", "A6"},
                                 {"A6", "A7", "A0"},
                                 {"B0", "B1", "B2"},
                                 {"B2", "B3", "B4"},
                                 {"B4", "B5", "B6"},
                                 {"B6", "B7", "B0"},
                                 {"C0", "C1", "C2"},
                                 {"C2", "C3", "C4"},
                                 {"C4", "C5", "C6"},
                                 {"C6", "C7", "C0"},
                                 {"A1", "B1", "C1"},
                                 {"A3", "B3", "C3"},
                                 {"A5", "B5", "C5"},
                                 {"A7", "B7", "C7"},
                                 };

    //string neighbours[24][4];
    string neighbours[24][5] = {{"A0", "A1", "A7", "O", "O"},
                                {"A1", "A0", "A2", "B1", "O"},
                                {"A2", "A1", "A3", "O", "O"},
                                {"A3"}};

public:
    void fillGMarray();
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