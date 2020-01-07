
#include "geometry.h"
#include <iostream>
using namespace std;

bool addPointState(Space space, size_t x, size_t y, size_t z) {
    bool alreadySet = space[x][y][z] == EXIST ? true : false;
    space[x][y][z] = EXIST;
    return alreadySet;
}

void displayMap(const Map& map)
{
    for(size_t i = 0; i < map.size(); ++i)
    {
        displayLine(map[i]);
        cout << endl;
    }

}

void displayLine(const Line& line)
{
    for(size_t i = 0; i < line.size(); ++i)
    {
        cout << (line[i] == EXIST ? 'O': '.');
    }
}

void fillSpace(Space& space, PointList list)
{
    // size_t max_x;
    // for () {

    // }
    // for (aut PointState: list) {
    //     size_t x = PointState[0];
    //     space[0][PointState[0]][PointState[1]] true;
    //     space[1][PointState[1]][PointState[2]] true;
    //     space[2][PointState[0]][PointState[2]] true;

    // }
}

Map projection(const Space& space, MapCode code)
{
    return space[code];
}