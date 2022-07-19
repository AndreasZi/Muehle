//Dieses Programm testet, ob die Mühlenlogik funktioniert

#include <iostream>
#include "Board.cpp"
#include "Player.cpp"

int main(){
    Player black('B');
    Player white('W');
    Board b;

    std::cout << "Mühlentest\n";

    
    std::cout<<"Standardfälle"<<endl;
    b.setChip('A','0',white);
    b.setChip('A','1',white);
    b.setChip('A','2',white);
    std::cout << "+dir Eckmühle: ";
    if (b.checkMill('A','0')==1){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }

    std::cout << "-dir Eckmühle: ";
    if (b.checkMill('A','2')==1){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }

    std::cout << "tan Mittenmühle: ";
    if (b.checkMill('A','1')==1){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }

    b.emptyBoard();
    b.setChip('A','1',white);
    b.setChip('B','1',white);
    b.setChip('C','1',white);
    std::cout << "rad Mittenmühle: ";
    if (b.checkMill('A','1')==1 && b.checkMill('B','1')==1 && b.checkMill('C','1')==1){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }


    b.emptyBoard();
    //b.setChip('A','0',black);
    //b.setChip('A','6',white);
    //b.setChip('B','0',black);
    b.setChip('B','7',white);
    b.setChip('B','6',white);
    b.setChip('C','0',white);
    //b.setChip('C','7',white);
    
    std::cout << "außname Nullfehler: ";
    if (!b.checkMill('B','7')){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }




    b .emptyBoard();
    std::cout<<"Ausnahmefälle"<<endl;
    b.setChip('A','0',white);
    b.setChip('A','6',white);
    b.setChip('A','7',white);
    std::cout << "-exception Eckmühle: ";
    if (b.checkMill('A','0')==1){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }
    std::cout << "+exception Eckmühle: ";
    if (b.checkMill('A','6')==1){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }
    std::cout << "Mittenmühle: ";
    if (b.checkMill('A','7')==1){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }
    

    b .emptyBoard();
    std::cout<<"Ausnahmefall im Nulldurchgang"<<endl;
    b.setChip('A','0',black);
    b.setChip('A','6',white);
    b.setChip('A','7',white);
    b.setChip('B','0',white);
    std::cout << "+exception Eckmühle: ";
    if (!b.checkMill('A','6')){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }



    std::cout<<"leeres Feld"<<endl;
    b.emptyBoard();
    int foundMills = 0;
    for(char c1 = 'A'; c1 < 'D'; c1++){
        // Alle Buchstaben von A bis C
        for(char c2 = '0'; c2 < '8'; c2++){
            // Alle Zahlen von 0 bis 7
            // Feld auf 'O' setzen
            // std::cout<<c1<<c2<<endl;
            foundMills += b.checkMill(c1,c2);
        }
    }
    std::cout << "Auf dem leeren Feld wurden "<<foundMills<<" Mühlen erkannt\n";


    std::cout << "Neighbourtest\n";
    b.emptyBoard();
    std::cout << "Nachbar auf Rechteck: ";
    if (b.checkNeighbour('C', '2', 'C', '1')){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }

    std::cout << "Kein Nachbar auf Rechteck: ";
    if (!b.checkNeighbour('C', '2', 'C', '6')){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }

    std::cout << "Kein Nachbar ueber Ecke: ";
    if (!b.checkNeighbour('C', '2', 'B', '2')){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }


    std::cout << "Nachbar auf Steg: ";
    if (b.checkNeighbour('C', '1', 'B', '1')){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }

    std::cout << "Kein Nachbar auf Steg: ";
    if (!b.checkNeighbour('C', '1', 'A', '1')){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }

    std::cout << "Nachbar bei Nulldurchgang: ";
    if (b.checkNeighbour('B', '0', 'B', '7')){
        std::cout << "erkannt\n";
    }
    else{
        std::cout << "fehler\n";
    }

    b.emptyBoard();
    b.printBoard();

}


