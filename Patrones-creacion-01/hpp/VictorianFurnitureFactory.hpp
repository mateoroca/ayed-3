#include "./IFurnitureFactory.hpp"
#include "./VictorianChair.hpp"
#include "./VictorianSofa.hpp"
#include "./VictorianCoffeeTable.hpp"
#pragma once
class VictorianFurnitureFactory : public FurnitureFactory
{
public:
  Chair *createChair() override
  {
    return new VictorianChair();
  }

  Sofa *createSofa() override
  {
    return new VictorianSofa();
  }

  CoffeeTable *createCoffeeTable() override
  {
    return new VictorianCoffeeTable();
  }
};