class Player
{
private:
    /* data */
public:
    int unusedChips;
    int lostChips;
    char character;
    Player(unsigned char character)
{
    unusedChips = 9;
    lostChips = 0;
    character = character;
}


};
