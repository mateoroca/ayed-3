#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::vector<std::string> historialDeLlamadas;
  int posicionActual = -1; // Inicialmente no hay registros en el historial
  int opcion = 0;

  while (true)
  {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Seleccione una opcion:" << std::endl;
    std::cout << "1. Agregar numero telefonico al historial" << std::endl;
    std::cout << "2. Ver historial de llamadas" << std::endl;
    std::cout << "3. Ver registro anterior" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "Opcion: ";
    std::cout << "-----------------------------------" << std::endl;
    std::cin >> opcion;

    if (opcion == 1)
    {
      std::string numeroTelefono;
      std::cout << "Ingrese el numero telefonico: ";
      std::cin >> numeroTelefono;
      historialDeLlamadas.push_back(numeroTelefono);
      posicionActual = historialDeLlamadas.size() - 1; // Actualizar la posicion actual al registro mas reciente
      std::cout << "Numero telefonico agregado al historial." << std::endl;
    }
    else if (opcion == 2)
    {
      std::cout << "Historial de llamadas:" << std::endl;
      for (int i = 0; i < historialDeLlamadas.size(); i++)
      {
        std::cout << i + 1 << ". " << historialDeLlamadas[i] << std::endl;
        std::cout << "-----------------------------------" << std::endl;
      }
    }
    else if (opcion == 3)
    {
      if (posicionActual >= 0)
      {
        std::cout << "Registro anterior: " << historialDeLlamadas[posicionActual] << std::endl;
        posicionActual--;
      }
      else
      {
        std::cout << "No hay registros anteriores en el historial." << std::endl;
        std::cout << "-----------------------------------" << std::endl;
      }
    }
    else if (opcion == 4)
    {
      break;
    }
    else
    {
      std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
      std::cout << "-----------------------------------" << std::endl;
    }
  }

  return 0;
}
