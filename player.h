class Player // Erstelle eine Klasse namens Player
{
private:
    /* data */
    string name;

public:
    int unusedChips;
    int lostChips;
    char color;
    Player(char);

    void startTurn();
    void loseChip();
    char getColor();
    string generateName();
    void setName(string);
    string getName();
};
#include <iostream>
using namespace std;

Player::Player(char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
    // name = generateName();
}
Player::Player(string NAME; char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
    setName(NAME);
}

void Player::startTurn()
{
}

void Player::loseChip()
{
}

class Bot : public Player
{
private:
    // char generateColor(); //Immer anders als Spieler

    // ARRAY der globalen Mühlen | 16 Mühlen a 3 Chips
    string globalMills[16][3];
    // ARRAY der Nachbarn | 24 ChipPlacements with max. 4 Neighbours
    string neighbours[24][4];

    void fillGMarray();
    void fillNeigbourArray();

public:
    Bot();
    //~Bot();

    void placeChip();
    void moveChip();
    string getRemoveChipPosition();
};

Bot::Bot(char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
    name = 'Bot';
    fillGMarray();
    fillNeighbourArray();
}

Bot::Bot()
{
    unusedChips = 9;
    lostChips = 0;
    // color = generateColor();
    name = 'Bot';
    fillGMarray();
    fillNeighbourArray();
}

/*Bot::~Bot(){

}*/

// AB HIER KOMMT ALLES IN Bot.cpp---------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

fillGMarray()
{
}
fillNeighbourArray()
{
}

void placeChip()
{
}
void moveChip()
{
}

// HIER ENDET Bot.cpp-----------------------------------------------------------------------------------------------------