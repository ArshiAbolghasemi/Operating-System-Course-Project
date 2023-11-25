#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../util/colors.hpp"

class Table
{
private:
    std::vector<std::string> cols;
    std::map<int, std::map<std::string, std::string>> rows;
    int lastRow;
public:
    Table();
    ~Table();
    void setColumns(std::vector<std::string> cols);
    void addRows(std::map<int, std::map<std::string, std::string>> rows);
    void print();
};


#endif