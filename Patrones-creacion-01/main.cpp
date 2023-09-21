#include <iostream>
#include "./hpp/Ichair.hpp"
#include "./hpp/Isofa.hpp"
#include "./hpp/IcofeeTable.hpp"
#include "./hpp/IFurnitureFactory.hpp"
#include "./hpp/ModernChair.hpp"
#include "./hpp/ModernSofa.hpp"
#include "./hpp/ModernCoffeeTable.hpp"
#include "./hpp/VictorianChair.hpp"
#include "./hpp/VictorianSofa.hpp"
#include "./hpp/VictorianCoffeeTable.hpp"
#include "./hpp/ModernFurnitureFactory.hpp"
#include "./hpp/VictorianFurnitureFactory.hpp"

int main()
{
  // Usar la fábrica de muebles modernos
  FurnitureFactory *modernFactory = new ModernFurnitureFactory();
  Chair *chair = modernFactory->createChair();
  Sofa *sofa = modernFactory->createSofa();
  CoffeeTable *coffeeTable = modernFactory->createCoffeeTable();

  std::cout << chair->getDescription() << std::endl;
  std::cout << sofa->getDescription() << std::endl;
  std::cout << coffeeTable->getDescription() << std::endl;

  delete chair;
  delete sofa;
  delete coffeeTable;
  delete modernFactory;

  // Usar la fábrica de muebles victorianos
  FurnitureFactory *victorianFactory = new VictorianFurnitureFactory();
  chair = victorianFactory->createChair();
  sofa = victorianFactory->createSofa();
  coffeeTable = victorianFactory->createCoffeeTable();

  std::cout << chair->getDescription() << std::endl;
  std::cout << sofa->getDescription() << std::endl;
  std::cout << coffeeTable->getDescription() << std::endl;

  delete chair;
  delete sofa;
  delete coffeeTable;
  delete victorianFactory;

  return 0;
}
