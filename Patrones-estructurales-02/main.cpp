#include <iostream>
#include <string>

class Alojamiento
{
public:
  virtual std::string obtenerDescripcion() const = 0;
  virtual double obtenerCosto() const = 0;
};

class Hotel : public Alojamiento
{
public:
  std::string obtenerDescripcion() const override
  {
    return "Habitacion de hotel";
  }

  double obtenerCosto() const override
  {
    return 100.0;
  }
};

class DecoradorAlojamiento : public Alojamiento
{
protected:
  Alojamiento *alojamiento;

public:
  DecoradorAlojamiento(Alojamiento *alojamiento) : alojamiento(alojamiento) {}

  std::string obtenerDescripcion() const override
  {
    return alojamiento->obtenerDescripcion();
  }

  double obtenerCosto() const override
  {
    return alojamiento->obtenerCosto();
  }
};

class DesayunoDecorator : public DecoradorAlojamiento
{
public:
  DesayunoDecorator(Alojamiento *alojamiento) : DecoradorAlojamiento(alojamiento) {}

  std::string obtenerDescripcion() const override
  {
    return DecoradorAlojamiento::obtenerDescripcion() + " con desayuno";
  }

  double obtenerCosto() const override
  {
    return DecoradorAlojamiento::obtenerCosto() + 20.0; // Costo adicional por desayuno
  }
};

int main()
{
  Alojamiento *alojamiento1 = new Hotel();
  Alojamiento *alojamiento2 = new DesayunoDecorator(new Hotel());

  std::cout << "Alojamiento 1: " << alojamiento1->obtenerDescripcion() << ", Costo: $" << alojamiento1->obtenerCosto() << std::endl;
  std::cout << "Alojamiento 2: " << alojamiento2->obtenerDescripcion() << ", Costo: $" << alojamiento2->obtenerCosto() << std::endl;

  delete alojamiento1;
  delete alojamiento2;

  return 0;
}
