#include "Board.h"


Board::Board(/* args */)
{
    empty.setColor('O');
    //*cells = ;
    emptyBoard();
}





void Board::setChip(char orbit, char rotation, Player player)
{
    // Setter, um den Wert des Arrays cells an der Stelle coordinate (zb. "A0") auf den Wert color (zb. 'W') zu setzen.
    cells[int(orbit)-65][int(rotation)-48] = player;
}


char Board::getChip(char orbit, char rotation)
{
    // Getter, der den Wert des Arrays cells an der Stelle coordinate (zb. "A0") zu returnt.
    return cells[int(orbit)-65][int(rotation)-48].getColor();
}

void Board::emptyBoard()
{   
    //Alle Felder mit Char 'O' zu füllen
    Player* ptr = &cells[0][0]; //pointer um die Mehrdimensionalität zu überspringen
    for(int i = 0; i < 24; i++){
        *(ptr + i) = empty;
    } 
}


int Board::checkMill(char orbit, char rotation)
{
    if(getChip(orbit,rotation)=='O'){
        return 0;
    }
    // Coordinates from A0 to C7/    
    if (int(rotation) % 2 == 0)//  Checking if stone is placed in corner
    {
        if ((rotation == '0' || rotation == '6'))
        //Ausnahme für Nulldurchgang:
        {
            // Der Chip liegt auf Feld 0, 7 oder 6
            if(getChip(orbit, '0') == getChip(orbit, '7') && getChip(orbit, '6') == getChip(orbit, '7'))
            // 0, 7 und 6 sind von gleichfarbigen Steinen besetzt.
            {
                return 1;
            }
        }
        if (getChip(orbit,rotation) == getChip(orbit, rotation + 1) && getChip(orbit,rotation) == getChip(orbit, rotation + 2) && rotation != '6')
        //+dir Standardprüfung für Ecksteine
        {
            // der IM Uhrzeigersinn befindliche Nachbar, sowie dessen Nachbar sind gleich der Farbe des gesetzten Steins
            return 1;
        }

        if (getChip(orbit,rotation) == getChip(orbit, rotation - 1) && getChip(orbit,rotation) == getChip(orbit, rotation - 2) && rotation != '0')
        //-dir Standardprüfung für Ecksteine
        {
            // der GEGEN den Uhrzeigersinn befindliche Nachbar, sowie dessen Nachbar sind gleich der Farbe des gesetzten Steins
            return 1;
        }
    }
    else
    {
        // Der neugesetzte Stein ist ein Mittelstein
        
        if (getChip('A', rotation) == getChip('B', rotation) && getChip('B', rotation) == getChip('C', rotation))
        // Mühle auf Steg
        {
            // Alle Steine auf dem Betroffenen Steg sind gleichfarbig.
            return 1;
        }
        // checking for tangential mill
        if (rotation == '7')
        //Ausnahme für Nulldurchgang:
        {
            // Der Chip liegt auf Feld 0, 7 oder 6
            if(getChip(orbit, '0') == getChip(orbit, '7') && getChip(orbit, '6') == getChip(orbit, '7'))
            // 0, 7 und 6 sind von gleichfarbigen Steinen besetzt.
            {
                return 1;
            }
        }
        else if (getChip(orbit,rotation) == getChip(orbit, rotation - 1) && getChip(orbit,rotation) == getChip(orbit, rotation + 1))
        // Mühle auf dem Rechteck
        {
            cout << orbit << ", " << rotation << ", " << getChip(orbit,rotation) << "; " << orbit << ", " << rotation - 1 << ", "  << getChip(orbit, rotation - 1)  << "; " << orbit << ", " << rotation + 1 << ", " << getChip(orbit, rotation + 1) << endl ;
            // Farbe des neugestzten Steins ist gleich den auf den Nachbarfeldern auf dem jeweilligen Rechteck
            return 1;
        }
    }

    
    if ((rotation == '0' || rotation == '7'|| rotation == '6'))
    //Ausnahme für Nulldurchgang:
    {
        // Der Chip liegt auf Feld 0, 7 oder 6
        if(getChip(orbit, '0') == getChip(orbit, '7') && getChip(orbit, '6') == getChip(orbit, '7'))
        // 0, 7 und 6 sind von gleichfarbigen Steinen besetzt.
        {
            return 1;
        }
    }
    return 0;
}
bool Board::checkNeighbour(char orbitOrigin, char rotationOrigin, char orbitTarget, char rotationTarget)
{
    // Checking for same orbit (A == A?)
    if (orbitOrigin == orbitTarget)
    {
        // AX-AY ==1 DISTANZ
        if (abs(rotationOrigin - rotationTarget) == 1 || abs(rotationOrigin - rotationTarget) == 7)
        {
            // EXCEPTION für Ecksteine FOR X0 & X7
            return true;
            
        }/* 
        else if (rotationOrigin == 0 && rotationTarget == 7 || rotationOrigin == 7 && rotationTarget == 0)
        {
            return true;
        } */
    }
    else if (rotationOrigin == rotationTarget && rotationOrigin%2 != 0)
    {
        // Cases: AB BC  BA CB
        if (abs(orbitOrigin - orbitTarget) == 1)
        {
            return true;
        }
    }
    return false;
    
}


void Board::printBoard(){
    cout << "Mühle:" << endl;
    cout << getChip('A','0') << "------------" << getChip('A','1') <<"------------"<<getChip('A','2')<<"       " <<"A0" << "------------" << "A1" <<"-----------"<<"A2"<< endl;
    cout <<"|" <<"            " <<"|"<< "            "<<"|"<<"       "<<"|" <<"             " <<"|"<< "            "<<"|"<< endl;
    cout <<"|    "<< getChip('B','0')<< "-------" << getChip('B','1') <<"-------"<<getChip('B','2')<< "    |"<<"       "<<"|    "<< "B0"<< "-------" << "B1" <<"-------"<<"B2"<< "  |"<<endl;
    cout <<"|" <<"    |       " <<"|"<< "       |  "<<"  |"<<"       "<<"|" <<"    |        " <<"|"<< "        | "<<"  |"<<endl; 
    cout <<"|    |   "<<getChip('C','0')<<"---"<<getChip('C','1')<<"---"<<getChip('C','2')<<"   |"<<"    |"<<"       "<<"|    |   "<<"C0"<<"---"<<"C1"<<"---"<<"C2"<<"  |"<<"   |"<<endl;
    cout <<"|" <<"    |   |       |   |  "<<"  |"<< "       "<<"|" <<"    |   |          |  |  "<<" |"<< endl;
    cout <<getChip('A','7')<<"----"<<getChip('B','7')<<"---"<<getChip('C','7')<<"       "<<getChip('C','3')<<"---"<<getChip('B','3')<<"----"<<getChip('A','3')<<"       "<<"A7"<<"---"<<"B7"<<"-"<<"C7"<<"         "<<"C3"<<"-"<<"B3"<<"---"<<"A3"<<endl;
    cout <<"|" <<"    |   |    " <<" "<< "  |   |  "<<"  |"<<"       "<<"|" <<"    |   |          |  |  "<<" |"<< endl;
    cout <<"|    |   "<<getChip('C','6')<<"---"<<getChip('C','5')<<"---"<<getChip('C','4')<<"   |"<<"    |"<<"       "<<"|    |   "<<"C6"<<"---"<<"C5"<<"---"<<"C4"<<"  |"<<"   |"<<endl;
    cout <<"|" <<"    |       " <<"|"<< "       |  "<<"  |"<<"       "<<"|" <<"    |        " <<"|"<< "        |  "<<" |"<< endl;
    cout <<"|    "<< getChip('B','6')<< "-------" << getChip('B','5') <<"-------"<<getChip('B','4')<< "    |"<<"       "<<"|    "<< "B6"<< "-------" << "B5" <<"-------"<<"B4"<< "  |"<<endl;
    cout <<"|" <<"            " <<"|"<< "            "<<"|"<<"       "<<"|" <<"             " <<"|"<< "           "<<" |"<< endl;
    cout << getChip('A','6')<< "------------" << getChip('A','5') <<"------------"<<getChip('A','4')<<"       "<<"A6"<< "------------" << "A5" <<"-----------"<<"A4"<< endl;
    }

    

