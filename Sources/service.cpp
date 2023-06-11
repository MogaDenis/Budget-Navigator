#include "../Headers/service.hpp"



bool equalLocations(const std::shared_ptr<Location>& first, const std::shared_ptr<Location>& second)
{
    return *first == *second;
}


Service::Service()
{
    this->locationsRepository = Repository<std::shared_ptr<Location>>(equalLocations);
}

std::vector<std::shared_ptr<Location>> Service::getAllLocations() const
{
    return this->locationsRepository.getAllelements();
}

int Service::numberOfLocations() const
{
    return this->locationsRepository.size();
}

bool Service::noLocations() const
{
    return this->locationsRepository.isEmpty();
}

bool Service::addLocation(std::shared_ptr<Location>& location)
{
    return this->locationsRepository.addElement(location);
}

bool Service::deleteLocation(std::shared_ptr<Location>& location)
{
    return this->locationsRepository.deleteElement(location);
}

int Service::searchLocation(std::shared_ptr<Location>& location) const
{
    return this->locationsRepository.searchElement(location);
}

std::shared_ptr<Location>& Service::getLocation(int index)
{
    return this->locationsRepository.getElement(index);
}

bool Service::isLocation(std::shared_ptr<Location>& location) const
{
    return this->locationsRepository.isElement(location);
}

bool Service::linkLocations(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation, int distance)
{
    return this->locationsRepository.linkElements(firstLocation, secondLocation, distance);
}

bool Service::unlinkLocations(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation)
{
    return this->locationsRepository.unlinkElements(firstLocation, secondLocation);
}

bool Service::areLocationsNeighbours(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation) const
{
    return this->locationsRepository.areElementsNeighbours(firstLocation, secondLocation);
}

int Service::getDistance(std::shared_ptr<Location>& firstLocation, std::shared_ptr<Location>& secondLocation)
{
    return this->locationsRepository.getCost(firstLocation, secondLocation);
}
