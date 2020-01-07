
#include "geometry.h"

using namespace std;

void displayMap(const Map& map)
{
    for(size_t i = 0; i < map.size(); ++i)
    {
        displayLine(map[i]);
        cout << endl;
    }

}

void displayLine(const Line& line)
{
    for(size_t i = 0; i < line.size(); ++i)
    {
        cout << line[i] == EXIST ? 'O': '.';
    }
}

void fillSpace(Space& space)
{

}

Map projection(const Space& space, MapCode code)
{
    return space[code];
}