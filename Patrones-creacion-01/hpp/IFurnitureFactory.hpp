#include "./Ichair.hpp"
#include "./Isofa.hpp"
#include "./IcofeeTable.hpp"
#pragma once
class FurnitureFactory
{
public:
  virtual Chair *createChair() = 0;
  virtual Sofa *createSofa() = 0;
  virtual CoffeeTable *createCoffeeTable() = 0;
  virtual ~FurnitureFactory() {}
};
