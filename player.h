class Player //Erstelle eine Klasse namens Player
{
private:
    /* data */
public:

    int unusedChips;
    int lostChips;
    char color;
    Player(char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
}

};

