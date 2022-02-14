//
// Created by Owner on 1/26/2022.
//

#include "Algorithm.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <vector>
#include "Subset.h"
#include <string>
using namespace std;

Algorithm::Algorithm() {

}
Algorithm::Algorithm(char* fileName) {
    //create inputFile
    inputFile = fileName;
    inputFileString = inputFile;
    inputFileString = inputFileString.substr(0, inputFileString.length()-4);
    inputFileString = inputFileString.substr(9, inputFileString.length());
    readFile();
}

void Algorithm::readFile(){
    //open file
    fstream inFS(inputFile);

    //checks if file is open
    if(!inFS.is_open()){
        cout << "File did not open." << endl;
    }
    else {
        cout << "File opened." << endl;
    }

    //reading in file
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

    //calling all three algorithms
        cout << "Testing expFirst()"<< endl;
        expFirst();
          cout << "Testing customAlgo" << endl;
          customAlgo();
          cout << "Testing bruteForce()" << endl;
          bruteForce();
}

// most expensive first algorithm
void Algorithm::expFirst() {
    // sorts paintings by price
    sort(paintingVec.begin(), paintingVec.end(), comparePrice);

    //create vector to hold paintings
    vector<Painting> mostExpFirst;
    int sizeTaken = 0;
    int counter = 0;

    //checking if painting fits the wall
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

    //adds all prices and width
    for(int i = 0; i< mostExpFirst.size(); i++){
        totalPrice+= mostExpFirst.at(i).getPrice();
        totalWidth+= mostExpFirst.at(i).getWidth();
    }
    cout << "The total price from the most expensive first algorithm is: " << totalPrice << endl;
    cout << "Total width taken up: " << totalWidth << endl;

    //creates output file
    fstream file;

    //names and writes into ouput file
    file.open("../output/"+inputFileString+"-highvalue.txt",ios::out);
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

//custom algorithm
void Algorithm::customAlgo(){
    //sorts paintings by price
    sort(paintingVec.begin(), paintingVec.end(), comparePriceByWidth);

    //creates vector to hold all paintings
    vector<Painting> bestRatioFirst;
    int sizeTaken = 0;
    int counter = 0;

    //checking if painting fits the wall
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

    //adds all prices and width
    double totalPrice = 0;
    double totalWidth = 0;
    for(int i = 0; i< bestRatioFirst.size(); i++){
        totalPrice+= bestRatioFirst.at(i).getPrice();
        totalWidth+= bestRatioFirst.at(i).getWidth();
    }
    cout << "The total price from the custom algorithm is: " << totalPrice<< endl;
    cout << "The total width taken up is: " << totalWidth << endl;

    //creates output file
    fstream file;

    //names and write into output file
    file.open("../output/"+inputFileString+"-custom.txt",ios::out);
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
    //create vector to hold combinations of paintings on a wall
    vector <Subset> allSubsets;

    //creating all possible subsets of paintings
    int count = pow(2, paintingVec.size());
    cout << "The expected # of subsets is: " << count << endl;
    for (int i = 0; i < count; i++) {
        Subset newSubset;
        for (int j = 0; j < paintingVec.size(); j++) {
            if ((i & (1 << j)) != 0){
                newSubset.pushback(paintingVec[j]);
            }
        }

        //checks if a set of paintings fit on a wall and adds to vector
        if (newSubset.getTotalWidth() <= maxSize){
                allSubsets.push_back(newSubset);
        }
    }

    //finds the painting combination with the highest total value
    Subset maxVal = allSubsets[1];
    for (int h = 0; h < allSubsets.size()-1; h++){
        if (maxVal.getTotalValue() < allSubsets[h].getTotalValue()){
            maxVal = allSubsets[h];
        }
    }
    cout << "Total price from bruteforce algorithm: " << maxVal.getTotalValue() <<  endl;

    //create output file
    fstream outputFile;

    //names and writes into ouput file
    cout << "inputFileString: " << inputFileString << endl;
    outputFile.open("../output/"+inputFileString+"-bruteForce.txt",ios::out);
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







