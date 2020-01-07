
#include "geometry.h"
#include <iostream>
using namespace std;

#define EMPTY_BUFFER while(getchar() != '\n')

bool addPointState(Space space, size_t x, size_t y, size_t z);


bool addPointState(Space space, size_t x, size_t y, size_t z) {
    bool alreadySet = space[x][y][z] == EXIST ? true : false;
    space[x][y][z] = EXIST;
    return alreadySet;
}

int getNbrPoints()
{
    int nbrPoints;
    bool valueOK;
    bool inputOK;
    do
    {
        cout << "Please, enter the number of points you want : ";
        cin >> nbrPoints;
        
        inputOK = cin.good();
        valueOK = nbrPoints < 0;
        if(!inputOK)
            cin.clear();
        EMPTY_BUFFER;
        
    } while((!inputOK or !valueOK) and cout << "Incorrect input, please try again\n");
    
    return nbrPoints;
}

bool getPoint(int& x, int& y, int& z)
{
    cout << "Please, enter a point [X Y Z] : ";
    cin >> x >> y >> z;
    bool inputOK  = cin.good();
    bool valuesOK = x < 0 or y < 0 or z < 0;
   
    if(!inputOK)
        cin.clear();
    EMPTY_BUFFER;
    
    return (inputOK or valuesOK);
}

PointList getPointList()
{
    PointList list;
    int nbrPoints = getNbrPoints();
    list.resize(nbrPoints);
    for(int i = 0; i < nbrPoints; ++i)
    {
        list[i].resize(3);
        int x, y, z;
        while(!getPoint(x, y, z))
        {
            cout << "Incorrect input, please try again\n";
        }
        list[i][0] = x;
        list[i][1] = y;
        list[i][2] = z;
    }
    
    return list;
}

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
        cout << (line[i] == EXIST ? 'O': '.');
    }
}

void fillSpace(Space& space, PointList list)
{
    // size_t max_x;
    // for () {

    // }
    // for (aut PointState: list) {
    //     size_t x = PointState[0];
    //     space[0][PointState[0]][PointState[1]] true;
    //     space[1][PointState[1]][PointState[2]] true;
    //     space[2][PointState[0]][PointState[2]] true;

    // }
}

Map projection(const Space& space, MapCode code)
{
    return space[code];
}