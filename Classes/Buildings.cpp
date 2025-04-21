#include "Buildings.h"

Buildings::Buildings(const std::string& type, int capacity, int costMoney, int costMaterials)
    : type(type), capacity(capacity), costMoney(costMoney), costMaterials(costMaterials) {}

Buildings::Buildings(const Buildings& other)
    : type(other.type), capacity(other.capacity), costMoney(other.costMoney), costMaterials(other.costMaterials) {}

Buildings& Buildings::operator=(const Buildings& other) {
    if (this != &other) {
        type = other.type;
        capacity = other.capacity;
        costMoney = other.costMoney;
        costMaterials = other.costMaterials;
        std::cout << "Cladirea de tipul " << type << " a fost atribuita";
    }
    return *this;
}

Buildings::~Buildings() {}

/*int Buildings::maintenance() const {
    return (capacity * 5) + (costMoney / 10);
}*/

const std::string& Buildings::getType() const {
    return type;
}

int Buildings::getCapacity() const {
    return capacity;
}

int Buildings::getcostMoney() const {
    return costMoney;
}

int Buildings::getcostMaterials() const {
    return costMaterials;
}

void Buildings::showMaintenance() const {
    int var_maintenance = (capacity * 5) + (costMoney / 10);
    std::cout << "Maintenance for " << type << ": " << var_maintenance << "$ per month" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Buildings& building) {
    os << "Building Type: " << building.type << ", Capacity: " << building.capacity
       << ", Cost: " << building.costMoney << "$ and " << building.costMaterials << " materials";
    return os;
}
