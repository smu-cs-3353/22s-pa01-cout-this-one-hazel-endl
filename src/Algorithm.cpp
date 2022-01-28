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
    fstream inFS(fileName);
    if(!inFS.is_open()){
        cout << "File did not open." << endl;
    }
    else {
        cout << "File opened." << endl;
    }
}

void Algorithm::readFile(){

}


