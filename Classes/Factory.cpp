#include "Factory.h"

#include "Resources.h"

Factory::Factory(const std::string& type, int capacity, int costMoney, int costMaterials,
                 const std::string& product, int productionRate, int materialGenerationRate, int GenerationInterval)
    : Buildings(type, capacity, costMoney, costMaterials),
      product(product),
      productionRate(productionRate),
      materialGenerationRate(materialGenerationRate),
      generationInterval(GenerationInterval) {
    lastProductionTime = std::chrono::system_clock::now();
}

void Factory::updateBuilding(Resources& resources) {
    auto currentTime = std::chrono::system_clock::now();
    auto timeDiff = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastProductionTime);

    if (timeDiff.count() >= generationInterval) {
        resources.setMaterials(resources.getMaterials() + materialGenerationRate);
        lastProductionTime = currentTime;
        std::cout << "Factory generated " << materialGenerationRate << " materials\n";
    }
}
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

Buildings* Factory::clone() const {
    return new Factory(*this);
}

/*void Factory::generateMaterials(Resources& resources) {
    auto currentTime = std::chrono::system_clock::now();
    auto timeDiff = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastProductionTime);

    if (timeDiff.count() >= generationInterval) {
        resources.setMaterials(resources.getMaterials() + materialGenerationRate);
        lastProductionTime = currentTime;
    }
}*/