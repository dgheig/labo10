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

/**
  * @brief  Get a point list from the user
  * @return PointList The point list the user enter
  */
PointList getPointList();

/**
  * @brief  Display a line
  * @param  [in] const Line& line  
  */
void displayLine(const Line& line);

/**
  * @brief  Display a map
  * @param  [in] const Map& map 
  */
void displayMap(const Map& map);

/**
  * @brief  Create a space conatin the three projections
  * @param  [in] PointList list The list of the points in the space
  * @return Space Contain the three projections
  */
Space getSpace(PointList list);

/**
  * @brief  Project a point in a map (XY, XZ or YZ)
  * @param  [in]      PointList list
  * @param  [in][out] Map&      map  The map for the projection
  * @param  [in]      MapCode   code Code of the diection of the projection
  */
void project(PointList list, Map& map, MapCode code);

/**
  * @brief  Add a point to all of projections in space
  * @param  [in]      PointList list
  * @param  [in][out] Space&    space The space where the maps projections are saved
  */
void addPoint(Point point, Space& space);
/**
  * @brief  
  * @param  [in] const Space& space 
  * @param  [in] MapCode      code  The code for the direction of the projection
  * @return Map The map of the projection asked
  */
Map getProjection(const Space& space, MapCode code);

/**
  * @brief  Get the coordinate X from a point
  * @param  [in] Point point  
  * @return Coodrinate The coordinate X of the point
  */
Coordinate getX(Point point);

/**
  * @brief  Get the coordinate Y from a point
  * @param  [in] Point point 
  * @return Coodrinate The coordinate Y of the point
  */
Coordinate getY(Point point);

/**
  * @brief  Get the coordinate Z from a point
  * @param  [in] Point point 
  * @return Coodrinate The coordinate Z of the point
  */
Coordinate getZ(Point point);

#endif // GEOMETRY_H