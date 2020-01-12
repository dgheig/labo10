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

typedef std::size_t Coordonate;
typedef std::vector<Coordonate> Point;
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
  * @param  [in] char        exist Display for a point
  *                                Default value 'O'
  * @param  [in] char        empty Display for a place empty
  *                                Default value '.'
  */
void displayLine(const Line& line, char exist = 'O', char empty = '.');

/**
  * @brief  Display a map
  * @param  [in] const Map& map
  * @param  [in] char       exist Display for a point
  *                               Default value 'O'
  * @param  [in] char       empty Display for a place empty
  *                               Default value '.'
  */
void displayMap(const Map& map, MapCode code, char exist = 'O', char empty = '.');

/**
  * @brief  Create a space conatin the three projections
  * @param  [in] PointList list The list of the points in the space
  * @return Space Contain the three projections
  */
Space getSpace(const PointList& list);

/**
  * @brief  Project a point in a map (XY, XZ or YZ)
  * @param  [in]      Point     point
  * @param  [in][out] Map&      map  The map for the projection
  * @param  [in]      MapCode   code Code of the diection of the projection
  */
void project(const Point& point, Map& map, MapCode code);

/**
  * @brief  Add a point to all of projections in space
  * @param  [in]      PointList list
  * @param  [in][out] Space&    space The space where the maps projections are saved
  */
void addPoint(Space& space, Point point);

/**
  * @brief  Get the projection of the map asked by the mapcode
  * @param  [in] const Space& space
  * @param  [in] MapCode      code  The code for the direction of the projection
  * @return Map The map of the projection asked
  */
Map getProjection(const Space& space, MapCode code);

/**
  * @brief  Get the Coordonate X from a point
  * @param  [in] Point point
  * @return Coordonate The Coordonate X of the point
  */
Coordonate getX(const Point& point);

/**
  * @brief  Get the Coordonate Y from a point
  * @param  [in] Point point
  * @return Coordonate The Coordonate Y of the point
  */
Coordonate getY(const Point& point);

/**
  * @brief  Get the Coordonate Z from a point
  * @param  [in] Point point
  * @return Coordonate The Coordonate Z of the point
  */
Coordonate getZ(const Point& point);

/**
  * @brief  Set the Coordonate X from a point
  * @param  [in][out] Point      point
  * @param  [in]      Coordonate value
  */
void setX(Point& point, Coordonate value);

/**
  * @brief  Set the Coordonate Y from a point
  * @param  [in][out] Point      point
  * @param  [in]      Coordonate value
  */
void setY(Point& point, Coordonate value);

/**
  * @brief  Set the Coordonate Z from a point
  * @param  [in][out] Point      point
  * @param  [in]      Coordonate value
  */
void setZ(Point& point, Coordonate value);

#endif // GEOMETRY_H