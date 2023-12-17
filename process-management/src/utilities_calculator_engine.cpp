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

std::vector<std::string> UtilitiesCalculatorEngine::getBuildingsFromUser()
{
    std::cout << "Enter comma-seperated buildings name: ";
    std::vector<std::string> input_buildings = CLI::getCommaSeperatedInput();
    return input_buildings;
}

std::vector<std::string> UtilitiesCalculatorEngine::getUtilitiesFromUser()
{
    std::cout << "Enter comma-seperated utilities: ";
    std::vector<std::string> input_utilities = CLI::getCommaSeperatedInput();
    return input_utilities;
}

std::vector<NamedPipe*> UtilitiesCalculatorEngine::createNamedPipes(std::vector<std::string> buildingNames)
{
    std::vector<NamedPipe*> namedPipes;
    for (auto name : buildingNames) {
        std::string fifoPath = "/tmp/" + name;
        namedPipes.push_back(new NamedPipe(fifoPath, 0666));
    }
    
    return namedPipes;
}

std::vector<UnnamedPipe*> UtilitiesCalculatorEngine::createUnnamedPipes(int inputBuildingsCnt)
{
    std::vector<UnnamedPipe*> unnamedPipes;
    while (inputBuildingsCnt--) {
        unnamedPipes.push_back(new UnnamedPipe());
    }
    unnamedPipes.push_back(new UnnamedPipe());

    return unnamedPipes;
}

int UtilitiesCalculatorEngine::runWorkers(std::vector<std::string> inputBuildings,
    std::vector<std::string> inputUtilities)
{
    std::cout << std::endl;
    std::vector<Worker*> workers;

    int inputBuildingsCnt = inputBuildings.size();
    std::vector<NamedPipe*> namedPipes = this->createNamedPipes(inputBuildings);
    std::vector<UnnamedPipe*> unnamedPipes = this->createUnnamedPipes(inputBuildingsCnt); 
    std::vector<NamedPipe*> copyNamedPipes = namedPipes;

    for(int bid = 0; bid < this->buildings.size(); bid++) {
        auto it = std::find(inputBuildings.begin(), inputBuildings.end(),
            this->buildings[bid]->getName());
        if (it == inputBuildings.end()) continue;

        pid_t buildingWorker = fork();

        if (buildingWorker < 0) {
            Log::error("failed to create building %s worker",
                Color::color(this->buildings[bid]->getName(), colors::Red).c_str());
            return EXIT_FAILURE;
        } else if (buildingWorker == 0) {
            NamedPipe* namedPipe = copyNamedPipes.back();
            copyNamedPipes.pop_back();
            UnnamedPipe* unnamedPipe = unnamedPipes.back();
            unnamedPipes.pop_back();
            Worker* worker = new BuildingsWorker(getpid(), this->buildings[bid]->getName(), bid,
                namedPipe, unnamedPipe, inputUtilities, this->buildingsDataPath);
            workers.push_back(worker);    
            Log::info("process %s is created for building %s worker", 
                Color::color(std::to_string(getpid()), colors::CYAN).c_str(),
                Color::color(this->buildings[bid]->getName(), colors::CYAN).c_str());
            if (worker->execute() < 0) throw new std::runtime_error("buildings process failed");
            return EXIT_SUCCESS;
        }
    }    

    pid_t billsWorkerPid = fork();
    if (billsWorkerPid < 0) {
        Log::error("failed to created bills worker");
        return EXIT_FAILURE;
    } else if (billsWorkerPid > 0) {
        UnnamedPipe* unnamedPipe = unnamedPipes.back();
        unnamedPipes.pop_back();
        Worker* worker = new BillsWorker(getpid(), "bills", inputUtilities, namedPipes, unnamedPipe);
        workers.push_back(worker);
        Log::info("process %s is created for bills worker", 
            Color::color(std::to_string(getpid()), colors::CYAN).c_str());
        if (worker->execute() < 0) throw new std::runtime_error("bills process failed");
        return EXIT_SUCCESS;
    }

    int workerCounts = inputBuildingsCnt + 1;
    while (workerCounts--) wait(NULL);

    return EXIT_SUCCESS;
}

int UtilitiesCalculatorEngine::run()
{
    Log::info("utilities calculator engine is started");
    Log::info("reading building path file");
    this->printBuildings();
    std::vector<std::string> input_buildings = this->getBuildingsFromUser();
    std::vector<std::string> input_utilities = this->getUtilitiesFromUser();
    this->runWorkers(input_buildings, input_utilities);
    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    try {
        Log::info("start utilitis calculator engine");
        return EXIT_SUCCESS;
    } catch (std::exception& exception) {
        Log::error("utilities calculator engine failed");
        return EXIT_FAILURE;
    }
}