#include "../../include/worker/buildings_worker.hpp"

BuildingsWorker::BuildingsWorker(pid_t _pid, std::string _name, int _bid,
        NamedPipe* _namedPipe, UnnamedPipe* _unnamedPipe,
        std::vector<std::string> _utilities, std::string _buildingsDataFilePath) :
        Worker(_pid, _name)
{
    this->bid = _bid;
    this->namedPipe = _namedPipe;
    this->unnamedPipe = _unnamedPipe;
    this->utilities = _utilities;
    this->buildingsDataFilePath = _buildingsDataFilePath;
}

BuildingsWorker::~BuildingsWorker() {}    

int BuildingsWorker::execute()
{
    Log::info("worker %s with pid %s start to process",
        Color::color(this->name, colors::CYAN).c_str(),
        Color::color(std::to_string(this->pid), colors::CYAN).c_str());
    
    std::vector<UtilityWorker*> utilityWorkers;
    std::string buildingFilePath = this->buildingsDataFilePath + this->name;
    std::vector<UnnamedPipe*> utilityWorkersUnamedPipes;
    for(auto utility : this->utilities) {
        pid_t pid = fork();
        if (pid < 0) {
            Log::error("failed to create utility %s process for building %s",
                Color::color(utility, colors::Red).c_str(),
                Color::color(this->name, colors::Red).c_str()
            );
            throw new std::runtime_error("failed to create process");
        } else if (pid > 0) {
            UnnamedPipe* pipe = new UnnamedPipe();
            utilityWorkersUnamedPipes.push_back(pipe);
            UtilityWorker* worker = new UtilityWorker(pid, utility,
                buildingFilePath + '/' + utility + CSV_EXTENSION, pipe);
            utilityWorkers.push_back(worker);    
            Log::info("create utility %s process with pid %s for building %s",
                Color::color(utility, colors::CYAN).c_str(),
                Color::color(std::to_string((int)pid), colors::CYAN).c_str(),
                Color::color(this->name, colors::CYAN).c_str());
            if (worker->execute() < 0) throw new std::runtime_error("utilit process failed");
            return EXIT_SUCCESS;
        }
    }

    for (auto utility : this->utilities) {
        Log::warn("wait");
        wait(NULL);
    }
    
    return EXIT_SUCCESS;
}
