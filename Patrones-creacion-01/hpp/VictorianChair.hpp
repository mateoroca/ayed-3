#include "./Ichair.hpp"
#pragma once
class VictorianChair : public Chair
{
public:
  std::string getDescription() override
  {
    return "Una silla victoriana";
  }
};