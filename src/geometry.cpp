
#include "geometry.h"
#include <iostream>
using namespace std;

bool addPointState(Space space, size_t x, size_t y, size_t z);
Space initSpace(Coordinate max_x, Coordinate max_y, Coordinate max_z);
Coordinate getX(Point point);
Coordinate getY(Point point);
Coordinate getZ(Point point);

bool addPointState(Space space, size_t x, size_t y, size_t z) {
    bool alreadySet = space[x][y][z] == EXIST ? true : false;
    space[x][y][z] = EXIST;
    return alreadySet;
}

Map initMap(size_t height, size_t width) {
    Map map(height);
    for (auto& line: map) {
        line.resize(width, EMPTY);
    }
    return map;
}

Space initSpace(Coordinate max_x, Coordinate max_y, Coordinate max_z) {
    Space space {
        initMap(max_x, max_y), // MAPCODE_XY
        initMap(max_y, max_z), // MAPCODE_XZ
        initMap(max_x, max_z)  // MAPCODE_YZ
    };

    return space;
}


Coordinate getX(Point point) {
    if (point.size() > 0) return point[0];
    return 0;
}
Coordinate getY(Point point) {
    if (point.size() > 1) return point[1];
    return 0;
}
Coordinate getZ(Point point) {
    if (point.size() > 2) return point[2];
    return 0;
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
    for (auto point: list) {
        space[MAPCODE_XY][getX(point)][getY(point)] = EXIST;
        space[MAPCODE_YZ][getY(point)][getZ(point)] = EXIST;
        space[MAPCODE_XZ][getX(point)][getZ(point)] = EXIST;
    }
}


Space getSpace(PointList list) {
    size_t max_x = 0;
    size_t max_y = 0;
    size_t max_z = 0;
    for (const auto& point: list) {
        if (getX(point) > max_x) max_x = getX(point);
        if (getY(point) > max_y) max_y = getY(point);
        if (getZ(point) > max_z) max_z = getZ(point);
    }

    Space space = initSpace(max_x, max_y, max_z);

    for(const auto& point: list) {
        size_t x = (size_t) getX(point);
        size_t y = (size_t) getY(point);
        size_t z = (size_t) getZ(point);

        space[MAPCODE_XY][x][y] = EXIST;
        space[MAPCODE_YZ][y][z] = EXIST;
        space[MAPCODE_XZ][x][z] = EXIST;
    }

    return space;
}

Map projection(const Space& space, MapCode code)
{
    return space[code];
}