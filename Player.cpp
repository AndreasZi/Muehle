#include "Player.h"
Player::Player(){

}
Player::Player(char COLOR)
{
    unusedChips = 9;
    lostChips = 0;
    color = COLOR;
    setName("unknown Player");
}
Player::Player(string NAME, char COLOR)
{
    unusedChips = 9;
    lostChips = 4;
    color = COLOR;
    setName(NAME);
}
void Player::startTurn()
{
}
void Player::loseChip()
{
    lostChips++;
}
void Player::setName(string NAME)
{
    name = NAME;
}
int Player::getLostChips()
{
    return lostChips;
}
char Player::getColor()
{
    return color;
}
void Player::setColor(char COLOR)
{
    color = COLOR;
}
int Player::getUnusedChips()
{
    return unusedChips;
}
void Player::decrementUnusedChip()
{
    unusedChips--;
}

// THIS IS WHERE BOT TERRITORY STARTS, MF------------------------------------------------------------

void Bot::fillGMarray()
{
    /* char orbit = A;
     int rotation = 0;
     for(int i = 0; i<16; i++){
         for(int j = 0; j<3; j++){
             globalMills[i][j] = A
         }
         cout << "rotation vor Inkrement: "<< rotation <<endl;
         orbit[0]++;
         cout << "rotation++: "<< rotation <<endl;
     }*/
}
void Bot::fillNeighbourArray()
{
}
string Bot::genereateChipPlacement()
{
    return "Work In Progress";
}
string Bot::genereateChipMovement()
{
    return "Work In Progress";
}
string Bot::generateRemoveChipPosition()
{
    return "Work In Progress";
}
void Bot::printTest(){
    cout<<"Sie haben den Bot erfolgreich AKTIVIERT" << endl;
}