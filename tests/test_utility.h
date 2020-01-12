#ifndef TEST_UTILITY_H
#define TEST_UTILITY_H

#include <iostream>
#include "../src/geometry.h"

bool compareLine(const Line& line1, const Line& line2);
bool compareMap(const Map& map1, const Map& map2);
bool compareSpace(const Space& space1, const Space& space2);

bool compareLine(const Line& line1, const Line& line2) {
    if (line1.size() != line2.size()) return false;
    for (size_t index = 0; index < line1.size(); ++index) {
        if (line1[index] != line2[index]) return false;
    }
    return true;
}

bool compareMap(const Map& map1, const Map& map2) {
    if (map1.size() != map2.size()) return false;
    for (size_t index = 0; index < map1.size(); ++index) {
        if (!compareLine(map1[index], map2[index])) return false;
    }
    return true;
}

bool compareSpace(const Space& space1, const Space& space2) {
    if (space1.size() != space2.size()) return false;
    for (size_t index = 0; index < space1.size(); ++index) {
        if (!compareMap(space1[index], space2[index])) return false;
    }
    return true;
}

void displayPointList(const PointList& list) {
    for (const Point& point: list) {
        std::cerr << '('
                  << getX(point) << ' '
                  << getY(point) << ' '
                  << getZ(point) << ')' << std::endl;
    }
}

// Space getSpace(const PointList& list);
// void project(const PointList& list, Map& map, MapCode code);
// void addPoint(Space& space, Point point);
// Map getProjection(const Space& space, MapCode code);

// Coordonate getX(const Point& point);
// Coordonate getY(const Point& point);
// Coordonate getZ(const Point& point);

// void setX(Point& point, Coordonate value);
// void setY(Point& point, Coordonate value);
// void setZ(Point& point, Coordonate value);

#endif // TEST_UTILITY_H