#ifndef ROAD_H
#define ROAD_H
#include "Buildings.h"
#include "Resources.h"

class Road : public Buildings {
public:
  Road(const std::string &type, int capacity, int costMoney, int costMaterials);
  void updateBuilding(Resources &resources) override;
  Buildings *clone() const override;
};

#endif // ROAD_H
