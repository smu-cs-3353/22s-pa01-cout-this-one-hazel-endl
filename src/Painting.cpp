//
// Created by Hazel Eroy on 1/26/22.
//
#include <iostream>
using namespace std;
#include "Painting.h"


Painting::Painting() {
     ID = -1;
     Price = -1.0;
     Width = -1.0;
     Height = -1.0;
}

Painting::Painting(int IDnum, double value, double w, double h) {
     ID = IDnum;
     Price = value;
     Width = w;
     Height = h;
}

void Painting::print(){
    cout << ID << " " << Price << " " << Width << " " << Height << endl;
    /*cout << "ID: " << ID << endl;
    cout << "Price: $" << Price <<  endl;
    cout << "Dimensions (W x H): " << Width << " " << Height << endl;*/
};
const double & Painting::getPrice() const{
    return Price;
}
double Painting::getWidth(){
    return Width;
}

double Painting::getHeight(){
    return Height;
}

const int &Painting::getID() const {
    return ID;
}
