#include "./Isofa.hpp"
#pragma once
class VictorianSofa : public Sofa
{
public:
  std::string getDescription() override
  {
    return "Un sofa victoriano";
  }
};