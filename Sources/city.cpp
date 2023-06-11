#include "../Headers/city.hpp"
#include <algorithm>


City::City(std::string& name, std::vector<std::string>& sights) : Location(name)
{
    this->sights = sights;
}

City::City(std::string& name) : Location(name)
{

}

bool City::operator == (const City& city) const
{
    if (this->name != city.name)
        return false;

    return true;
}

bool City::operator != (const City& city) const 
{
    return !this->operator==(city);
}

City& City::operator = (const City& city)
{
    if (*this == city)
        return *this;

    this->name = city.name;
    this->sights = city.sights;

    return *this;
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