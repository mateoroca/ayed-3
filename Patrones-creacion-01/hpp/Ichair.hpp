#include <iostream>
#pragma once
class Chair
{
public:
  virtual std::string getDescription() = 0;
  virtual ~Chair() {}
};