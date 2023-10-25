#include <iostream>
#include <string>

struct Patient
{
  std::string name;
  int age;
  std::string diagnosis;
};

struct Node
{
  Patient data;
  Node *next;
};

class PatientList
{
public:
  PatientList()
  {
    head = nullptr;
  }

  void addPatient(const Patient &patient)
  {
    Node *newNode = new Node;
    newNode->data = patient;
    newNode->next = head;
    head = newNode;
  }

  void listPatients()
  {
    Node *current = head;
    while (current != nullptr)
    {
      std::cout << "Nombre: " << current->data.name << std::endl;
      std::cout << "Edad: " << current->data.age << std::endl;
      std::cout << "Diagnostico: " << current->data.diagnosis << std::endl;
      std::cout << "---------------------------" << std::endl;
      current = current->next;
    }
  }

  void modifyPatient(const std::string &name, const Patient &updatedPatient)
  {
    Node *current = head;
    while (current != nullptr)
    {
      if (current->data.name == name)
      {
        current->data = updatedPatient;
        return;
      }
      current = current->next;
    }
    std::cout << "Paciente no encontrado." << std::endl;
  }

  void deletePatient(const std::string &name)
  {
    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr)
    {
      if (current->data.name == name)
      {
        if (prev == nullptr)
        {
          head = current->next;
        }
        else
        {
          prev->next = current->next;
        }
        delete current;
        return;
      }
      prev = current;
      current = current->next;
    }
    std::cout << "Paciente no encontrado." << std::endl;
  }

  ~PatientList()
  {
    while (head != nullptr)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

private:
  Node *head;
};

int main()
{
  PatientList patientList;
  int choice;

  do
  {
    std::cout << "Menu de Pacientes" << std::endl;
    std::cout << "1. Registrar Paciente" << std::endl;
    std::cout << "2. Modificar Paciente" << std::endl;
    std::cout << "3. Eliminar Paciente" << std::endl;
    std::cout << "4. Listar Pacientes" << std::endl;
    std::cout << "5. Salir" << std::endl;
    std::cout << "Elija una opcion: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
      Patient newPatient;
      std::cin.ignore();
      std::cout << "Nombre: ";
      std::getline(std::cin, newPatient.name);
      std::cout << "Edad: ";
      std::cin >> newPatient.age;
      std::cin.ignore();
      std::cout << "Diagnostico: ";
      std::getline(std::cin, newPatient.diagnosis);
      patientList.addPatient(newPatient);
      std::cout << "Paciente registrado con exito." << std::endl;
      break;
    }
    case 2:
    {
      std::string name;
      std::cout << "Ingrese el nombre del paciente a modificar: ";
      std::cin.ignore();
      std::getline(std::cin, name);
      Patient updatedPatient;
      std::cout << "Nuevo nombre: ";
      std::getline(std::cin, updatedPatient.name);
      std::cout << "Nueva edad: ";
      std::cin >> updatedPatient.age;
      std::cin.ignore();
      std::cout << "Nuevo diagnostico: ";
      std::getline(std::cin, updatedPatient.diagnosis);
      patientList.modifyPatient(name, updatedPatient);
      break;
    }
    case 3:
    {
      std::string name;
      std::cout << "Ingrese el nombre del paciente a eliminar: ";
      std::cin.ignore();
      std::getline(std::cin, name);
      patientList.deletePatient(name);
      break;
    }
    case 4:
      std::cout << "Lista de Pacientes:" << std::endl;
      patientList.listPatients();
      break;
    case 5:
      std::cout << "Saliendo del programa." << std::endl;
      break;
    default:
      std::cout << "Opcion no valida. Por favor, elija una opcion valida." << std::endl;
    }
  } while (choice != 5);

  return 0;
}
