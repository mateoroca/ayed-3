#include "./Isofa.hpp"
#pragma once
class ModernSofa : public Sofa
{
public:
  std::string getDescription() override
  {
    return "Un sofa moderno";
  }
};
