
#include "geometry.h"
#include <iostream>
using namespace std;

#define EMPTY_BUFFER while(getchar() != '\n')

bool addPointState(Space space, size_t x, size_t y, size_t z);

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
    Space space(3);
    space[MAPCODE_XY] = initMap(max_x, max_y); // MAPCODE_XY
    space[MAPCODE_YZ] = initMap(max_y, max_z); // MAPCODE_YZ
    space[MAPCODE_XZ] = initMap(max_x, max_z); // MAPCODE_XZ

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

    } while((!inputOK or !valueOK)); // and cout << "Incorrect input, please try again\n"

    return nbrPoints;
}

bool getPoint(int& x, int& y, int& z)   {
    cout << "Please, enter a point [X Y Z] : ";
    cin >> x >> y >> z;
    cout << endl;
    bool inputOK  = cin.good();
    bool valuesOK = x >= 0 or y >= 0 or z >= 0;

    if(!inputOK) cin.clear();
    EMPTY_BUFFER;

    return (inputOK or valuesOK);
}

PointList getPointList() {
    PointList list;
    int nbrPoints = getNbrPoints();
    list.resize(nbrPoints);
    for(int i = 0; i < nbrPoints; ++i) {
        list[i].resize(3);
        int x, y, z;
        while(!getPoint(x, y, z))
            cout << "Incorrect input, please try again\n";

        list[i][0] = x;
        list[i][1] = y;
        list[i][2] = z;
    }

    return list;
}

void displayMap(const Map& map) {
    for(Line line: map) {
        displayLine(line);
        cout << endl;
    }

}

void displayLine(const Line& line) {
    for(size_t i = 0; i < line.size(); ++i) {
        cout << (line[i] == EXIST ? 'O': '.');
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
    cout << max_x << endl;
    cout << max_y << endl;
    cout << max_z << endl;

    Space space = initSpace(max_x + 1, max_y + 1, max_z + 1);

    cout << "space has been init" << endl;

    for(const auto& point: list) 
        addPoint(point, space);
    
    cout << "projections have been done" << endl;

    return space;
}

void project(Point point, Map& map, MapCode code) {
    switch (code) {
        case MAPCODE_XY :
            map[getX(point)][getY(point)] = EXIST;
            cout << "map size " << map.size() << " " << map[0].size() << endl;
            cout << "point " << getX(point) <<  " " << getY(point) << endl;
            break;
        case MAPCODE_XZ :
            map[getX(point)][getZ(point)] = EXIST;
            cout << "map size " << map.size() << " " << map[0].size() << endl;
            cout << "point " << getX(point) <<  " " << getZ(point) << endl;
            break;
        case MAPCODE_YZ :
            cerr << "fdsa\n";
            cerr << map.size() << ' ' << getY(point) << endl;
            cerr << map[getY(point)].size() << ' ' << getZ(point) << endl;
            map[getY(point)][getZ(point)] = EXIST;
            cerr << "rerwe\n";
            cout << "map size " << map.size() << " " << map[0].size() << endl;
            cout << "point " << getY(point) <<  " " << getZ(point) << endl;
            break;
    }
}

void addPoint(Point point, Space& space) {
    cout << "1\n";
    project(point, space[MAPCODE_XY], MAPCODE_XY);
    cout << "2\n";
    project(point, space[MAPCODE_XZ], MAPCODE_XZ);
    cout << "3\n";
    project(point, space[MAPCODE_YZ], MAPCODE_YZ);
    cout << "4\n";
}

Map getProjection(const Space& space, MapCode code)
{
    return space[code];
}