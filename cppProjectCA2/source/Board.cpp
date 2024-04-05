//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Board.h"
#include <iostream>
#include <fstream>

using namespace std;
Board::Board(const vector<Bug*> &bugs) {
    bugsVector=bugs;
    getBugPositions();
}

void Board::tapBugBoard() {
    moveAllBugs();
    getBugPositions();
}


void Board::displayLifeHistory() {
    for (Bug* bug:bugsVector){
        bug->displayBug();
        cout << getBugLifeHistory(bug) << endl;
    }
}


//https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm for time code
void Board::writeHistoryToFile() {
    time_t now = time(0);
    tm *gtm = gmtime(&now); // Using gmtime() instead of localtime()

    string year = to_string(1900 + gtm->tm_year);
    string month =  to_string(1 + gtm->tm_mon);
    string day = to_string(gtm->tm_mday);
    string hour = to_string((gtm->tm_hour)+1);
    string minutes = to_string(gtm->tm_min);
    string seconds = to_string(gtm->tm_sec);

    string filename = "bugs_life_history_"+day+"-"+month+"-"+year+"_"+hour+"-"+minutes+"-"+seconds+".txt";
    ofstream output(filename);
    cout<< filename<< endl;
    for (Bug* bug: bugsVector){
        output << bug->getBugDetails();
        output << getBugLifeHistory(bug)<<"\n";
    }

    output.close();
}

void Board::getBugPositions() {
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            boardVector[i][j] = nullptr;
        }
    }
    auto iter = bugsVector.begin();
    for (int i=0;i<bugsVector.size();i++){
        Pair bugPos = (*iter)->getPosition();
        boardVector[bugPos.getX()][bugPos.getY()] = *iter;
        iter++;
    }
    printBoard();
}
void Board::moveAllBugs() {
    for (int i=0;i<bugsVector.size();i++){
        bugsVector[i]->displayBug();
        bugsVector[i]->move();
        bugsVector[i]->displayBug();
    }
}
void Board::printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "| ";
            if (this->boardVector[i][j] != nullptr) {
                Bug *b = this->boardVector[i][j];
                cout << b->getSize();
            } else {
                cout << "X";
            }
            cout<< " |";
            if (j==9){
                cout<<endl;
            }
        }
    }
}

void Board::displayAllCells() {
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cout << "(" << i << "," <<j<< ") : ";
            if (boardVector[i][j] == nullptr){
                cout << "empty"<<endl;
            } else {
                cout << boardVector[i][j]->getBugDetails() << endl;
            }
        }
    }
}

string Board::getBugLifeHistory(Bug *bug) {
    string bugLifeHistory = "PATH: ";
    for (auto iter : bug->getPath()){
        bugLifeHistory +=" (" + to_string(iter.getX()) +","+ to_string(iter.getY())+") ";
    }

    if (!bug->isAlive()){
        bugLifeHistory += to_string(bug->getEatenBy())+ " ate this bug!";
    } else {
        bugLifeHistory+= "ALIVE! ";
    }
    return bugLifeHistory;
}




