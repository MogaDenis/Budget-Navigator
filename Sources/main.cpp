#include "../Tests/test_all.hpp"
#include <iostream>
#include "../Headers/repository.hpp"
#include "../Headers/service.hpp"
#include "../Headers/city.hpp"


int main(int argc, char** argv)
{
    testAll();

    std::cout << "All tests passed\n\n";

    std::string cityName{"Simleu Silvaniei"};
    std::shared_ptr<Location> firstCity = std::make_shared<City>(cityName);

    Repository<std::shared_ptr<Location>> repo{equalLocations};

    repo.addElement(firstCity);
    
    std::string cityName2{"Zalau"};
    std::vector<std::string> sights{"house", "park"};
    std::shared_ptr<Location> secondCity = std::make_shared<City>(cityName2, sights);

    repo.addElement(secondCity);

    for (auto elem : repo.getAllelements())
        std::cout << elem->toString() << '\n'; 

    return 0;
}