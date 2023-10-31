#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct Vertex
{
  char city;
  int cost;

  Vertex(char c, int cst) : city(c), cost(cst) {}

  bool operator<(const Vertex &other) const
  {
    return cost > other.cost;
  }
};

void findShortestPath(vector<vector<Vertex>> &graph, char start, char end)
{
  int numCities = graph.size();
  vector<int> distance(numCities, INT_MAX);
  vector<char> previous(numCities, ' ');

  int startIndex = start - 'A';
  distance[startIndex] = 0;

  priority_queue<Vertex> pq;
  pq.push(Vertex(start, 0));

  while (!pq.empty())
  {
    Vertex u = pq.top();
    pq.pop();

    if (u.city == end)
    {
      break;
    }

    int uIndex = u.city - 'A';

    for (const Vertex &v : graph[uIndex])
    {
      int vIndex = v.city - 'A';
      if (distance[uIndex] != INT_MAX && (distance[uIndex] + v.cost < distance[vIndex]))
      {
        distance[vIndex] = distance[uIndex] + v.cost;
        previous[vIndex] = u.city;
        pq.push(Vertex(v.city, distance[vIndex]));
      }
    }
  }

  vector<char> path;
  char currentCity = end;
  while (currentCity != start)
  {
    path.push_back(currentCity);
    int currentIndex = currentCity - 'A';
    currentCity = previous[currentIndex];
  }
  path.push_back(start);

  cout << "Camino de menor costo desde ciudad " << start << " a ciudad " << end << ": ";
  for (int i = path.size() - 1; i >= 0; i--)
  {
    cout << path[i];
    if (i > 0)
    {
      cout << " -> ";
    }
  }
  cout << endl;
  cout << "Costo total: " << distance[end - 'A'] << endl;
}

int main()
{
  int numCities = 8;

  vector<vector<Vertex>> graph(numCities);

  graph['A' - 'A'].push_back(Vertex('B', 3));
  graph['A' - 'A'].push_back(Vertex('C', 5));
  graph['A' - 'A'].push_back(Vertex('D', 2));
  graph['A' - 'A'].push_back(Vertex('H', 10));

  graph['B' - 'A'].push_back(Vertex('A', 3));
  graph['B' - 'A'].push_back(Vertex('C', 5));
  graph['B' - 'A'].push_back(Vertex('D', 8));
  graph['B' - 'A'].push_back(Vertex('G', 6));
  graph['B' - 'A'].push_back(Vertex('E', 4));
  graph['B' - 'A'].push_back(Vertex('H', 6));

  graph['C' - 'A'].push_back(Vertex('A', 5));
  graph['C' - 'A'].push_back(Vertex('B', 5));
  graph['C' - 'A'].push_back(Vertex('E', 1));
  graph['C' - 'A'].push_back(Vertex('F', 7));
  graph['C' - 'A'].push_back(Vertex('G', 9));

  graph['D' - 'A'].push_back(Vertex('H', 14));
  graph['D' - 'A'].push_back(Vertex('A', 2));
  graph['D' - 'A'].push_back(Vertex('B', 8));
  graph['D' - 'A'].push_back(Vertex('E', 12));

  graph['E' - 'A'].push_back(Vertex('G', 15));
  graph['E' - 'A'].push_back(Vertex('D', 12));
  graph['E' - 'A'].push_back(Vertex('B', 4));
  graph['E' - 'A'].push_back(Vertex('C', 1));

  graph['F' - 'A'].push_back(Vertex('C', 7));
  graph['F' - 'A'].push_back(Vertex('H', 9));

  graph['G' - 'A'].push_back(Vertex('H', 3));
  graph['G' - 'A'].push_back(Vertex('B', 6));
  graph['G' - 'A'].push_back(Vertex('E', 15));

  graph['H' - 'A'].push_back(Vertex('A', 10));
  graph['H' - 'A'].push_back(Vertex('F', 9));
  graph['H' - 'A'].push_back(Vertex('B', 6));
  graph['H' - 'A'].push_back(Vertex('G', 3));
  graph['H' - 'A'].push_back(Vertex('D', 14));

  int option;
  char startCity, endCity;

  while (true)
  {
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Encontrar ruta de menor costo" << endl;
    cout << "2. Salir" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
      cout << "Ingrese ciudad de inicio (A-H): ";
      cin >> startCity;
      cout << "Ingrese ciudad de destino (A-H): ";
      cin >> endCity;
      if (startCity >= 'A' && startCity <= 'H' && endCity >= 'A' && endCity <= 'H')
      {
        findShortestPath(graph, startCity, endCity);
      }
      else
      {
        cout << "Ciudades no validas. Deben estar entre A y H." << endl;
      }
      break;
    case 2:
      cout << "Saliendo del programa." << endl;
      return 0;
    default:
      cout << "Opcion no valida. Por favor, seleccione una opción valida." << endl;
      break;
    }
  }

  return 0;
}
