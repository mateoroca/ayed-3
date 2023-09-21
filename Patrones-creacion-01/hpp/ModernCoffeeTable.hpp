#include "./IcofeeTable.hpp"
#pragma once
class ModernCoffeeTable : public CoffeeTable
{
public:
  std::string getDescription() override
  {
    return "Una mesa de café moderna";
  }
};