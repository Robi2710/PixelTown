#ifndef FACTORY_H
#define FACTORY_H
#include "Buildings.h"
#include <string>

class Factory : public Buildings {
private:
   std::string product;
   int productionRate;
public:
   Factory(const std::string& type, int capacity, int costMoney, int costMaterials,
             const std::string& product, int productionRate);
   const std::string& getProduct() const;
   int getProductionRate() const;
   void showProductionInfo() const;
};
#endif //FACTORY_H
