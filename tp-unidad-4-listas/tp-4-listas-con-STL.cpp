#include <iostream>
#include <string>
#include <list>

struct Patient
{
  std::string name;
  int age;
  std::string diagnosis;
};

class PatientHandler
{
public:
  void addPatient(const Patient &patient)
  {
    patients.push_back(patient);
  }

  void listPatients()
  {
    for (const Patient &patient : patients)
    {
      std::cout << "Nombre: " << patient.name << std::endl;
      std::cout << "Edad: " << patient.age << std::endl;
      std::cout << "Diagnostico: " << patient.diagnosis << std::endl;
      std::cout << "---------------------------" << std::endl;
    }
  }

  void modifyPatient(const std::string &name, const Patient &updatedPatient)
  {
    for (Patient &patient : patients)
    {
      if (patient.name == name)
      {
        patient = updatedPatient;
        return;
      }
    }
    std::cout << "Paciente no encontrado." << std::endl;
  }

  void deletePatient(const std::string &name)
  {
    for (auto it = patients.begin(); it != patients.end(); ++it)
    {
      if (it->name == name)
      {
        patients.erase(it);
        std::cout << "Paciente eliminado." << std::endl;
        return;
      }
    }
    std::cout << "Paciente no encontrado." << std::endl;
  }

private:
  std::list<Patient> patients;
};

int main()
{
  PatientHandler patientHandler;
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
      patientHandler.addPatient(newPatient);
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
      patientHandler.modifyPatient(name, updatedPatient);
      break;
    }
    case 3:
    {
      std::string name;
      std::cout << "Ingrese el nombre del paciente a eliminar: ";
      std::cin.ignore();
      std::getline(std::cin, name);
      patientHandler.deletePatient(name);
      break;
    }
    case 4:
      std::cout << "Lista de Pacientes:" << std::endl;
      patientHandler.listPatients();
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
