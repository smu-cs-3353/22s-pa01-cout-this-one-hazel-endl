//
// Created by London Kasper on 1/24/2022.
//
#include <iostream>
#include "Painting.h"
#include "Algorithm.h"
#include <fstream>
#include <string>

using namespace std;
int main(int argc,  char *argv[]){
    Algorithm newAlgorithm(argv[1]);
//        if(argc > 1){
//            //cout << argv[1] << endl; //output the command line argument
//            char* fileIn = argv[1];
//
//            //will also need three output files to be declared, each one appended to the end of the input file's name (see project guidelines)
//            fstream inFS(fileIn);
//            if(!inFS.is_open()){
//                cout << "File did not open." << endl;
//            }
//            else {
//                cout << "File opened." << endl;
//            }
//            string maxWidth;
//            char buffer[3000];
//            inFS.getline(buffer, 3000, ' ');
//            maxWidth = buffer;
//            cout << maxWidth << endl;
//            inFS.getline(buffer, 3000, '\n');
//            string maxHeight = buffer;
//            cout << maxHeight << endl;
//            inFS.getline(buffer, 3000, '\n');
//            string numPaintings = buffer;
//            cout << "Number of paintings in this file: " << numPaintings << endl;
//            inFS.getline(buffer, 3000, ' ');
//            while(!inFS.eof()){
//                string id = buffer;
//                inFS.getline(buffer, 3000, ' ');
//                string price = buffer;
//                inFS.getline(buffer, 3000, ' ');
//                string width = buffer;
//                inFS.getline(buffer, 3000, '\n');
//                string height = buffer;
//               //cout << "Painting ID: " << id << "  Price: " << price << "  Width: " << width << endl;
//                Painting newPainting(stoi(id), stod(price), stod(width), stod(height));
//                newPainting.print();
//                inFS.getline(buffer, 3000, ' ');
//            }
//        }
}
