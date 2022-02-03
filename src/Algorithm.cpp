//
// Created by Owner on 1/26/2022.
//

#include "Algorithm.h"
#include <iostream>
#include <fstream>
using namespace std;
Algorithm::Algorithm() {

}
Algorithm::Algorithm(char* fileName) {
    inputFile = fileName;
    readFile();
}

void Algorithm::readFile(){
    fstream inFS(inputFile);
    if(!inFS.is_open()){
        cout << "File did not open." << endl;
    }
    else {
        cout << "File opened." << endl;
    }
    string maxWidth;
    char buffer[3000];
    inFS.getline(buffer, 3000, ' ');
    maxWidth = buffer;
    cout << maxWidth << endl;
    inFS.getline(buffer, 3000, '\n');
    string maxHeight = buffer;
    cout << maxHeight << endl;
    inFS.getline(buffer, 3000, '\n');
    string numPaintings = buffer;
    cout << "Number of paintings in this file: " << numPaintings << endl;
    inFS.getline(buffer, 3000, ' ');
    while(!inFS.eof()){
        string id = buffer;
        inFS.getline(buffer, 3000, ' ');
        string price = buffer;
        inFS.getline(buffer, 3000, ' ');
        string width = buffer;
        inFS.getline(buffer, 3000, '\n');
        string height = buffer;
        //cout << "Painting ID: " << id << "  Price: " << price << "  Width: " << width << endl;
        Painting newPainting(stoi(id), stod(price), stod(width), stod(height));
        newPainting.print();
        paintingVec.push_back(newPainting);
        cout << "The number of Paintings in paintingVec is: " << paintingVec.size() << endl;
        inFS.getline(buffer, 3000, ' ');
    }
}

void Algorithm::expFirst() {

}

bool Algorithm::compareInterval(Painting &i1, Painting &i2) {
    if(i1.getPrice() > i2.getPrice()){
        return false; 
    }
    return true;
}


