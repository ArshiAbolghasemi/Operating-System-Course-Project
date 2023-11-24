#include "../../include/service/csv_reader.hpp"

std::map<int, std::map<std::string, std::string>> 
    CSVReader::read(std::string filePath)
{
    std::ifstream file(filePath);

    if (!file.is_open()) {
        Log::error("cannot open %s!", filePath);
        throw new std::runtime_error("failed to open file");
    }

    std::map<int, std::map<std::string, std::string>> data;

    std::string header;
    std::getline(file, header);
    std::istringstream headerStream(header);
    
    std::vector<std::string> columnNames;
    std::string columnName;
    while (std::getline(headerStream, columnName, ',')) {
        columnNames.push_back(columnName);
    }

    std::string line;
    int colIdx = 0;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::vector<std::string> values;
        std::string value;

        while (std::getline(lineStream, value, ',')) {
            values.push_back(value);
        }

        std::map<std::string, std::string> rowData;
        for (size_t i = 0; i < columnNames.size(); ++i) {
            rowData[columnNames[i]] = values[i];
        }

        data[colIdx++] = rowData;
    }

    file.close();

    return data;
}