//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Board.h"
#include <iostream>
#include <fstream>
#include <random>
#include <thread>
#include <chrono>
#include <map>
#include <time.h>


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

    cout<< "writing to file"<<endl;
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

    map<Pair, std::vector<Bug*>*> positionsUsedMap;


    for (auto bug : bugsVector) {

        if (bug->isAlive()) {
            Pair positionOfBug = bug->getPosition();
            auto it = positionsUsedMap.find(positionOfBug);
            if (it == positionsUsedMap.end()) {
                auto *bugsInCell = new std::vector<Bug *>;
                bugsInCell->push_back(bug);
                positionsUsedMap.insert({positionOfBug, bugsInCell});
            } else {
                it->second->push_back(bug);
            }
        }
    }


    for (auto& entry : positionsUsedMap) {
        cout<< "position:   " << entry.first.getX() << "," << entry.first.getY() << endl;
        for (int i = 0; i < entry.second->size(); i++) {
                cout<<"  Bug :"<< entry.second->at(i)->getId() << " "<< entry.second->at(i)->getBugType()<<endl;
        }
        if (entry.second->size() >= 2) {
            int biggestBugSize = 0;
            int indexOfBiggest = -1;

            for (int i = 0; i < entry.second->size(); i++) {
                Bug* bug = entry.second->at(i);
                if (biggestBugSize < bug->getSize()) {
                    biggestBugSize = bug->getSize();
                    indexOfBiggest = static_cast<int>(i);

                    // if bugs are equal in size, only half the time will it select another bug to be the biggest.
                } else if (biggestBugSize == bug->getSize()) {
                    srand(time(0));
                    int randomInt = rand()%2;

                    if (randomInt == 1 ){
                        indexOfBiggest = static_cast<int>(i);
                    }
                }
            }

            if (indexOfBiggest != -1) {
                Bug* biggestBugInCell = entry.second->at(indexOfBiggest);
                for (size_t i = 0; i < entry.second->size(); i++) {
                    if (i !=indexOfBiggest) {
                        biggestBugInCell->eatBug(entry.second->at(i));
                    }
                }
            }
        }
    }

    // Update board
    for (auto bug : bugsVector) {
        Pair bugPos = bug->getPosition();
        if (bug->isAlive()) {
            boardVector[bugPos.getX()][bugPos.getY()] = bug;
        }
    }

    for (auto& entry : positionsUsedMap) {
        delete entry.second;
    }
    positionsUsedMap.clear();

    printBoard();
}

void Board::moveAllBugs() {
    for (int i = 0; i < bugsVector.size(); i++) {

        if (bugsVector.at(i)->isAlive()) {
            cout << endl;
            bugsVector[i]->move();
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "| ";
            if (this->boardVector[i][j] != nullptr) {
                Bug *b = this->boardVector[i][j];
                cout<<b->getId();
            } else {
                cout << "   ";
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

vector<Bug*> &Board::getBugsVec() {
    return bugsVector;
}




