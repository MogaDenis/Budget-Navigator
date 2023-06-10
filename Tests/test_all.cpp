#include "test_all.hpp"
#include "../Headers/graph.hpp"
#include "../Headers/city.hpp"
#include "../Headers/repository.hpp"
#include <assert.h>
#include <iostream>


void testAll()
{
    testGraph();
    testCity();
    testRepository();
}

void testGraph()
{
    std::cout << "Test graph\n";
    testGraphConstructor();
    testGraphAdd();
    testGraphDelete();
    testGraphParse();
    testGraphMinCostPath();
}

void testRepository()
{
    std::cout << "Test repository\n";
    testRepositoryConstructor();
    testRepositoryAdd();
    testRepositoryDelete();
    testRepositoryGetAll();
    testRepositorySearchAndGet();
    testRepositoryLinkAndUnlink();
}

void testGraphConstructor()
{
    Graph<int> testGraph{};

    assert(testGraph.isEmpty());
    assert(testGraph.size() == 0);
}

void testGraphAdd()
{
    Graph<int> testGraph{};

    int source = 1, target = 2, cost = 3;
    testGraph.addVertex(source);
    assert(testGraph.isVertex(source));

    testGraph.addVertex(target);
    assert(testGraph.isVertex(target));

    assert(!testGraph.isEdge(source, target));
    testGraph.addEdge(source, target, cost);
    assert(testGraph.isEdge(source, target));
}

void testGraphDelete()
{
    Graph<int> testGraph{};

    int source = 1, target = 2, cost = 3;
    testGraph.addVertex(source);
    testGraph.addVertex(target);

    testGraph.deleteVertex(source);
    assert(!testGraph.isVertex(source));
    assert(!testGraph.deleteVertex(source));
    testGraph.deleteVertex(target);
    assert(!testGraph.isVertex(target));

    testGraph.addVertex(source);
    testGraph.addVertex(target);
    testGraph.addEdge(source, target, cost);

    testGraph.deleteEdge(source, target);
    assert(!testGraph.isEdge(source, target));
    assert(!testGraph.deleteEdge(source, target));
}

void testGraphParse()
{
    Graph<int> testGraph{};

    int source = 1, target = 2, cost = 3;
    testGraph.addVertex(source);
    testGraph.addVertex(target);

    assert(testGraph.parseAllVertices().size() == 2);
    assert(testGraph.parseNeighbours(source).empty());

    testGraph.addEdge(source, target, cost);

    assert(testGraph.parseNeighbours(source).size() == 1);
    assert(testGraph.parseNeighbours(source).at(0) == target);
    assert(testGraph.parseNeighbours(target).size() == 1);
    assert(testGraph.parseNeighbours(target).at(0) == source);
}

void testGraphMinCostPath()
{
    Graph<int> testGraph{};

    int vertex1 = 1, vertex2 = 2, vertex3 = 3, vertex4 = 4, vertex5 = 5, vertex6 = 6;
    testGraph.addVertex(vertex1);
    testGraph.addVertex(vertex2);
    testGraph.addVertex(vertex3);
    testGraph.addVertex(vertex4);
    testGraph.addVertex(vertex5);
    testGraph.addVertex(vertex6);

    testGraph.addEdge(vertex1, vertex2, 5);
    testGraph.addEdge(vertex1, vertex3, 2);
    testGraph.addEdge(vertex1, vertex4, 4);
    testGraph.addEdge(vertex2, vertex3, 2);
    testGraph.addEdge(vertex2, vertex6, 1);
    testGraph.addEdge(vertex3, vertex4, 4);
    testGraph.addEdge(vertex3, vertex5, 3);
    testGraph.addEdge(vertex3, vertex6, 2);
    testGraph.addEdge(vertex4, vertex5, 5);
    testGraph.addEdge(vertex5, vertex6, 5);

    int totalCost = 0;
    std::vector<int> path1{1, 3, 2};
    assert(testGraph.minimumCostPath(vertex1, vertex2, totalCost) == path1);
    assert(totalCost == 4);

    std::vector<int> path2{1, 3, 6};
    assert(testGraph.minimumCostPath(vertex1, vertex6, totalCost) == path2);
    assert(totalCost == 4);
}

void testCity()
{
    std::cout << "Test city\n";

    std::string testName{"test"};
    std::vector<std::string> testSights{"house", "park"};

    City testCity{testName, testSights};

    assert(testCity.getName() == testName);
    assert(testCity.getSights() == testSights);
    assert(testCity.toString() == std::string("City: test - Sights: house, park"));
}

void testRepositoryConstructor()
{
    Repository testRepository{};

    assert(testRepository.size() == 0);
    assert(testRepository.isEmpty());
    assert(testRepository.getAllLocations().size() == 0);
}

void testRepositoryAdd()
{
    Repository testRepository{};

    std::string name1{"name"};
    std::vector<std::string> sights1{"house", "park"};
    std::shared_ptr<Location> location1 = std::make_shared<City>(name1, sights1);

    assert(testRepository.addLocation(location1));
    assert(!testRepository.addLocation(location1));

    std::string name2{"another name"};
    std::vector<std::string> sights2{"house", "park"};
    std::shared_ptr<Location> location2 = std::make_shared<City>(name2, sights2);

    assert(testRepository.addLocation(location2));

    assert(testRepository.size() == 2);
}

void testRepositoryDelete()
{
    Repository testRepository{};

    std::string name1{"name"};
    std::vector<std::string> sights1{"house", "park"};
    std::shared_ptr<Location> location1 = std::make_shared<City>(name1, sights1);

    std::string name2{"another name"};
    std::vector<std::string> sights2{"house", "park"};
    std::shared_ptr<Location> location2 = std::make_shared<City>(name2, sights2);

    testRepository.addLocation(location1);
    testRepository.addLocation(location2);

    assert(testRepository.deleteLocation(location1));
    assert(!testRepository.deleteLocation(location1));
    assert(testRepository.deleteLocation(location2));

    assert(testRepository.size() == 0);
}

void testRepositoryGetAll()
{
    Repository testRepository{};

    std::string name1{"name"};
    std::vector<std::string> sights1{"house", "park"};
    std::shared_ptr<Location> location1 = std::make_shared<City>(name1, sights1);

    std::string name2{"another name"};
    std::vector<std::string> sights2{"house", "park"};
    std::shared_ptr<Location> location2 = std::make_shared<City>(name2, sights2);

    testRepository.addLocation(location1);
    testRepository.addLocation(location2);

    assert(testRepository.getAllLocations().size() == 2);
    assert(testRepository.getAllLocations().at(0) == location1);
    assert(testRepository.getAllLocations().at(1) == location2);
}

void testRepositorySearchAndGet()
{
    Repository testRepository{};

    std::string name1{"name"};
    std::vector<std::string> sights1{"house", "park"};
    std::shared_ptr<Location> location1 = std::make_shared<City>(name1, sights1);

    std::string name2{"another name"};
    std::vector<std::string> sights2{"house", "park"};
    std::shared_ptr<Location> location2 = std::make_shared<City>(name2, sights2);

    std::string name3{"other name"};
    std::vector<std::string> sights3{"house", "park"};
    std::shared_ptr<Location> location3 = std::make_shared<City>(name3, sights3);

    testRepository.addLocation(location1);
    testRepository.addLocation(location2);

    assert(testRepository.isLocation(location1));
    assert(testRepository.isLocation(location2));
    assert(!testRepository.isLocation(location3));

    int index1 = testRepository.searchLocation(location1);
    int index2 = testRepository.searchLocation(location2);
    int index3 = testRepository.searchLocation(location3);

    assert(index1 == 0);
    assert(index2 == 1);
    assert(index3 == -1);

    auto location1Copy = testRepository.getLocation(index1);
    auto location2Copy = testRepository.getLocation(index2);

    assert(location1 == location1Copy);
    assert(location2 == location2Copy);

    try 
    {
        testRepository.getLocation(index3);
    }
    catch (const std::exception&)
    {
        // Do nothing.
    }
}

void testRepositoryLinkAndUnlink()
{
    Repository testRepository{};

    std::string name1{"name"};
    std::vector<std::string> sights1{"house", "park"};
    std::shared_ptr<Location> location1 = std::make_shared<City>(name1, sights1);

    std::string name2{"another name"};
    std::vector<std::string> sights2{"house", "park"};
    std::shared_ptr<Location> location2 = std::make_shared<City>(name2, sights2);

    testRepository.addLocation(location1);
    testRepository.addLocation(location2);

    assert(testRepository.areLocationsNeighbours(location1, location2) == false);
    testRepository.linkLocations(location1, location2, 1);
    assert(testRepository.areLocationsNeighbours(location1, location2));
    assert(testRepository.getDistance(location1, location2) == 1);
    testRepository.unlinkLocations(location1, location2);
    assert(testRepository.areLocationsNeighbours(location1, location2) == false);

    try 
    {
        testRepository.getDistance(location1, location2);
    }
    catch (const std::exception&)
    {
        // Do nothing.
    }
}
