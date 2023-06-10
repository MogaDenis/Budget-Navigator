#pragma once
#include "city.hpp"
#include "graph.hpp"
#include <memory>


class Repository
{
private:
    std::vector<std::shared_ptr<Location>> locations;
    Graph<std::shared_ptr<Location>> graph;

public:
    Repository();
    ~Repository() = default;

    std::vector<std::shared_ptr<Location>> getAllLocations() const;

    int size() const;
    bool isEmpty() const;

    bool addLocation(std::shared_ptr<Location>& location);
    bool deleteLocation(std::shared_ptr<Location>& location);
    bool isLocation(std::shared_ptr<Location>& location) const;
    int searchLocation(std::shared_ptr<Location>& location) const;
    std::shared_ptr<Location>& getLocation(int index);

    bool linkLocations(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation, int distance);
    bool unlinkLocations(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation); 
    bool areLocationsNeighbours(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation) const;
    int getDistance(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation);
};