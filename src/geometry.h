#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

typedef bool Point;
enum Point {
   EMPTY,
   EXIST
};
typedef std::vector<Point> axeZ;
typedef std::vector<axeZ> axeY;
typedef std::vector<axeY> axeX;


#endif // GEOMETRY_H