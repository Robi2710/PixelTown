#ifndef HOUSE_H
#define HOUSE_H
#include "Buildings.h"
#include "Resources.h"

class House : public Buildings {
private:
    int maintenanceCost;
    std::chrono::steady_clock::time_point lastMaintenaceTime;
public:
    House(const std::string& type, int capacity, int costMoney, int costMaterials,
          int maintenanceCost);
    //void payMaintenance(Resources& resources);
    void updateBuilding(Resources& resources) override;
    Buildings* clone() const override;
};



#endif //HOUSE_H
