#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
class Resources {
private:
  int money;
  int materials;

public:
  explicit Resources(int money = 10000, int materials = 0);

  int getMoney() const;
  int getMaterials() const;

  bool sufficientResources(int nmoney, int nmaterials) const;
  void setMaterials(int newmaterials);
  bool consumeResources(int cmoney, int cmaterials);
  friend std::ostream &operator<<(std::ostream &os, const Resources &resources);
};
#endif // RESOURCES_H
