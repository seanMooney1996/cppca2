#include <iostream>
#include "headers/Bug.h"
#include "headers/Crawler.h"
#include "headers/Hopper.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
void readBugsFromFile(vector<Bug*> &bug_vector,const string& file_name);
void displayAllBugs(const vector<Bug*> &bug_vector,int size);
int main() {
    vector<Bug*> bug_vector;
    readBugsFromFile(bug_vector,"bugs.txt");

    displayAllBugs(bug_vector,bug_vector.size());
    return 0;
}

void displayAllBugs(const vector<Bug*> &bug_vector,int size){
    cout<<"**** DISPLAYING ALL BUGS ****"<<endl;
    for (int i=0;i<size;i++){
        bug_vector.at(i)->displayBug();
    }
    cout<<"*********************";
}


void readBugsFromFile(vector<Bug*> &bug_vector,const string& file_name){
    std::ifstream inputFile(file_name);

    while(!inputFile.eof()){
        string line;
        getline(inputFile,line);
        stringstream ss(line);
        string token;
        vector<string> tokens;
        char delimiter = ';';

        while (getline(ss,token,delimiter)){
            tokens.push_back(token);
        }

        int id = stoi(tokens.at(1));
        int x = stoi(tokens.at(2));
        int y = stoi(tokens.at(3));
        int dir = stoi(tokens.at(4));
        int size = stoi(tokens.at(5));
        Direction d;
        if (dir == 1){
            d=Direction::North;
        } else  if (dir == 2){
            d=Direction::East;
        }  else  if (dir == 3){
            d=Direction::South;
        } else {
            d=Direction::West;
        }
        if (tokens.at(0)=="C"){
            Crawler *c = new Crawler(id,x,y,d,size);
            bug_vector.push_back(c);
        } else {
            int hopLength = stoi(tokens.at(6));
            Hopper *h = new Hopper(id,x,y,d,size,hopLength);
            bug_vector.push_back(h);
        }
    }

    inputFile.close();
}

