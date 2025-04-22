#include "Factory.h"

Factory::Factory(const std::string& type, int capacity, int costMoney, int costMaterials,
              const std::string& product, int productionRate)
    : Buildings(type, capacity, costMoney, costMaterials), product(product), productionRate(productionRate) {}

const std::string& Factory::getProduct() const {
    return product;
}

int Factory::getProductionRate() const {
    return productionRate;
}

void Factory::showProductionInfo() const {
    std::cout << "Factory Type: " << getType() << ", Producing: " << product
              << ", Production Rate: " << productionRate << " units/month" << std::endl;
}