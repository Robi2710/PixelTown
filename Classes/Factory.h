#ifndef FACTORY_H
#define FACTORY_H
#include "Buildings.h"
#include <string>
#include "Resources.h"
#include <chrono>
class Factory : public Buildings {
private:
   std::string product;
   int productionRate;
    int materialGenerationRate;
    int generationInterval;
    std::chrono::system_clock::time_point lastProductionTime;
public:
   Factory(const std::string& type, int capacity, int costMoney, int costMaterials,
             const std::string& product, int productionRate, int materialGenerationRate, int generationInterval);
    void updateBuilding(Resources& resources) override;
    [[nodiscard]] Buildings* clone() const override;
   //[[nodiscard]] int getProductionRate() const;
   void showProductionInfo() const;
    //void generateMaterials(Resources& resources);
};
#endif //FACTORY_H
