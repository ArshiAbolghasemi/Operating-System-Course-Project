#include "../../include/util/table.hpp"

Table::Table() {}

Table::~Table() {}

void Table::setColumns(std::vector<std::string> cols) { this->cols = cols; }

void Table::addRows(std::map<int, std::map<std::string, std::string>> rows)
{
    if (this->rows.empty()) {
        this->rows = rows;
        this->lastRow = this->rows.size() - 1;
        return;
    }

    for (auto row : rows) {
        this->rows[this->lastRow] = row.second;
        this->lastRow ++;
    }

    return;
}

void Table::print()
{
    int colSize = this->cols.size();
    for (int i = 0; i < colSize; i++) {
        if (i != 0) std::cout << colors::Yellow + " \\ " + colors::Reset;
        
        std::cout << colors::CYAN + this->cols[i] + colors::Reset;
    }

    std::cout << std::endl;

    for (int i = 0; i < colSize; i++) 
        for(int j = 0; j < this->cols[i].length() ; j++)
            std::cout << "-";

    for (auto row : this->rows) {
        std::cout << std::endl;

        for (int i = 0; i < colSize; i++) {
            if (i != 0) std::cout << colors::Yellow + " \\ " + colors::Reset;
            
            std::cout << colors::MAGENTA + row.second[this->cols[i]] + colors::Reset;
        }

        std::cout << std::endl;
        for (int i = 0; i < colSize; i++) 
            for(int j = 0; j < this->cols[i].length() ; j++)
                std::cout << "-";
    }
    std::cout << std::endl;
}