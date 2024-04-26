#include <iostream>
#include "headers/Bug.h"
#include "headers/Crawler.h"
#include "headers/Hopper.h"
#include "headers/Board.h"
#include "headers/Splitter.h"
#include "headers/GUI.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void readBugsFromFile(vector<Bug *> &bug_vector, const string &file_name, Board *board);

void findBugById(const vector<Bug *> &bugVec, int size);

int main() {
    vector<Bug *> bug_vector;
    auto *board = new Board();
    readBugsFromFile(bug_vector, "bugs.txt",board);
    board->initializeBoard(bug_vector);
    board->displayAllBugs();
    int input = 0;
    while (input != -1) {
        cout << "Enter -1 to exit" << endl;
        cout << "Enter 1 to find bug" << endl;
        cout << "Enter 2 to tap board" << endl;
        cout << "Enter 3 to display all bug history" << endl;
        cout << "Enter 4 to display all cells" << endl;
        cout << "Enter 5 run simulation" << endl;
        cout << "Enter 6 run display all bugs" << endl;
        cout << "Enter 7 run game mode" << endl;
        cin >> input;

        switch (input) {
            case (-1):
                cout << "Exiting" << endl;
                break;
            case (1) :
                findBugById(bug_vector, bug_vector.size());
                break;
            case (2) :
                board->tapBugBoard();
                break;
            case (3) :
                board->displayLifeHistory();
                break;
            case (4) :
                board->displayAllCells();
                break;
            case (5) :
                board->runSimulation();
                board->writeHistoryToFile();
                input = -1;
                break;
            case (6) :
                board->displayAllBugs();
                break;
            case (7) : {
                auto *pb = new PlayerBug( 1000, 9, 5, Direction::North, 5);
                GUI game(*board, *pb);
                game.begin();

                // reinstate board when game finishes
                readBugsFromFile(bug_vector, "bugs.txt",board);
                board->initializeBoard(bug_vector);
                break;
            }
            default :
                cout << " Enter a valid number " << endl;
        }
    }

    // using virtual destructor for deleting bug based on subclass.
    for(Bug *bug :bug_vector){
        delete bug;
    }
     delete board;
    return 0;
}

void findBugById(const vector<Bug *> &bugVec, int size) {
    cout << "Enter id of bug you would like to find" << endl;
    int input;
    cin >> input;
    bool foundBug = false;

    auto it = bugVec.begin();
    for (int i = 0; i < size; i++) {
        Bug *b = *it;
        if (b->getId() == input) {
            cout << "Found bug " << input << endl;
            b->displayBug();
            return;
        }
        it++;
    }

    cout << "Did not find bug " << input << endl;
}



void readBugsFromFile(vector<Bug *> &bug_vector, const string &file_name,Board *board) {
    std::ifstream inputFile(file_name);

    while (!inputFile.eof()) {
        string line;
        getline(inputFile, line);
        stringstream ss(line);
        string token;
        vector<string> tokens;
        char delimiter = ';';

        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }

        int id = stoi(tokens.at(1));
        int x = stoi(tokens.at(2));
        int y = stoi(tokens.at(3));
        int dir = stoi(tokens.at(4));
        int size = stoi(tokens.at(5));
        Direction d;
        if (dir == 1) {
            d = Direction::North;
        } else if (dir == 2) {
            d = Direction::East;
        } else if (dir == 3) {
            d = Direction::South;
        } else {
            d = Direction::West;
        }
        if (tokens.at(0) == "C") {
            auto *c = new Crawler(id, x, y, d, size);
            bug_vector.push_back(c);
        }
        else if (tokens.at(0) == "S") {
            int splitFreq = stoi(tokens.at(6));
            auto *s = new Splitter(id, x, y, d, size, splitFreq, board);
            bug_vector.push_back(s);
        }else {
            int hopLength = stoi(tokens.at(6));
            auto *h = new Hopper(id, x, y, d, size, hopLength);
            bug_vector.push_back(h);
        }
    }

    inputFile.close();
}

