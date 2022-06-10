class Player //Erstelle eine Klasse namens Player
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


Player::Player(char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
    //name = generateName();
}
Player::Player(string NAME; char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
    setName(NAME);
}

void Player::startTurn(){

}

void Player::loseChip(){

}

class Bot: public Player
{
private:

    char generateColor(); //Immer anders als Spieler
public:
    Bot();
    //~Bot();

    void placeChip();
    void moveChip();
};

Bot::Bot(char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
}

Bot::Bot()
{
    unusedChips = 9;
    lostChips = 0;
    color = generateColor();
}

/*Bot::~Bot(){

}*/
