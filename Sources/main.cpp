#include "../Tests/test_all.hpp"
#include <iostream>
#include "../Headers/repository.hpp"


int main(int argc, char** argv)
{
    testAll();

    std::cout << "All tests passed\n";

    return 0;
}