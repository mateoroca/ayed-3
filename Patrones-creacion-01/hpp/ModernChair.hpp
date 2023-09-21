#include "./Ichair.hpp"
#pragma once
class ModernChair : public Chair
{
public:
  std::string getDescription() override
  {
    return "Una silla moderna";
  }
};