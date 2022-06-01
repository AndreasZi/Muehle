#include <iostream>
using namespace std;


void printField(){
    cout << "Mühle:" << endl;
    cout << getChip("A0") << "------------" << getChip("A1") <<"------------"<<getChip("A2")<< endl;
    cout <<"|" <<"            " <<"|"<< "            "<<"|"<< endl;
    cout <<"|    "<< getChip("B0")<< "-------" << getChip("B1") <<"-------"<<getChip("B2")<< "    |"<<endl;
    cout <<"|" <<"    |       " <<"|"<< "       |  "<<"  |"<< endl;
    cout <<"|    |   "<<getChip("C0")<<"---"<<getChip("C1")<<"---"<<getChip("C2")<<"   |"<<"    |"<<endl;
    cout <<"|" <<"    |   |       |   |  "<<"  |"<< endl;
    cout <<getChip("A7")<<"----"<<getChip("B7")<<"---"<<getChip("C7")<<"       "<<getChip("C3")<<"---"<<getChip("B3")<<"----"<<getChip("A3")<<endl;
    cout <<"|" <<"    |   |    " <<" "<< "  |   |  "<<"  |"<< endl;
    cout <<"|    |   "<<getChip("C6")<<"---"<<getChip("C5")<<"---"<<getChip("C4")<<"   |"<<"    |"<<endl;
    cout <<"|" <<"    |       " <<"|"<< "       |  "<<"  |"<< endl;
    cout <<"|    "<< getChip("B6")<< "-------" << getChip("B5") <<"-------"<<getChip("B4")<< "    |"<<endl;
    cout <<"|" <<"            " <<"|"<< "            "<<"|"<< endl;
    cout << getChip("A6")<< "------------" << getChip("A5") <<"------------"<<getChip("A4")<< endl;
    }