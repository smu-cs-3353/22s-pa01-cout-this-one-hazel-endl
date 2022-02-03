//
// Created by Hazel Eroy on 1/26/22.
//

#ifndef INC_22S_PA01_COUT_THIS_ONE_HAZEL_ENDL_PAINTING_H
#define INC_22S_PA01_COUT_THIS_ONE_HAZEL_ENDL_PAINTING_H
#include <iostream>
using namespace std;
class Painting {

    public:
    Painting();

    Painting(int IDnum, double value, double w, double h);

     void print();
     const double & getPrice() const;
    private:
        int ID;
        double Price;
        double Width;
        double Height;


};


#endif //INC_22S_PA01_COUT_THIS_ONE_HAZEL_ENDL_PAINTING_H
