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

bool test_point_get(const Point& point, Coordonate x, Coordonate y, Coordonate z) {
    if (
        getX(point) != x or
        getY(point) != y or
        getZ(point) != z
    ) {
        cerr << "Error, expected:" << endl
             << x << ' ' << y << ' ' << z << endl
             << "got:"
             << getX(point) << ' ' << getY(point) << ' ' << getZ(point) << endl;
        exit_value = EXIT_FAILURE;
        return false;
    }
    return true;
}

int main() {

    test_point_get(
        {1},
        1, 0, 0
    );

    test_point_get(
        {1, 2},
        1, 2, 0
    );


    test_point_get(
        {1, 2, 3, 4},
        1, 2, 3
    );

    if(exit_value == EXIT_SUCCESS) cout << "All tests where successful" << endl;

    return exit_value;
}
