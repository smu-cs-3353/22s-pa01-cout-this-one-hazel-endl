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
#include <string>
#include <chrono>

using namespace std::chrono;
Algorithm::Algorithm() {

}
Algorithm::Algorithm(char* fileName) {
    inputFile = fileName;
    inputFileString = inputFile;
    inputFileString = inputFileString.substr(0, inputFileString.length()-4);
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
        Painting newPainting(stoi(id), stod(price), stod(width), stod(height));
        paintingVec.push_back(newPainting);
        inFS.getline(buffer, 3000, ' ');
    }
    cout << "Testing expFirst()"<< endl;
    auto start1 = high_resolution_clock::now();
    expFirst();
    auto stop1 = high_resolution_clock::now();
    cout << "Testing customAlgo" << endl;
    auto start2 = high_resolution_clock::now();
    customAlgo();
    auto stop2 = high_resolution_clock::now();
    cout << "Testing bruteForce()" << endl;
    auto start3 = high_resolution_clock::now();
    bruteForce();
    auto stop3 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Expensive first execution time: " << duration1.count() << endl;
    cout << "Custom execution time: " << duration2.count() << endl;
    cout << "Brute Force execution time: " << duration3.count() << endl;
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
    totalPrice+= mostExpFirst.at(i).getPrice();
    totalWidth+= mostExpFirst.at(i).getWidth();
}
cout << "The total price from the most expensive first algorithm is: " << totalPrice << endl;
cout << "Total width taken up: " << totalWidth << endl;
fstream file;
file.open(inputFileString+"-highvalue.txt",ios::out); //FIXME fix the .txt being included from initial filename
    if(!file)
    {
        cout<<"Error in creating file!!!";
    }
    else{
        file<< totalPrice << endl;
        for(int i = 0; i<mostExpFirst.size(); i++){
            file << mostExpFirst.at(i).getID() << " " << mostExpFirst.at(i).getPrice() << " " << mostExpFirst.at(i).getWidth() << " " << mostExpFirst.at(i).getHeight() << endl;
        }
    }

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
    cout << "The total price from the custom algorithm is: " << totalPrice<< endl;
    cout << "The total width taken up is: " << totalWidth << endl;
    fstream file;
    file.open(inputFileString+"-custom.txt",ios::out);
    if(!file)
    {
        cout<<"Error in creating file!!!";
    }
    else{
        file<< totalPrice << endl;
        for(int i = 0; i<bestRatioFirst.size(); i++){
            file << bestRatioFirst.at(i).getID() << " " << bestRatioFirst.at(i).getPrice() << " " << bestRatioFirst.at(i).getWidth() << " " << bestRatioFirst.at(i).getHeight() << endl;
        }
    }
}

bool Algorithm::comparePrice(const Painting &i1, const Painting &i2) {
    return (i1.getPrice() > i2.getPrice());
}

bool Algorithm::comparePriceByWidth(const Painting &i1, const Painting &i2) {
    return (i1.getPriceByWidth() > i2.getPriceByWidth());
}

void Algorithm::bruteForce() {
    vector <Subset> allSubsets;
    int count = pow(2, paintingVec.size());
    cout << "The expected # of subsets is: " << count << endl;
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


    Subset maxVal = allSubsets[1];
    for (int h = 0; h < allSubsets.size()-1; h++){
        if (maxVal.getTotalValue() < allSubsets[h].getTotalValue()){
            maxVal = allSubsets[h];
        }
    }


    cout << "Total price from bruteforce algorithm: " << maxVal.getTotalValue() <<  endl;
    fstream outputFile;
    outputFile.open(inputFileString+"-bruteForce.txt",ios::out);
    if(!outputFile)
    {
        cout<<"Error in creating file!!!";
    }
    else{
        outputFile << maxVal.getTotalValue();
        outputFile << endl;
        for (int i = 0; i < maxVal.size(); i ++){
            outputFile << maxVal.getVector()[i].getID()<< " "<< maxVal.getVector()[i].getPrice()<< " "<< maxVal.getVector()[i].getWidth()<< " "<< maxVal.getVector()[i].getHeight()<< endl;
        }
    }

}







