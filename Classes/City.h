#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <vector>
#include "Buildings.h"
#include "Resources.h"

class City {
private:
    std::string name;
    int population;
    Resources resources;
    std::vector<Buildings*> buildings;

    int totalMaintenance() const;

    void checkCityStatus() const;

public:
    explicit City(const std::string& name, int population=0, const Resources& resources= Resources());

    ~City();

    Resources& getResources();

    const std::vector<Buildings*>& getBuildings() const;

    bool addBuilding(Buildings* building);

    void updateFactoriesHouse();

    friend std::ostream& operator<<(std::ostream& os, const City& city);
};

#endif //CITY_H
