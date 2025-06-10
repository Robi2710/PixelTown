#include "City.h"
#include "Exceptions.h"
#include "Factory.h"
#include "House.h"
#include "PoliceDepartment.h"
#include "Road.h"
/*int City::totalMaintenance() const {
    int total = 0;
    for (const auto* const building : buildings) {
        total += (building->getCapacity() * 5) + (building->getcostMoney() /
10);
    }
    return total;
}*/

void City::checkCityStatus() const {
  if (population == 0) {
    std::cout
        << "Warning: Your city is empty! Build more houses to attract people."
        << std::endl;
  }
  if (resources.getMoney() < 500) {
    std::cout << "Warning: Low funds! Manage your resources wisely."
              << std::endl;
  }
}

City::City(const std::string &name, int population,
           const Resources &resources) {
  this->name = name;
  this->population = population;
  this->resources = resources;
}

// City::~City() {
//   for (std::unique_ptr<Buildings> : buildings) {
//     delete building;
//   }
// }

Resources &City::getResources() { return resources; }

/*const std::vector<Buildings*>& City::getBuildings() const {
    return buildings;
}*/

// C++
bool City::addBuilding(std::unique_ptr<Buildings> building) {
  // Check resources using the data before moving ownership
  if (!resources.consumeResources(building->getcostMoney(), building->getcostMaterials())) {
    std::cout << "You don't have enough resources" << std::endl;
    return false;
  }

  // Save required building details before moving the pointer
  std::string bType = building->getType();
  int bCapacity = building->getCapacity();

  // Transfer ownership to the vector
  buildings.push_back(std::move(building));

  // Use saved details instead of accessing the moved pointer
  if (bType == "House") {
    population += bCapacity;
    std::cout << "Population increased by " << bCapacity << " people" << std::endl;
  }
  else if (bType == "Factory") {
    std::cout << "A factory was built" << std::endl;
  }
  else if (bType == "Road") {
    std::cout << "A road was built" << std::endl;
  }
  else if (bType == "PoliceDepartment") {
    std::cout << "A police department was built" << std::endl;
  }
  checkCityStatus();
  return true;
}

void City::updateFactoriesHouse() {
  for (std::unique_ptr<Buildings>& building : buildings) {
    if (Factory *factory = dynamic_cast<Factory *>(building.get())) {
      factory->updateBuilding(resources);
    }
    if (House *house = dynamic_cast<House *>(building.get())) {
      house->updateBuilding(resources);
    }
    if (PoliceDepartment *police = dynamic_cast<PoliceDepartment *>(building.get())) {
      police->updateBuilding(resources);
    }
  }
}

std::ostream &operator<<(std::ostream &os, const City &city) {
  os << "City: " << city.name << ", Population: " << city.population
     << ", Resources: " << city.resources
     << ", Buildings: " << city.buildings.size();
  return os;
}