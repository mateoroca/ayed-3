
#include "./IcofeeTable.hpp"
#pragma once
class VictorianCoffeeTable : public CoffeeTable
{
public:
  std::string getDescription() override
  {
    return "Una mesa de cafe victoriana";
  }
};
