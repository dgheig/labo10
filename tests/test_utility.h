#ifndef TEST_UTILITY_H
#define TEST_UTILITY_H

#include <iostream>
#include "../src/geometry.h"

bool comparePoint(const Point& point1, const Point& point2);
bool compareLine(const Line& line1, const Line& line2);
bool compareMap(const Map& map1, const Map& map2);
bool compareSpace(const Space& space1, const Space& space2);

void displayPoint(const Point& point);
void displayPointList(const PointList& list);

bool comparePoint(const Point& point1, const Point& point2) {
    if (
        getX(point1) == getX(point2) and
        getY(point1) == getY(point2) and
        getZ(point1) == getZ(point2)
    ) return true;
    return false;
}

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

void displayPoint(const Point& point) {
    std::cout << '('
              << getX(point) << ' '
              << getY(point) << ' '
              << getZ(point) << ')' << std::endl;
}

void displayPointList(const PointList& list) {
    for (const Point& point: list) {
        displayPoint(point);
    }
}

#endif // TEST_UTILITY_H