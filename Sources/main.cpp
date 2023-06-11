#include "../Tests/test_all.hpp"
#include <iostream>
#include "../Headers/repository.hpp"
#include "../Headers/service.hpp"
#include "../Headers/city.hpp"


int main(int argc, char** argv)
{
    testAll();

    std::cout << "All tests passed\n\n";

    return 0;
}