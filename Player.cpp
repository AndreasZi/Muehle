#include "Player.h"

Player::Player(char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
}
Player::Player(string NAME, char COLOR)
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
void Player::setName(string NAME)
{
    name = NAME;
}

//THIS IS WHERE BOT-TERRITORY STARTS---------------------------------------------------------------------------------------

void Bot::fillGMarray()
{
}
void Bot::fillNeighbourArray()
{
}

void Bot::placeChip()
{
}
void Bot::moveChip()
{
}