#ifndef _CSV_READER_HPP_
#define _CSV_READER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include "../util/log.hpp"

const std::string CSV_EXTENSION = ".csv";

class CSVReader
{
private:
public:
    static std::map<int, std::map<std::string, std::string>> 
        read(const std::string filePath);
};


#endif