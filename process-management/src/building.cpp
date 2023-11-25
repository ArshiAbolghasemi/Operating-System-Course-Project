#include "../include/building.hpp"

Building::Building(std::string _dataPath)
{
    this->dataPath = _dataPath;
}

Building::~Building() {}

std::string Building::getName() { return this->dataPath; }