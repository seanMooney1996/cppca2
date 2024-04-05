//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Board.h"
#include <iostream>
#include <fstream>
#include <random>
#include <thread>

using namespace std;

Board::Board(const vector<Bug *> &bugs) {
    bugsVector = bugs;
    getBugPositions();
}

Board::Board() = default;

void Board::initializeBoard(vector<Bug*> &bugsVec){
    bugsVector=bugsVec;
}

void Board::tapBugBoard() {
    moveAllBugs();
    getBugPositions();
}

void Board::displayLifeHistory() {
    for (Bug *bug: bugsVector) {
        bug->displayBug();
        cout << getBugLifeHistory(bug) << endl;
    }
}

//https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm for time code
void Board::writeHistoryToFile() {
    time_t now = time(0);
    tm *gtm = gmtime(&now); // Using gmtime() instead of localtime()

    string year = to_string(1900 + gtm->tm_year);
    string month = to_string(1 + gtm->tm_mon);
    string day = to_string(gtm->tm_mday);
    string hour = to_string((gtm->tm_hour) + 1);
    string minutes = to_string(gtm->tm_min);
    string seconds = to_string(gtm->tm_sec);

    string filename =
            "bugs_life_history_" + day + "-" + month + "-" + year + "_" + hour + "-" + minutes + "-" + seconds + ".txt";
    ofstream output(filename);
    cout << filename << endl;
    for (Bug *bug: bugsVector) {
        output << bug->getBugDetails();
        output << getBugLifeHistory(bug) << "\n";
    }

    output.close();
}


void Board::getBugPositions() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            boardVector[i][j] = nullptr;
        }
    }
    auto iter = bugsVector.begin();
    for (int i = 0; i < bugsVector.size(); i++) {
        Bug *b = *iter;

        // eat functionality for board
        if (b->isAlive()) {
            Pair bugPos = b->getPosition();
            Bug *ptrToOtherBug = boardVector[bugPos.getX()][bugPos.getY()];
            if (ptrToOtherBug== nullptr){
                boardVector[bugPos.getX()][bugPos.getY()] = b;
            } else {
                if (ptrToOtherBug->getSize()>b->getSize()){
                    ptrToOtherBug->eatBug(b);
                } else if (ptrToOtherBug->getSize()<b->getSize()){
                    b->eatBug(ptrToOtherBug);
                    boardVector[bugPos.getX()][bugPos.getY()] = b;
                } else {
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    int min = 1;
                    int max = 2;
                    std::uniform_int_distribution<> dist(min, max);
                    int randomInt = dist(gen);
                    if (randomInt == 1){
                        ptrToOtherBug->eatBug(b);
                    } else {
                        b->eatBug(ptrToOtherBug);
                        boardVector[bugPos.getX()][bugPos.getY()] = b;
                    }
                }
            }
        }
        iter++;
    }
    printBoard();
}

void Board::moveAllBugs() {
    for (int i = 0; i < bugsVector.size(); i++) {
        cout<< endl;
        bugsVector[i]->move();
    }
}

void Board::printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "| ";
            if (this->boardVector[i][j] != nullptr) {
                Bug *b = this->boardVector[i][j];
                if (b->getSize()<10){
                    cout <<" "<<b->getSize();
                } else {
                    cout << b->getSize();
                }
            } else {
                cout << "  ";
            }
            cout << " |";
            if (j == 9) {
                cout << endl;
            }
        }
    }
}

void Board::displayAllCells() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "(" << i << "," << j << ") : ";
            if (boardVector[i][j] == nullptr) {
                cout << "empty" << endl;
            } else {
                cout << boardVector[i][j]->getBugDetails() << endl;
            }
        }
    }
}

string Board::getBugLifeHistory(Bug *bug) {
    string bugLifeHistory = "PATH: ";
    for (auto iter: bug->getPath()) {
        bugLifeHistory += " (" + to_string(iter.getX()) + "," + to_string(iter.getY()) + ") ";
    }

    if (!bug->isAlive()) {
        bugLifeHistory += to_string(bug->getEatenBy()) + " ate this bug!";
    } else {
        bugLifeHistory += "ALIVE! ";
    }
    return bugLifeHistory;
}


// https://en.cppreference.com/w/cpp/thread/sleep_for <--- sleep code used
void Board::runSimulation() {
    int aliveCount=1000;
    while (aliveCount>1){
        aliveCount=0;
        tapBugBoard();
        for (Bug *bug:bugsVector){
            if (bug->isAlive()){
                aliveCount++;
            }
        }
        std::this_thread::sleep_for(1000ms);
    }
}

void Board::displayAllBugs() {
    cout << "**** DISPLAYING ALL BUGS ****" << endl;
    for (int i = 0; i < bugsVector.size(); i++) {
        bugsVector.at(i)->displayBug();
    }
    cout << "*********************" << endl;
}

void Board::addNewBugToBoard(Bug *bug) {
        bugsVector.push_back(bug);
}




