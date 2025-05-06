#ifndef POLICEDEPARTMENT_H
#define POLICEDEPARTMENT_H

#include "Buildings.h"
#include "Resources.h"
#include "House.h"
#include <vector>

class PoliceDepartment : public Buildings {
private:
    const int radius = 4;
    const float satisfactionIncrease = 0.1f;
    std::vector<Buildings*>* cityBuildings;
public:
    PoliceDepartment(const std::string& type, int capacity, int costMoney, int costMaterials);
    void updateBuilding([[maybe_unused]] Resources& resources) override;
    Buildings* clone() const override;
    std::vector<House*> findNearbyHouses();

    int getRadius() const;
    float getSatisfactionIncrease() const;
};



#endif //POLICEDEPARTMENT_H
