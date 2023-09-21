#include <iostream>
#pragma once
class Sofa
{
public:
  virtual std::string getDescription() = 0;
  virtual ~Sofa() {}
};