/*
-----------------------------------------------------------------------------------
Laboratoire : labo_10
Fichier     : labo_10_comte_emmanuelle_gallay_david.cpp
Auteur(s)   : Emmanuelle Comte et David Gallay
Date        :

But         :
Remarque(s) :

                There is the github repository:
                https://github.com/dgheig/labo10

Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "src/geometry.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {

    PointList list = getPointList();
    cout << "List has been filled" << endl;

    Space space = getSpace(list);
    cout << "Space has been filled" << endl;

    for(const auto& map: space) {
        displayMap(map);
    }

    WAIT_ENTER;
    return EXIT_SUCCESS;
}
