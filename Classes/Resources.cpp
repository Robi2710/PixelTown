#include "Resources.h"

Resources::Resources(int money, int materials) {
  this->money = money;
  this->materials = materials;
}

int Resources::getMoney() const { return this->money; }

bool Resources::sufficientResources(int nmoney, int nmaterials) const {
  return this->money >= nmoney && this->materials >= nmaterials;
}

void Resources::setMaterials(int newmaterials) {
  this->materials = newmaterials;
}

bool Resources::consumeResources(int cmoney, int cmaterials) {
  if (sufficientResources(cmoney, cmaterials)) {
    this->money -= cmoney;
    this->materials -= cmaterials;
    return true;
  }
  return false;
}

int Resources::getMaterials() const { return this->materials; }

std::ostream &operator<<(std::ostream &os, const Resources &resources) {
  os << resources.money << "$ money, " << resources.materials << " materials";
  return os;
}