#include <iostream>

bool par(int n);

bool impar(int n)
{
  if (n == 1)
  {
    return true;
  }
  else
  {
    return par(n - 1);
  }
}

bool par(int n)
{
  if (n == 1)
  {
    return false;
  }
  else
  {
    return impar(n - 1);
  }
}

int main()
{
  int numero;

  std::cout << "Ingrese un numero natural: ";
  std::cin >> numero;

  if (par(numero))
  {
    std::cout << numero << " es par." << std::endl;
  }
  else
  {
    std::cout << numero << " es impar." << std::endl;
  }

  return 0;
}
