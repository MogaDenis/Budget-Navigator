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

    bool operator == (const Location& location) const
    {
        return this->name == location.name;
    }

    bool operator != (const Location& location) const 
    {
        return !this->operator==(location);
    }

    Location& operator = (const Location& location)
    {
        if (*this == location)
            return *this;

        this->name = location.name;

        return *this;
    }

    std::string getName() const
    {
        return this->name;
    }

    virtual std::string toString() const = 0;
};