
#include "geometry.h"
#include <iostream>
using namespace std;

#define EMPTY_BUFFER while(getchar() != '\n')

bool addPointState(Space space, size_t x, size_t y, size_t z);
Space initSpace(Coordinate max_x, Coordinate max_y, Coordinate max_z);

// bool addPointState(Space space, size_t x, size_t y, size_t z) {
//     bool alreadySet = space[x][y][z] == EXIST ? true : false;
//     space[x][y][z] = EXIST;
//     return alreadySet;
// }

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

int getNbrPoints()
{
    int nbrPoints;
    bool valueOK;
    bool inputOK;
    do
    {
        cout << "Please, enter the number of points you want : ";
        cin >> nbrPoints;
        cout << endl;

        inputOK = cin.good();
        valueOK = nbrPoints >= 0;
        if(!inputOK)
            cin.clear();
        EMPTY_BUFFER;

    } while((!inputOK or !valueOK)); // and cout << "Incorrect input, please try again\n"

    return nbrPoints;
}

bool getPoint(int& x, int& y, int& z)
{
    cout << "Please, enter a point [X Y Z] : ";
    cin >> x >> y >> z;
    cout << endl;
    bool inputOK  = cin.good();
    bool valuesOK = x >= 0 or y >= 0 or z >= 0;

    if(!inputOK)
        cin.clear();
    EMPTY_BUFFER;

    return (inputOK or valuesOK);
}

PointList getPointList()
{
    PointList list;
    int nbrPoints = getNbrPoints();
    list.resize(nbrPoints);
    for(int i = 0; i < nbrPoints; ++i)
    {
        list[i].resize(3);
        int x, y, z;
        while(!getPoint(x, y, z))
        {
            cout << "Incorrect input, please try again\n";
        }
        list[i][0] = x;
        list[i][1] = y;
        list[i][2] = z;
    }

    return list;
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

    cout << "getting space" << endl;

    size_t max_x = 0;
    size_t max_y = 0;
    size_t max_z = 0;
    for (const auto& point: list) {
        if (getX(point) > max_x) max_x = getX(point);
        if (getY(point) > max_y) max_y = getY(point);
        if (getZ(point) > max_z) max_z = getZ(point);
    }

    cout << "max dimension has been found" << endl;

    Space space = initSpace(max_x, max_y, max_z);

    cout << "space has been init" << endl;

    for(const auto& point: list) {
        size_t x = (size_t) getX(point);
        size_t y = (size_t) getY(point);
        size_t z = (size_t) getZ(point);

        space[MAPCODE_XY][x][y] = EXIST;
        space[MAPCODE_YZ][y][z] = EXIST;
        space[MAPCODE_XZ][x][z] = EXIST;
    }

    cout << "projections have been done" << endl;

    return space;
}

Map projection(const Space& space, MapCode code)
{
    return space[code];
}