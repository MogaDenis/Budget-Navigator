#include "../Headers/city.hpp"


City::City(std::string& name, std::vector<std::string>& sights) : Location(name)
{
    this->sights = sights;
}

std::vector<std::string> City::getSights() const
{
    return this->sights;
}

std::string City::toString() const
{
    std::string cityString = "City: ";
    cityString = cityString + this->name + " - Sights: ";

    bool first = true;
    for (const std::string& sight : this->sights)
    {
        if (first)
        {
            cityString = cityString + sight;
            first = false;
        }
        else
            cityString = cityString + ", " + sight;
    }

    return cityString;
}