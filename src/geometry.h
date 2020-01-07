#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

enum PointState {
    EMPTY,
    EXIST
};

enum MapCode {
    XY,
    XZ,
    YZ
};

typedef std::size_t Coordinate;
typedef std::vector<Coordinate> Point;
typedef std::vector<Point> PointList;

typedef std::vector<PointState> Line;
typedef std::vector<Line> Map;
typedef std::vector<Map> Space;

PointList getPointList();
void displayLine(const Line& line);
void displayMap(const Map& map);
void fillSpace(Space& space, PointList list);
Map projection(const Space& space, MapCode code);

#endif // GEOMETRY_H