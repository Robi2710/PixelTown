#include "House.h"
#include "Resources.h"
House::House(const std::string& type, int capacity, int costMoney, int costMaterials,
              int maintenanceCost)
    : Buildings(type, capacity, costMoney, costMaterials),
    maintenanceCost(maintenanceCost),
    lastMaintenaceTime(std::chrono::steady_clock::now()),
    satisfaction(1.0f)
{}

/*void House::payMaintenance(Resources& resources) {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - lastMaintenaceTime;
    if (elapsed.count() >= 120 ) {
        resources.setMaterials(resources.getMoney() - maintenanceCost);
        lastMaintenaceTime = now;
    }
}*/
void House::updateBuilding(Resources& resources) {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - lastMaintenaceTime;
    if (elapsed.count() >= 120 ) {
        resources.setMaterials(resources.getMoney() - maintenanceCost);
        lastMaintenaceTime = now;
    }
}

Buildings* House::clone() const {
    return new House(*this);
}

