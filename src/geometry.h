#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

enum PointState {
    EMPTY,
    EXIST
};

enum MapCode {
    MAPCODE_XY,
    MAPCODE_XZ,
    MAPCODE_YZ
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
Space getSpace(PointList list);
void fillSpace(Space& space, PointList list);
Map projection(const Space& space, MapCode code);


Coordinate getX(Point point);
Coordinate getY(Point point);
Coordinate getZ(Point point);

#endif // GEOMETRY_H