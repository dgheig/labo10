/*
-----------------------------------------------------------------------------------
Laboratory  : labo_10
File        : labo_10_comte_emmanuelle_gallay_david.cpp
Author(s)   : Emmanuelle Comte et David Gallay
Date        : 12.01.2020

Purpose     : Make projections of a space and display them.
Remark(s)   : If the user put 0 points in the point list,
              The program will display a space empty (just one point [0, 0, 0])

                There is the github repository:
                https://github.com/dgheig/labo10

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "src/geometry.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {

    PointList list = getPointList();

    Space space = getSpace(list);

    for (const Map& map: space) {
        displayMap(map);
        cout << endl;
    }

    cout << "Please, press <ENTER> to end the program" << endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
