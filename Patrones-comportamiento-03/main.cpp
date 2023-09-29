#include <iostream>
#include <string>

class RouteStrategy
{
public:
  virtual void calculateRoute(std::string origin, std::string destination) = 0;
};

class PedestrianRoute : public RouteStrategy
{
public:
  void calculateRoute(std::string origin, std::string destination) override
  {
    std::cout << "Calculando ruta para peaton desde " << origin << " hasta " << destination << std::endl;
  }
};

class CarRoute : public RouteStrategy
{
public:
  void calculateRoute(std::string origin, std::string destination) override
  {
    std::cout << "Calculando ruta para coche desde " << origin << " hasta " << destination << std::endl;
  }
};

class PublicTransportRoute : public RouteStrategy
{
public:
  void calculateRoute(std::string origin, std::string destination) override
  {
    std::cout << "Calculando ruta para transporte publico desde " << origin << " hasta " << destination << std::endl;
  }
};

class NavigationApp
{
public:
  NavigationApp(RouteStrategy *strategy) : routeStrategy(strategy) {}

  void setRouteStrategy(RouteStrategy *strategy)
  {
    routeStrategy = strategy;
  }

  void calculateRoute(std::string origin, std::string destination)
  {
    routeStrategy->calculateRoute(origin, destination);
  }

private:
  RouteStrategy *routeStrategy;
};

int main()
{

  RouteStrategy *pedestrian = new PedestrianRoute;
  RouteStrategy *car = new CarRoute();
  RouteStrategy *publicTransport = new PublicTransportRoute;

  NavigationApp navigationApp(pedestrian);

  // Calcular rutas usando diferentes estrategias
  navigationApp.calculateRoute("Casa", "Trabajo"); // Ruta para peatón
  navigationApp.setRouteStrategy(car);
  navigationApp.calculateRoute("Casa", "Trabajo"); // Ruta para coche
  navigationApp.setRouteStrategy(publicTransport);
  navigationApp.calculateRoute("Casa", "Trabajo"); // Ruta para transporte público

  delete pedestrian;
  delete car;
  delete publicTransport;

  return 0;
}
