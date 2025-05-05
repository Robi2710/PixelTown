#include "City.h"
#include "Exceptions.h""
#include "Factory.h"
#include "House.h"
#include "Road.h"
int City::totalMaintenance() const {
    int total = 0;
    for (const auto* const building : buildings) {
        total += (building->getCapacity() * 5) + (building->getcostMoney() / 10);
    }
    return total;
}

void City::checkCityStatus() const {
    if (population == 0) {
        std::cout << "Warning: Your city is empty! Build more houses to attract people." << std::endl;
    }
    if (resources.getMoney() < 500) {
        std::cout << "Warning: Low funds! Manage your resources wisely." << std::endl;
    }
}

City::City(const std::string& name, int population, const Resources& resources) {
    this->name = name;
    this->population = population;
    this->resources = resources;
}

City::~City() {
    for (Buildings* building : buildings) {
        delete building;
    }
}

Resources& City::getResources() {
    return resources;
}

const std::vector<Buildings*>& City::getBuildings() const {
    return buildings;
}

bool City::addBuilding(Buildings* building) {
    if (!resources.consumeResources(building->getcostMoney(),building->getcostMaterials())) {
        std::cout<<"You don't have enough resources"<<std::endl;
        delete building;
        return false;
    }

    buildings.push_back(building);


    if (building->getType() == "house") {
        population += building->getCapacity();
        std::cout<<"Population increased by "<<building->getCapacity()<<" people"<<std::endl;
    }

    if (building->getType() == "factory") {
        std::cout<<"A factory was built"<<std::endl;
    }

    if (building->getType() == "road") {
        std::cout<<"A road was built"<<std::endl;
    }
    checkCityStatus();
    return true;
}

void City::displayCityInfo() const {
    std::cout << "=== Town " << name << " ===" << std::endl;
    std::cout << "Population: " << population << std::endl;
    std::cout << "Resources: " << resources << std::endl;
    std::cout << "Number of buildings: " << buildings.size() << std::endl;
    std::cout << "Total monthly maintenance: " << totalMaintenance() << "$" << std::endl;
}

void City::updateFactoriesHouse() {
    for (Buildings* building : buildings) {
        if (Factory* factory = dynamic_cast<Factory*>(building)) {
            factory->generateMaterials(resources);
        }
        if (House* house = dynamic_cast<House*>(building)) {
            house->payMaintenance(resources);
        }

    }
}

std::ostream& operator<<(std::ostream& os, const City& city) {
    os << "City: " << city.name << ", Population: " << city.population
           << ", Resources: " << city.resources << ", Buildings: " << city.buildings.size();
    return os;
}