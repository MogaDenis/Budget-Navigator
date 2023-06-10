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

    std::vector<std::string> getSights() const;

    std::string toString() const override;
};