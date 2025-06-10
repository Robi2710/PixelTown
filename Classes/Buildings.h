#ifndef BUILDINGS_H
#define BUILDINGS_H

#include "Resources.h"
#include <string>

class Buildings {
private:
  std::string type{};
  int capacity{0};
  int costMoney{0};
  int costMaterials{0};

  // int maintenance() const;
public:
  Buildings(const std::string &type, int capacity, int costMoney,
            int costMaterials);
  Buildings(const Buildings &) = default;
  Buildings &operator=(const Buildings &other);
  virtual ~Buildings() = default;

  // virtual int calculateMaintenance() const = 0;
  virtual void updateBuilding(Resources &resources) = 0;
  [[nodiscard]] virtual Buildings *clone() const = 0;
  [[nodiscard]] const std::string &getType() const;
  [[nodiscard]] int getCapacity() const;
  [[nodiscard]] int getcostMoney() const;
  [[nodiscard]] int getcostMaterials() const;
  //void showMaintenance() const;

  friend std::ostream &operator<<(std::ostream &os, const Buildings &building);
};

#endif
