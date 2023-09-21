#include <iostream>
#pragma once
class CoffeeTable
{
public:
  virtual std::string getDescription() = 0;
  virtual ~CoffeeTable() {}
};