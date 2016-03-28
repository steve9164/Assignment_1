#include <fstream>
#include <string>
#include <map>
#include <QVector2D>

#include "initfile.h"

/* Config file is in the format specified below:
[Section header]
Objects=MyObject,Object2

[MyObject]
Position=xpos,ypos
Velocity=xvel,yvel
Mass=
Color=#00FF00


*/

struct ObjectConfig
{
    QPointF position;
    QPointF velocity;

};

InitFile::InitFile(std::string fileName)
: m_fileName(fileName)
{
    // Read the config file
    std::ifstream configFile(fileName);
    std::string line;
    std::string section;
    while (std::getline(configFile, line))
    {
        if (line.empty()) continue;

    }

}
