//
// Created by Hazel Eroy on 2/4/22.
//

#include "Subset.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

Subset::Subset() {

}

double Subset::getTotalWidth() {
    double totalWidth;

    for (int i = 0; i < subsetPainting.size(); i++){
        totalWidth += subsetPainting[i].getWidth();
    }
    return totalWidth;
}

double Subset::getTotalValue() {
    double totalValue;

    for (int i = 0; i < subsetPainting.size(); i++){
        totalValue += subsetPainting[i].getPrice();
    }

    return totalValue;
}

void Subset::pushback(Painting p) {
    subsetPainting.push_back(p);

}

int Subset::size() {
    return subsetPainting.size();
}

void Subset::print() {
    for (int i = 0; i < subsetPainting.size(); i++){
        cout << subsetPainting[i].getID() << " ";
    }

}

void Subset::printPaintings() {
    for (int i = 0; i < subsetPainting.size(); i++){
        subsetPainting[i].print();
    }
}


