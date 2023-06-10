#include "../Headers/repository.hpp"


Repository::Repository()
{
    this->locations = std::vector<std::shared_ptr<Location>>();
    this->graph = Graph<std::shared_ptr<Location>>();
}

std::vector<std::shared_ptr<Location>> Repository::getAllLocations() const
{
    return this->locations;
}

bool Repository::addLocation(std::shared_ptr<Location>& location)
{
    bool addStatus = this->graph.addVertex(location);

    if (addStatus)
    {
        this->locations.push_back(location);
        return true;
    }

    return false;
}

int Repository::size() const
{
    return (int)this->locations.size();
}

bool Repository::isEmpty() const
{   
    return this->size() == 0;
}

bool Repository::deleteLocation(std::shared_ptr<Location>& location)
{
    bool deleteStatus = this->graph.deleteVertex(location);

    if (deleteStatus)
    {
        this->locations.erase(std::find(this->locations.begin(), this->locations.end(), location));
        return true;
    }

    return false;
}

bool Repository::isLocation(std::shared_ptr<Location>& location) const
{
    return this->graph.isVertex(location);
}

int Repository::searchLocation(std::shared_ptr<Location>& location) const
{
    auto positionFound = std::find(this->locations.begin(), this->locations.end(), location);

    if (positionFound == this->locations.end())
        return -1;

    return (int)std::distance(this->locations.begin(), positionFound);
}

std::shared_ptr<Location>& Repository::getLocation(int index)
{
    if (index < 0 || index >= (int)this->locations.size())
        throw std::exception();

    return this->locations.at(index);
}

bool Repository::linkLocations(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation, int distance)
{
    return this->graph.addEdge(firstLocation, secondLocation, distance);
}

bool Repository::unlinkLocations(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation)
{
    return this->graph.deleteEdge(firstLocation, secondLocation);
}

bool Repository::areLocationsNeighbours(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation) const
{
    return this->graph.isEdge(firstLocation, secondLocation);
}

int Repository::getDistance(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation)
{
    return this->graph.getCost(firstLocation, secondLocation);
}