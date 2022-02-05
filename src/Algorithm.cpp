//
// Created by Owner on 1/26/2022.
//

#include "Algorithm.h"
#include <iostream>
#include <fstream>
#include <algorithm>
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
    cout << "Maximum width: " << maxWidth << endl;
    maxSize = stoi(maxWidth);
    inFS.getline(buffer, 3000, '\n');
    string maxHeight = buffer;
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
        //newPainting.print();
        paintingVec.push_back(newPainting);
        //cout << "The number of Paintings in paintingVec is: " << paintingVec.size() << endl;
        inFS.getline(buffer, 3000, ' ');
    }
        cout << "Testing expFirst()"<< endl;
        expFirst();
          cout << "Testing customAlgo" << endl;
          customAlgo();
}

void Algorithm::expFirst() {
sort(paintingVec.begin(), paintingVec.end(), comparePrice);
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
double totalPrice = 0;
double totalWidth = 0;
for(int i = 0; i< mostExpFirst.size(); i++){
    //mostExpFirst.at(i).print();
    totalPrice+= mostExpFirst.at(i).getPrice();
    totalWidth+= mostExpFirst.at(i).getWidth();
}
cout << "The total price from the most expensive first algorithm is: " << totalPrice << endl;
cout << "Total width taken up: " << totalWidth << endl;
}

void Algorithm::customAlgo(){
    sort(paintingVec.begin(), paintingVec.end(), comparePriceByWidth);
    vector<Painting> bestRatioFirst;
    int sizeTaken = 0;
    int counter = 0;
    while(true){
        if(counter >= paintingVec.size()) {
            break;
        }
        else if(maxSize - (sizeTaken + paintingVec.at(counter).getWidth())>=0){
            bestRatioFirst.push_back(paintingVec.at(counter));
            sizeTaken += paintingVec.at(counter).getWidth();
        }
        counter++;
    }
    double totalPrice = 0;
    double totalWidth = 0;
    for(int i = 0; i< bestRatioFirst.size(); i++){
        //bestRatioFirst.at(i).print();
        totalPrice+= bestRatioFirst.at(i).getPrice();
        totalWidth+= bestRatioFirst.at(i).getWidth();
    }
    cout << "The total price from the custom algorithm is: " << totalPrice << endl;
    cout << "The total width taken up is: " << totalWidth << endl;
}

bool Algorithm::comparePrice(const Painting &i1, const Painting &i2) {
    return (i1.getPrice() > i2.getPrice());
}

bool Algorithm::comparePriceByWidth(const Painting &i1, const Painting &i2) {
    return (i1.getPriceByWidth() > i2.getPriceByWidth());
}


