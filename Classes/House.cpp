#include "House.h"
#include "Resources.h"
House::House(const std::string& type, int capacity, int costMoney, int costMaterials,
              int maintenanceCost)
    : Buildings(type, capacity, costMoney, costMaterials),
    maintenanceCost(maintenanceCost),
    lastMaintenaceTime(std::chrono::steady_clock::now())
{}

void House::payMaintenance(Resources& resources) {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - lastMaintenaceTime;
    if (elapsed.count() >= 120 ) {
        resources.setMaterials(resources.getMoney() - maintenanceCost);
        lastMaintenaceTime = now;
    }
}