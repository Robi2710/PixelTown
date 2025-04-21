#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <string>
#include <iostream>

class Buildings {
private:
    std::string type;
    int capacity;
    int costMoney;
    int costMaterials;

    int maintenance() const;
public:
    Buildings(const std::string& type, int capacity, int costMoney, int costMaterials);
    Buildings(const Buildings& other);
    Buildings& operator=(const Buildings& other);
    ~Buildings();

    const std::string& getType() const;
    int getCapacity() const;
    int getcostMoney() const;
    int getcostMaterials() const;
    void showMaintenance() const;

    friend std::ostream& operator<<(std::ostream& os, const Buildings& building);
};

#endif
