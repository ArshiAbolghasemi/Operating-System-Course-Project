#ifndef _BUILDING_HPP_
#define _BUILDING_HPP_

#include <string>

class Building
{
private:
    std::string dataPath;
public:
    Building(std::string _dataPath);
    ~Building();
    std::string getName();
};

#endif