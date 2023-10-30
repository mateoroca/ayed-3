#include <iostream>
#include <vector>
#include <ctime>

struct Cliente
{
  std::string nombre;
  time_t llegada;
  int box;
};

class GestorTurnos
{
private:
  std::vector<Cliente> clientes;

  void calcularTiempoEsperaRecursivo(int indice)
  {
    if (indice == 0)
    {
      clientes[indice].llegada = time(NULL);
    }
    else
    {
      calcularTiempoEsperaRecursivo(indice - 1);
      time_t ahora = time(NULL);
      int tiempoEspera = difftime(ahora, clientes[indice].llegada);
      std::cout << "Cliente " << clientes[indice].nombre << " espero " << tiempoEspera << " segundos." << std::endl;
    }
  }

public:
  void registrarCliente(const std::string &nombre, int box)
  {
    Cliente nuevoCliente;
    nuevoCliente.nombre = nombre;
    nuevoCliente.llegada = time(NULL);
    nuevoCliente.box = box;
    clientes.push_back(nuevoCliente);
    std::cout << "Cliente " << nombre << " registrado en el Box " << box << std::endl;
  }

  void mostrarClientesEnOrden()
  {
    for (int i = 0; i < clientes.size(); i++)
    {
      std::cout << "Cliente " << clientes[i].nombre << " - Box " << clientes[i].box << std::endl;
    }
  }

  void llamarProximoCliente(int box)
  {
    if (clientes.empty())
    {
      std::cout << "No hay clientes en espera." << std::endl;
      return;
    }

    Cliente siguiente = clientes.front();
    clientes.erase(clientes.begin());
    std::cout << "Llamando a " << siguiente.nombre << " - Box " << box << std::endl;

    if (!clientes.empty())
    {
      std::cout << "Proximo cliente en espera: " << clientes.front().nombre << std::endl;
    }

    calcularTiempoEsperaRecursivo(0);
  }
};

int main()
{
  GestorTurnos gestor;
  int opcion;
  std::string nombre;

  do
  {
    std::cout << "\nMenu de opciones:" << std::endl;
    std::cout << "1. Registrar cliente" << std::endl;
    std::cout << "2. Mostrar clientes en orden de llegada" << std::endl;
    std::cout << "3. Llamar al proximo cliente" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "Elija una opcion: ";
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:

      int box;
      std::cout << "Nombre del cliente: ";
      std::cin >> nombre;
      std::cout << "Numero de box: ";
      std::cin >> box;
      gestor.registrarCliente(nombre, box);
      break;
    case 2:
      std::cout << "Clientes registrados en orden de llegada:" << std::endl;
      gestor.mostrarClientesEnOrden();
      break;
    case 3:
      int numBox;
      std::cout << "Ingrese el numero de box: ";
      std::cin >> numBox;
      gestor.llamarProximoCliente(numBox);
      break;
    case 4:
      std::cout << "Saliendo del programa." << std::endl;
      break;
    default:
      std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
  } while (opcion != 4);

  return 0;
}
