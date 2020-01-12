/*
-----------------------------------------------------------------------------------
Laboratoire : labo_10
Fichier     : test_point_get.cpp
Auteur(s)   : Emmanuelle Comte et David Gallay
Date        : 11.01.2020

But         : Example of test file for a function
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/

#include <iostream>
#include "../src/geometry.h"
#include "test_utility.h"
using namespace std;

int exit_value = EXIT_SUCCESS;

bool test_setX(Point& point, Coordonate value, const Point& expected) {

    setX(point, value);
    if ( !comparePoint(point, expected) )
    {
        cerr << "Error, expected:" << endl;
        displayPoint(expected);
        cerr << "got:";
        displayPoint(point);
        exit_value = EXIT_FAILURE;
        return false;
    }
    return true;
}

bool test_setY(Point& point, Coordonate value, const Point& expected) {

    setY(point, value);
    if ( !comparePoint(point, expected) )
    {
        cerr << "Error, expected:" << endl;
        displayPoint(expected);
        cerr << "got:";
        displayPoint(point);
        exit_value = EXIT_FAILURE;
        return false;
    }
    return true;
}

bool test_setZ(Point& point, Coordonate value, const Point& expected) {

    setZ(point, value);
    if ( !comparePoint(point, expected) )
    {
        cerr << "Error, expected:" << endl;
        displayPoint(expected);
        cerr << "got:";
        displayPoint(point);
        exit_value = EXIT_FAILURE;
        return false;
    }
    return true;
}

int main() {
    Point point1 = {1, 0, 3};
    Point point2 = {1, 8, 7};
    Point point3 = {0};

    test_setX(point1, 3, {3, 0, 3});
    test_setY(point2, 3, {1, 3, 7});
    test_setZ(point3, 3, {0, 0, 3});

    if(exit_value == EXIT_SUCCESS) cout << "All tests were successful" << endl;

    return exit_value;
}
