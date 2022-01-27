//
// Created by Hazel Eroy on 1/26/22.
//
#include <iostream>
using namespace std;
#include "Painting.h"

Painting::Painting() {
     ID = -1;
     Price = -1.0;
}

Painting::Painting(int IDnum, double value) {
     ID = IDnum;
     Price = value;
}

int Painting::getID() {
    return ID;}

void Painting::setID(int IDnum) {
    ID = IDnum;}

void Painting::setPrice (double value) {
    Price = value;}

double Painting::getPrice() {
    return Price;}

void Painting::print(){
    cout << "ID: " << getID() << endl;
    cout << "Price: $" << getPrice() <<  endl;
   // cout << "Dimensions (W x H): " << width << " " << height << endl;
};