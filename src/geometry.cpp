
#include "geometry.h"
#include <iostream>
using namespace std;

#define EMPTY_BUFFER while(getchar() != '\n')

/**
  * @brief  Reseve the place for the projections and set all to EMPTY
  * @param  [in] Coordinate max_x The maximum coordinate X of all the points in the space
  * @param  [in] Coordinate max_z The maximum coordinate Y of all the points in the space
  * @param  [in] Coordinate max_y The maximum coordinate Z of all the points in the space
  * @return Space The place for the projections
  */
Space initSpace(Coordinate max_x, Coordinate max_y, Coordinate max_z);

/**
  * @brief  Get a point from the user
  * @param  [in][out] int& x
  * @param  [in][out] int& y
  * @param  [in][out] int& z
  * @return bool True if the input is correct
  */
bool getPoint(int& x, int& y, int& z);

/**
  * @brief  Get the number of point the user want to set at EXIST
  * @return int The number of points desired
  */
int getNbrPoints();


Map initMap(size_t height, size_t width) {
    Map map(height);
    for (auto& line: map) {
        line.resize(width, EMPTY);
    }
    return map;
}

Space initSpace(Coordinate max_x, Coordinate max_y, Coordinate max_z) {
    Space space(3);
    space[MAPCODE_XY] = initMap(max_x, max_y);
    space[MAPCODE_YZ] = initMap(max_y, max_z);
    space[MAPCODE_XZ] = initMap(max_x, max_z);

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

int getNbrPoints() {
    int nbrPoints;
    bool valueOK;
    bool inputOK;
    do {
        cout << "Please, enter the number of points you want : ";
        cin  >> nbrPoints;
        cout << endl;

        inputOK = cin.good();
        valueOK = nbrPoints >= 0;
        if(!inputOK) cin.clear();
        EMPTY_BUFFER;

        if(!valueOK or !inputOK)
            cout << "Incorrect input, please try again\n";
        
    } while((!inputOK or !valueOK));

    return nbrPoints;
}

bool getPoint(int& x, int& y, int& z)   {
    cout << "Please, enter a point [X Y Z] : ";
    cin >> x >> y >> z;
 
    bool inputOK  = cin.good();
    bool valuesOK = x >= 0 or y >= 0 or z >= 0;

    if(!inputOK) cin.clear();
    EMPTY_BUFFER;

    if(!valuesOK or !inputOK)
        cout << "Incorrect input, please try again\n";
    
    return (inputOK and valuesOK);
}

PointList getPointList() {
    PointList list;
    int nbrPoints = getNbrPoints();
    list.resize(nbrPoints);
    for(Point point: list) {
        point.resize(3);
        int x, y, z;
        while(!getPoint(x, y, z));

        point[0] = x;
        point[1] = y;
        point[2] = z;
    }
    cout << endl;
    return list;
}

void displayMap(const Map& map) {
    for(Line line: map) {
        displayLine(line);
        cout << endl;
    }

}

void displayLine(const Line& line) {
    for(auto point: line) {
        cout << (point == EXIST ? 'O': '.');
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

    Space space = initSpace(max_x + 1, max_y + 1, max_z + 1);

    for(const auto& point: list)
        addPoint(point, space);

    return space;
}

void project(Point point, Map& map, MapCode code) {
    switch (code) {
        case MAPCODE_XY :
            map[getX(point)][getY(point)] = EXIST;
            break;
        case MAPCODE_XZ :
            map[getX(point)][getZ(point)] = EXIST;
            break;
        case MAPCODE_YZ :
            map[getY(point)][getZ(point)] = EXIST;
            break;
    }
}

void addPoint(Point point, Space& space) {
    project(point, space[MAPCODE_XY], MAPCODE_XY);
    project(point, space[MAPCODE_XZ], MAPCODE_XZ);
    project(point, space[MAPCODE_YZ], MAPCODE_YZ);
}

Map getProjection(const Space& space, MapCode code)
{
    return space[code];
}