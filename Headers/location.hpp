#pragma once
#include <string>


class Location
{
protected:
    std::string name;

public:
    Location(std::string& name)
    {
        this->name = name;
    }

    virtual ~Location() {};

    std::string getName() const
    {
        return this->name;
    }

    virtual std::string toString() const = 0;
};