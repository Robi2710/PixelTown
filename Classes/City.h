#ifndef CITY_H
#define CITY_H

#include "Buildings.h"
#include "Resources.h"
#include <iostream>
#include <vector>

class City {
private:
  std::string name{};
  int population{0};
  Resources resources{};
  std::vector<std::unique_ptr<Buildings> > buildings{};

  int totalMaintenance() const;

  void checkCityStatus() const;

public:
  explicit City(const std::string &name, int population = 0,
                const Resources &resources = Resources());

  // ~City();

  Resources &getResources();

  const std::vector<Buildings *> &getBuildings() const;

  bool addBuilding(std::unique_ptr<Buildings> building);

  void updateFactoriesHouse();

  friend std::ostream &operator<<(std::ostream &os, const City &city);
};

#endif // CITY_H
