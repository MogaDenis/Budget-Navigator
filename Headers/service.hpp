#pragma once
#include "location.hpp"
#include "repository.hpp"


bool equalLocations(const std::shared_ptr<Location>& first, const std::shared_ptr<Location>& second)
{
    return *first == *second;
}


class Service
{
private:
    Repository<std::shared_ptr<Location>> locationsRepository;

public:
    Service();
    ~Service() = default;

    std::shared_ptr<Location> getAllLocation() const;
    int numberOfLocations() const;
    bool noLocations() const;

    bool addLocation(std::shared_ptr<Location>& location);
    bool deleteLocation(std::shared_ptr<Location>& location);
    int searchLocation(std::shared_ptr<Location>& location) const;
    std::shared_ptr<Location>& getLocation(int index) const;
    bool isLocation(std::shared_ptr<Location>& location) const;

    bool linkLocations(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation, int distance);
    bool unlinkLocations(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation);
    bool areLocationsNeighbours(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation) const;
    int getDistance(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation) const;
};