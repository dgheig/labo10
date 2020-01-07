
#include "geometry.h"

bool addPointState(Space space, size_t x, size_t y, size_t z) {
    bool alreadySet = space[x][y][z] == EXIST ? true : false;
    space[x][y][z] = EXIST;
    return alreadySet;
}


void displayMap(const Map& map)
{

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
    return Map();
}