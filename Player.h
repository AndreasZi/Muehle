#include <list>
class Player //Erstelle eine Klasse namens Player
{
private:
    list<Chip> chips;
    char color;
public:
    Player(char);
    void startTurn(int&);
    char getColor(void);
};
