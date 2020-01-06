#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

enum Point {
    EMPTY,
    EXIST
};

enum MapCode {
    XY,
    XZ,
    YZ
};

typedef std::vector<Point> Line;
typedef std::vector<Line> Map;
typedef std::vector<Map> Space;

void displayMap(const Map& map);
void fillSpace(Space& space);
Map projection(const Space& space, MapCode code);

#endif // GEOMETRY_H