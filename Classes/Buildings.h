#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <string>
#include "Resources.h"

class Buildings {
private:
    std::string type;
    int capacity;
    int costMoney;
    int costMaterials;

    //int maintenance() const;
public:
    Buildings(const std::string& type, int capacity, int costMoney, int costMaterials);
    Buildings(const Buildings& other);
    Buildings& operator=(const Buildings& other);
    virtual ~Buildings();

    //virtual int calculateMaintenance() const = 0;
    virtual void updateBuilding(Resources& resources) = 0;
    [[nodiscard]] virtual Buildings* clone() const = 0;
    [[nodiscard]] virtual const std::string& getType() const;
    [[nodiscard]] virtual int getCapacity() const;
    [[nodiscard]] int getcostMoney() const;
    [[nodiscard]] int getcostMaterials() const;
    void showMaintenance() const;

    friend std::ostream& operator<<(std::ostream& os, const Buildings& building);
};

#endif
