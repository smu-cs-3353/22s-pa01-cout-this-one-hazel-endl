//
// Created by Owner on 1/26/2022.
//

#include "Algorithm.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include "Subset.h"
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
    maxSize = stoi(maxWidth);
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

    cout << "Testing expFirst()"<< endl;
    //expFirst();
    bruteForce();
}

void Algorithm::expFirst() {
sort(paintingVec.begin(), paintingVec.end(), comparePrice);
//cout << "First painting in paintingVec: ";
//paintingVec.at(0).print();
//cout << "last painting in painting Vec:";
//paintingVec.at(paintingVec.size()-1).print();
vector<Painting> mostExpFirst;
int sizeTaken = 0;
int counter = 0;
while(true){
    if(counter >= paintingVec.size()) {
    break;
    }
    else if(maxSize - (sizeTaken + paintingVec.at(counter).getWidth())>=0){
    mostExpFirst.push_back(paintingVec.at(counter));
    sizeTaken += paintingVec.at(counter).getWidth();
}

    counter++;
}
for(int i = 0; i< mostExpFirst.size(); i++){
    mostExpFirst.at(i).print();
}
}

bool Algorithm::comparePrice(const Painting &i1, const Painting &i2) {
    return (i1.getPrice() > i2.getPrice());
}



void Algorithm::bruteForce() {
    vector <Subset> allSubsets;
    int count = pow(2, paintingVec.size());
    for (int i = 0; i < count; i++) {
        Subset newSubset;
        for (int j = 0; j < paintingVec.size(); j++) {
            if ((i & (1 << j)) != 0){
                newSubset.pushback(paintingVec[j]);
            }
        }
        if (newSubset.getTotalWidth() <= maxSize){
                allSubsets.push_back(newSubset);
        }
    }

    for (int k = 0; k < allSubsets.size(); k++){
        for (int z = 0; z < allSubsets[k].size(); k++){
            allSubsets[k].print();
            cout << allSubsets[k].getTotalValue() << endl;
            cout << endl;
        }
        cout << "\n";
    }

    Subset maxVal = allSubsets[1];
    for (int h = 0; h < allSubsets.size()-1; h++){
        if (maxVal.getTotalValue() < allSubsets[h].getTotalValue()){
            maxVal = allSubsets[h];
        }
    }

    maxVal.print();
    cout << maxVal.getTotalValue() << endl << endl;

    cout << "Output format: " << endl;
    cout << maxVal.getTotalValue();
    cout << endl;

    maxVal.printPaintings();
}







