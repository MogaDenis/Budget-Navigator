#pragma once
#include "location.hpp"
#include <vector>


class City : public Location
{
private:
    std::vector<std::string> sights;

public:
    City(std::string& name, std::vector<std::string>& sights);
    ~City() override {};

    bool operator == (const City& city) const;

    bool operator != (const City& city) const;

    City& operator = (const City& city);

    std::vector<std::string> getSights() const;

    std::string toString() const override;
};