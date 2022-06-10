#include <iostream>
using namespace std;
class Player
{
private:
    string name;

public:
    int unusedChips;
    int lostChips;
    char color;
    Player(char);
    Player(string, char);

    void startTurn();
    void loseChip();
    char getColor();
    string generateName();
    void setName(string);
    string getName();
};

class Bot : public Player
{
private:
    string globalMills[16][3];
    string neighbours[24][4];

public:
    void fillGMarray(void);
    void fillNeighbourArray(void);

    void placeChip();
    void moveChip();
    string getRemoveChipPosition();

    Bot(char COLOR) : Player(COLOR)
    {
        setName("Bot");
        fillGMarray();
        fillNeighbourArray();
    }
};
