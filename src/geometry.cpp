
#include "geometry.h"
#include <iostream>

using namespace std;

#define EMPTY_BUFFER while(getchar() != '\n')

//-----------------------------------------------------------------------------------
/**
  * @brief  Reseve the place for the projections and set all to EMPTY
  * @param  [in] Coordonate max_x The maximum Coordonate X of all the points in the space
  * @param  [in] Coordonate max_z The maximum Coordonate Y of all the points in the space
  * @param  [in] Coordonate max_y The maximum Coordonate Z of all the points in the space
  * @return Space The place for the projections
  */
Space initSpace(Coordonate max_x, Coordonate max_y, Coordonate max_z);

/**
  * @brief  Ask the user for coordonates
  * @param  [in][out] int& x
  * @param  [in][out] int& y
  * @param  [in][out] int& z
  */
void getValues(int& x, int& y, int& z);

/**
  * @brief  Get a valid coordonate values from the user
  * @param  [in][out] int& x
  * @param  [in][out] int& y
  * @param  [in][out] int& z
  */
void getValidValues(int& x, int& y, int& z);

/**
  * @brief  Get a valid point from the user
  * @return Point Point input by the user
  */
Point askValidPoint();

/**
  * @brief  Get the number of point the user want to set at EXIST
  * @return int The number of points desired
  */
int getNbrPoints();


//-----------------------------------------------------------------------------------
Map initMap(size_t height, size_t width) {
    Map map(height);
    for (Line& line: map) {
        line.resize(width, EMPTY);
    }
    return map;
}

Space initSpace(Coordonate max_x, Coordonate max_y, Coordonate max_z) {
    Space space(3);
    space[MAPCODE_XY] = initMap(max_x, max_y);
    space[MAPCODE_YZ] = initMap(max_y, max_z);
    space[MAPCODE_XZ] = initMap(max_x, max_z);

    return space;
}

Coordonate getX(const Point& point) {
    if (point.size() > 0) return point[0];
    return 0;
}
Coordonate getY(const Point& point) {
    if (point.size() > 1) return point[1];
    return 0;
}
Coordonate getZ(const Point& point) {
    if (point.size() > 2) return point[2];
    return 0;
}

void ensureDim3(Point& point) {
    if(point.size() < 3) point.resize(3, 0);
}

void setX(Point& point, Coordonate value) {
    ensureDim3(point);
    point[0] = value;
}

void setY(Point& point, Coordonate value) {
    ensureDim3(point);
    point[1] = value;
}

void setZ(Point& point, Coordonate value) {
    ensureDim3(point);
    point[2] = value;
}
int getNbrPoints() {
    int nbrPoints;
    bool validInput;
    bool cinFailed;
    do {
        do
        {
            cout << "Please, enter the number of points you want : ";
            cin  >> nbrPoints;
            cout << endl;

            cinFailed = cin.fail();
            if (cinFailed)
            {
                cin.clear();
                cerr << "cin failed, please, try again." << endl
                     << "make sur to input positiv value" << endl;
            }
            EMPTY_BUFFER;
        } while (cinFailed);


        validInput = nbrPoints >= 0;

        if (!validInput)
            cerr << "Incorrect input, value must be positiv" << endl
                 << "please try again"                       << endl;

    } while(!validInput);

    return nbrPoints;
}

void getValues(int& x, int& y, int& z) {
    bool cinFailed;
    do
    {
        cout << "Please, enter a point [X Y Z] : ";
        cin  >> x >> y >> z;
        cinFailed = cin.fail();
        if (cinFailed)
        {
            cin.clear();
            cerr << "cin failed, please, try again." << endl
                 << "make sur to input positiv values separated by space" << endl;
        }
        EMPTY_BUFFER;
    } while (cinFailed);
}

void getValidValues(int& x, int& y, int& z) {

    getValues(x, y, z);

    while (x < 0 or y < 0 or z < 0)
    {
        cerr << "Incorrect input, values must be positiv" << endl
             << "please try again"                        << endl;
        getValues(x, y, z);
    }
}

Point askValidPoint() {
    int x, y, z;
    getValidValues(x, y, z);

    return Point({(Coordonate)x, (Coordonate)y, (Coordonate)z});
}

PointList getPointList() {

    int nbrPoints = getNbrPoints();
    PointList list(nbrPoints);

    for (Point& point: list) {
        point = askValidPoint();
    }
    cout << endl;
    return list;
}

void displayMap(const Map& map, MapCode code, char exist, char empty) {

    switch (code) {
        case MAPCODE_XY :
            cout << " Y\nX";
            break;
        case MAPCODE_XZ :
            cout << " Z\nX";
            break;
        case MAPCODE_YZ :
            cout << " Z\nY";
            break;
    }

    for (const Line& line: map) {
        displayLine(line, exist, empty);
        cout << endl << " ";
    }

}

void displayLine(const Line& line, char exist, char empty) {
    for (PointState point: line) {
        cout << (point == EXIST ? exist : empty);
    }
}


Space getSpace(const PointList& list) {

    size_t max_x = 0;
    size_t max_y = 0;
    size_t max_z = 0;

    for (const auto& point: list) {
        if (getX(point) > max_x) max_x = getX(point);
        if (getY(point) > max_y) max_y = getY(point);
        if (getZ(point) > max_z) max_z = getZ(point);
    }

    Space space = initSpace(max_x + 1, max_y + 1, max_z + 1);

    for (const Point& point: list)
        addPoint(space, point);

    return space;
}

void project(const Point& point, Map& map, MapCode code) {
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

void addPoint(Space& space, Point point) {
    project(point, space[MAPCODE_XY], MAPCODE_XY);
    project(point, space[MAPCODE_XZ], MAPCODE_XZ);
    project(point, space[MAPCODE_YZ], MAPCODE_YZ);
}

Map getProjection(const Space& space, MapCode code)
{
    return space[code];
}