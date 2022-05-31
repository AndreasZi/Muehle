#include <iostream>
using namespace std;
#include "./speicher.h"

void printField(){
    cout << "Mühle:" << endl;
    cout << getStone("A0") << "------------" << getStone("A1") <<"------------"<<getStone("A2")<< endl;
    cout <<"|" <<"            " <<"|"<< "            "<<"|"<< endl;
    cout <<"|    "<< getStone("B0")<< "-------" << getStone("B1") <<"-------"<<getStone("B2")<< "    |"<<endl;
    cout <<"|" <<"    |       " <<"|"<< "       |  "<<"  |"<< endl;
    cout <<"|    |   "<<getStone("C0")<<"---"<<getStone("C1")<<"---"<<getStone("C2")<<"   |"<<"    |"<<endl;
    cout <<"|" <<"    |   |       |   |  "<<"  |"<< endl;
    cout <<getStone("A7")<<"----"<<getStone("B7")<<"---"<<getStone("C7")<<"       "<<getStone("C3")<<"---"<<getStone("B3")<<"----"<<getStone("A3")<<endl;
    cout <<"|" <<"    |   |    " <<" "<< "  |   |  "<<"  |"<< endl;
    cout <<"|    |   "<<getStone("C6")<<"---"<<getStone("C5")<<"---"<<getStone("C4")<<"   |"<<"    |"<<endl;
    cout <<"|" <<"    |       " <<"|"<< "       |  "<<"  |"<< endl;
    cout <<"|    "<< getStone("B6")<< "-------" << getStone("B5") <<"-------"<<getStone("B4")<< "    |"<<endl;
    cout <<"|" <<"            " <<"|"<< "            "<<"|"<< endl;
    cout << getStone("A6")<< "------------" << getStone("A5") <<"------------"<<getStone("A4")<< endl;
    }