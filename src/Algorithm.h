//
// Created by Owner on 1/26/2022.
//

#ifndef INC_22S_PA01_COUT_THIS_ONE_HAZEL_ENDL_ALGORITHM_H
#define INC_22S_PA01_COUT_THIS_ONE_HAZEL_ENDL_ALGORITHM_H
#include "Painting.h"
#include <vector>
class Algorithm {
public:
    Algorithm();
    Algorithm(char*);
    void readFile();

private:
    vector<Painting> paintingVec;
    char* inputFile;
};


#endif //INC_22S_PA01_COUT_THIS_ONE_HAZEL_ENDL_ALGORITHM_H
