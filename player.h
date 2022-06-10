class Player //Erstelle eine Klasse namens Player
{
private:
    /* data */
public:

    int unusedChips;
    int lostChips;
    char color;
    Player(char);

    void startTurn();
    void loseChip();
    char getColor();

};


Player::Player(char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
}

void Player::startTurn(){

}

void Player::loseChip(){

}

class Bot: public Player
{
private:
    /* data */
public:
    Bot(/* args */);
    ~Bot();
};

Bot::Bot(/* args */)
{
}

Bot::~Bot()
{
}
