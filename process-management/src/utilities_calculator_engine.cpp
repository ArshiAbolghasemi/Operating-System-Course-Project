#include "../include/utilities_calculator_engine.hpp"

UtilitiesCalculatorEngine::UtilitiesCalculatorEngine(int argc, char* argv[])
{
    if (argc != 2) {
        Log::error("usage: ./utilities_calculator_engine <buildings data file path>");
        throw new std::exception();
    }
    
    this->buildingsDataPath = argv[1];

    std::tuple<int, std::vector<std::string>> buildingsSubdir = 
        FileService::getSubDirectories(this->buildingsDataPath);
    this->buildingsCount = std::get<0>(buildingsSubdir);
    for (const auto buildingPath : std::get<1>(buildingsSubdir)) {
        this->buildings.push_back(new Building(buildingPath));
    }
}

UtilitiesCalculatorEngine::~UtilitiesCalculatorEngine() 
{
    for (auto building : this->buildings) delete building;
}

void UtilitiesCalculatorEngine::printBuildings()
{
    Log::info("buildings count: %d", this->buildingsCount);

    Table* table = new Table();
    table->setColumns({"id", "building_name"});
    std::map<int, std::map<std::string, std::string>> rows;
    for (int bid = 0; bid < this->buildings.size(); bid++) {
        rows[bid] = {
            {"id", std::to_string(bid)},
            {"building_name", this->buildings[bid]->getName()},
        };
    }
    table->addRows(rows);
    std::cout << std::endl << std::endl;
    table->print();
    std::cout << std::endl << std::endl;
    delete table;
}

int UtilitiesCalculatorEngine::runWorkers()
{
    pid_t billsWorkerPid = fork();

    if (billsWorkerPid < 0) {
        Log::error("failed to created bills worker");
        return EXIT_FAILURE;
    } else if (billsWorkerPid > 0) {
        Log::info("bills worker is created");
    }

    for(int i = 0; i < this->buildings.size(); i++) {
        pid_t buildingWorker = fork();

        if (buildingWorker < 0) {
            Log::error("failed to create buildingn %d worker", i);
            return EXIT_FAILURE;
        } else if (buildingWorker > 0) {
            Log::info("building %d process is created", i);
        }
    }    

    return EXIT_SUCCESS;
}

int UtilitiesCalculatorEngine::run()
{
    Log::info("utilities calculator engine is started");
    Log::info("reading building path file");
    this->printBuildings();
    this->runWorkers();
    return EXIT_SUCCESS;
}