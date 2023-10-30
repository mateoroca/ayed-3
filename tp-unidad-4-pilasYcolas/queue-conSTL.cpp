#include <iostream>
#include <string>
#include <queue>

struct Cliente
{
  std::string nombre;
  int numeroTurno;
};

int main()
{
  std::queue<Cliente> colaDeClientes;
  int numeroClientes = 0;
  int numeroProximoCliente = 1;

  while (true)
  {
    int opcion;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Seleccione una opcion:" << std::endl;
    std::cout << "1. Registrar cliente" << std::endl;
    std::cout << "2. Llamar proximo cliente" << std::endl;
    std::cout << "3. Salir" << std::endl;
    std::cout << "Opcion: ";
    std::cout << "-----------------------------------" << std::endl;
    std::cin >> opcion;

    if (opcion == 1)
    {
      Cliente nuevoCliente;
      std::cout << "-----------------------------------" << std::endl;
      std::cout << "Ingrese el nombre del cliente: ";
      std::cin >> nuevoCliente.nombre;
      nuevoCliente.numeroTurno = numeroClientes + 1;
      colaDeClientes.push(nuevoCliente);
      numeroClientes++;
      std::cout << "Cliente registrado. Su turno es: " << nuevoCliente.numeroTurno << std::endl;
      std::cout << "-----------------------------------" << std::endl;
    }
    else if (opcion == 2)
    {
      if (!colaDeClientes.empty())
      {
        Cliente proximoCliente = colaDeClientes.front();
        colaDeClientes.pop();
        std::cout << "Proximo cliente - Box nro: " << numeroProximoCliente << std::endl;
        std::cout << "Nombre: " << proximoCliente.nombre << std::endl;
        numeroProximoCliente++;
      }
      else
      {
        std::cout << "No hay mas clientes en espera." << std::endl;
        std::cout << "-----------------------------------" << std::endl;
      }
    }
    else if (opcion == 3)
    {
      break;
    }
    else
    {
      std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
      std::cout << "-----------------------------------" << std::endl;
      break;
    }
  }

  return 0;
}
