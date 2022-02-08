#include <algorithm>
//
// Created by Hazel Eroy on 2/4/22.
//

#ifndef INC_22S_PA01_COUT_THIS_ONE_HAZEL_ENDL_SUBSET_H
#define INC_22S_PA01_COUT_THIS_ONE_HAZEL_ENDL_SUBSET_H
#include "Painting.h"
#include <vector>
#include <string>

class Subset {
public:
    Subset();
    double getTotalWidth();
    double getTotalValue();
    void pushback(Painting p);
    int size();
    void print();
    void printPaintings();
    vector <Painting> getVector ();

private:
    vector <Painting> subsetPainting;
};


#endif //INC_22S_PA01_COUT_THIS_ONE_HAZEL_ENDL_SUBSET_H
