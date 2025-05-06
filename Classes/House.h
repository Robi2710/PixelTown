#ifndef HOUSE_H
#define HOUSE_H
#include "Buildings.h"
#include "Resources.h"
#include <chrono>
class House : public Buildings {
private:
    int maintenanceCost;
    std::chrono::steady_clock::time_point lastMaintenaceTime;
    float satisfaction;
public:
    House(const std::string& type, int capacity, int costMoney, int costMaterials,
          int maintenanceCost);
    //void payMaintenance(Resources& resources);
    void updateBuilding(Resources& resources) override;
    Buildings* clone() const override;
    float getSatisfaction() const {return satisfaction;};
    void setSatisfaction(float newSatisfaction) { satisfaction = std::min(1.0f, newSatisfaction); }

};



#endif //HOUSE_H
