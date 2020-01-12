/*
-----------------------------------------------------------------------------------
Laboratoire : labo_10
Fichier     : test_getSpace.cpp
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


bool testGetSpace (const PointList& list, const Space& space, bool expected = true) {
    if(compareSpace(space, getSpace(list)) != expected)
    {
        // cerr << "Test function getSpace" << endl
        //      << "input PointList:"       << endl;
        // displayPointList(list);

        // cerr << "compared to space:"     << endl;
        // displa

        exit_value = EXIT_FAILURE;
    }
}

int main() {

    PointList list1 = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}
    }

    Space expected1 = {
        {
            {}
        }
    }

    testGetSpace(list1, )



    // model(. . ., true);

    return exit_value;
}
