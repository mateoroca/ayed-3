#include <iostream>
#include <string>

const int maxTamanoCola = 100;

struct Cola
{
  int elementos[maxTamanoCola];
  int frente; // Índice del frente de la cola
  int final;  // Índice del final de la cola
  int cantidad;
};

void inicializarCola(Cola &cola)
{
  cola.frente = 0;
  cola.final = -1;
  cola.cantidad = 0;
}

bool isEmpty(const Cola &cola)
{
  return cola.cantidad == 0;
}

void enqueue(Cola &cola, int elemento)
{
  if (cola.cantidad < maxTamanoCola)
  {
    cola.final = (cola.final + 1) % maxTamanoCola;
    cola.elementos[cola.final] = elemento;
    cola.cantidad++;
  }
  else
  {
    std::cout << "La cola está llena. No se pueden encolar más elementos." << std::endl;
  }
}

int dequeue(Cola &cola)
{
  if (!isEmpty(cola))
  {
    int elemento = cola.elementos[cola.frente];
    cola.frente = (cola.frente + 1) % maxTamanoCola;
    cola.cantidad--;
    return elemento;
  }
  else
  {
    std::cout << "La cola está vacía. No se pueden desencolar elementos." << std::endl;
    return -1;
  }
}

int front(const Cola &cola)
{
  if (!isEmpty(cola))
  {
    return cola.elementos[cola.frente];
  }
  else
  {
    std::cout << "La cola está vacía." << std::endl;
    return -1;
  }
}

struct Cliente
{
  std::string nombre;
  int numeroTurno;
};

int main()
{
  const int maxClientes = 100;
  Cliente cola[maxClientes];       // Arreglo para almacenar a los clientes
  int numeroClientes = 0;          // Número de clientes registrados
  Cola colaDeClientes;             // Cola para gestionar a los clientes
  inicializarCola(colaDeClientes); // Inicializar la cola de clientes
  int numeroProximoCliente = 0;    // Número del próximo cliente a atender

  while (true)
  {
    int opcion;
    std::cout << "-----------------------------------";
    std::cout << "Seleccione una opcion:" << std::endl;
    std::cout << "1. Registrar cliente" << std::endl;
    std::cout << "2. Llamar proximo cliente" << std::endl;
    std::cout << "3. Salir" << std::endl;
    std::cout << "Opcion: ";
    std::cout << "-----------------------------------";
    std::cin >> opcion;

    if (opcion == 1)
    {
      if (numeroClientes < maxClientes)
      {
        Cliente nuevoCliente;
        std::cout << "Ingrese el nombre del cliente: ";
        std::cin >> nuevoCliente.nombre;
        nuevoCliente.numeroTurno = numeroClientes + 1;
        cola[numeroClientes] = nuevoCliente;
        numeroClientes++;
        enqueue(colaDeClientes, nuevoCliente.numeroTurno);
        std::cout << "Cliente registrado. Su turno es: " << nuevoCliente.numeroTurno << std::endl;
      }
      else
      {
        std::cout << "La cola de clientes esta llena. Espere a que se atienda a algunos clientes." << std::endl;
      }
    }
    else if (opcion == 2)
    {
      if (!isEmpty(colaDeClientes))
      {
        int numeroTurno = dequeue(colaDeClientes); // Desencolar el próximo número de turno
        std::cout << "Proximo cliente - Box nro: " << numeroProximoCliente + 1 << std::endl;
        std::cout << "Nombre: " << cola[numeroTurno - 1].nombre << std::endl; // Restar 1 para obtener el índice correcto
        numeroProximoCliente++;
      }
      else
      {
        std::cout << "No hay mas clientes en espera." << std::endl;
      }
    }
    else if (opcion == 3)
    {
      break;
    }
    else
    {
      std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
  }

  return 0;
}
