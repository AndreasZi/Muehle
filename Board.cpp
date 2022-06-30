#include "Board.h"


Board::Board(/* args */)
{
    //Leerem "Player" einen Char zuweisen
    empty.setColor('O');

    //Spielfeld vor Spielstart leeren
    emptyBoard();
}

char Board::getEmptyColor(){
    //Der für leere Felder gewählte Char wird zurückgegeben
    return empty.getColor();
}



void Board::setChip(char orbit, char rotation, Player &player)
{
    // Setter, um einem Spielfeld einen Spieler-Pointer zuzuweisen.
    cells[int(orbit)-65][int(rotation)-48] = &player;
}

void Board::deleteChip(char orbit, char rotation)
{
    //Feld Leeren.
    cells[int(orbit)-65][int(rotation)-48] = &empty;
}


char Board::getChip(char orbit, char rotation)
{
    // Getter, der den Wert des Arrays cells an der Stelle coordinate (zb. "A0") zu returnt.
    return cells[int(orbit)-65][int(rotation)-48]->getColor();
}

Player* Board::getPlayer(char orbit, char rotation)
{
    // Getter, der einen Pointer für den Spieler des gewählten Feldes zurückgibt.
    return cells[int(orbit)-65][int(rotation)-48];
}

void Board::emptyBoard()
{   
    //Alle Felder mit empty zu füllen
    Player **ptr = &cells[0][0]; //pointer um die Mehrdimensionalität des Arrays zu überspringen
    for(int i = 0; i < 24; i++){
        //Wird für alle 24 Felder ausgeführt
        
        //Feld wird gelehrt.
        *(ptr + i) = &empty;
    } 
}


int Board::checkMill(char orbit, char rotation)
{
    /* 
    A0------------A1-----------A2
    |             |            |
    |    B0-------B1------B2   |
    |    |        |       |    |
    |    |   C0---C1-- C2 |    |
    |    |   |         |  |    |
    A7---B7--C7        C3-B3---A3
    |    |   |         |  |    |
    |    |   C6---C5-- C4 |    |
    |    |        |       |    |
    |    B6-------B5------B4   |
    |             |            |
    A6------------A5-----------A4 

    Koordinaten orbit ∈ [A,B,C], rotation ∈ [0,1,2,3,4,5,6,7]

    Theorie:

    Jedes Feld kann potentiell zwei Mühlen bilden:
    
    Wenn rotation eine gerade Zahl ist, befindet sich der Stein auf einer Ecke, 
    mögliche Mühlen würden Gebildet, wenn Steine auf gleichem orbit einen mit 
    rotation +1 und +2 bzw. -1 und -2 gleichfarbig sind.

    Wenn rotation eine ungerade Zahl ist, ist der Stein auf einem der vier Mittenstege.
    Die erste Mühle bildet sich aus den Positionen mit gleicher rotation und orbit A, B und C
    Die zweite Mühle ist bei gleichbleibendem Orbit: rotation +1 und -1

    Ausnahmen müssen gemacht werden wenn von 0 nach 7 oder 7 nach 0 geprüft wird.
    */

    if(getPlayer(orbit,rotation)==&empty){
        //Wenn das geprüfte Feld Leer ist, ist definitiv keine Mühle vorhanden :P
        return 0;
    }

    // Coordinates from A0 to C7/    
    if (int(rotation) % 2 == 0)
    {
        //Feld ist in einer Ecke

        if ((rotation == '0' || rotation == '6'))
        //Ausnahme für Nulldurchgang:
        {
            // Der Chip liegt auf Feld 0 oder 6 und könnte Somit durch Null gehen
            if(getChip(orbit, '0') == getChip(orbit, '7') && getChip(orbit, '6') == getChip(orbit, '7'))
            {
                // 0, 7 und 6 sind von gleichfarbigen Steinen besetzt. -> Mühle
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
            if(getChip(orbit, '0') == getChip(orbit, '7') && getChip(orbit, '6') == getChip(orbit, '7'))
            {
                // Die Position 7 bildet eine Mühle mit den Feldern 6 und 0 auf dem Selben Quadrat
                return 1;
            }
        }
        else if (getChip(orbit,rotation) == getChip(orbit, rotation - 1) && getChip(orbit,rotation) == getChip(orbit, rotation + 1))
        // Mühle auf dem Rechteck
        {
            // Farbe des neugestzten Steins ist gleich den auf den Nachbarfeldern auf dem jeweilligen Rechteck
            return 1;
        }
    }

    return 0;
}

bool Board::checkNeighbour(char orbitOrigin, char rotationOrigin, char orbitTarget, char rotationTarget)
{

    if (orbitOrigin == orbitTarget && (abs(rotationOrigin - rotationTarget) == 1 || abs(rotationOrigin - rotationTarget) == 7))
    {
        /* 
        Die verglichenen Felder befinden sich auf dem gleichen Quadrat
        Die Distanz zwischen den Beiden Punkten hat den Betrag 1
        Der Betrag 7 kann nur bei Nachbarn 0-7 oder 7-0 zutreffen und deckt somit die Ausnahme für Nulldurchgang ab
        */

        
        return true;
    }
    else if (rotationOrigin%2 != 0 && rotationOrigin == rotationTarget && abs(orbitOrigin - orbitTarget) == 1)
    {
        /* 
        Die verglichenen Felder sind mittelsteine
        Beide Felder sind auf dem gleichen Steg ("X1", "X3", "X5" oder "X7")
        Die Distanz zwischen den Beiden Punkten hat den Betrag 1 (alles außer A nach C)
        */
        return true;
    }
    return false;
}


void Board::printBoard(){
    //Ausgabe des Mühlefelds in der Console
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

    

