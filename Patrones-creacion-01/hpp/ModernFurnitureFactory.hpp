#include "./IFurnitureFactory.hpp"
#include "./ModernChair.hpp"
#include "./ModernSofa.hpp"
#include "./ModernCoffeeTable.hpp"
#pragma once
class ModernFurnitureFactory : public FurnitureFactory
{
public:
  Chair *createChair() override
  {
    return new ModernChair();
  }

  Sofa *createSofa() override
  {
    return new ModernSofa();
  }

  CoffeeTable *createCoffeeTable() override
  {
    return new ModernCoffeeTable();
  }
};
