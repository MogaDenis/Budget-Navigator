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

bool equalInts(const int& first, const int& second)
{
    return first == second;
}

void testGraphConstructor()
{
    Graph<int> testGraph{equalInts};

    assert(testGraph.isEmpty());
    assert(testGraph.size() == 0);
}

void testGraphAdd()
{
    Graph<int> testGraph{equalInts};

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
    Graph<int> testGraph{equalInts};

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
    Graph<int> testGraph{equalInts};

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
    Graph<int> testGraph{equalInts};

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
    std::vector<int> path1{vertex1, vertex3, vertex2};
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
    Repository<int> testRepository{equalInts};

    assert(testRepository.size() == 0);
    assert(testRepository.isEmpty());
    assert(testRepository.getAllelements().size() == 0);
}

void testRepositoryAdd()
{
    Repository<int> testRepository{equalInts};

    int elem1 = 1, elem2 = 2;

    assert(testRepository.addElement(elem1));
    assert(!testRepository.addElement(elem1));

    assert(testRepository.addElement(elem2));

    assert(testRepository.size() == 2);
}

void testRepositoryDelete()
{
    Repository<int> testRepository{equalInts};

    int elem1 = 1, elem2 = 2;

    testRepository.addElement(elem1);
    testRepository.addElement(elem2);

    assert(testRepository.deleteElement(elem1));
    assert(!testRepository.deleteElement(elem1));
    assert(testRepository.deleteElement(elem2));

    assert(testRepository.size() == 0);
}

void testRepositoryGetAll()
{
    Repository<int> testRepository{equalInts};

    int elem1 = 1, elem2 = 2;

    testRepository.addElement(elem1);
    testRepository.addElement(elem2);

    assert(testRepository.getAllelements().size() == 2);
    assert(testRepository.getAllelements().at(0) == elem1);
    assert(testRepository.getAllelements().at(1) == elem2);
}

void testRepositorySearchAndGet()
{
    Repository<int> testRepository{equalInts};

    int elem1 = 1, elem2 = 2, elem3 = 3;

    testRepository.addElement(elem1);
    testRepository.addElement(elem2);

    assert(testRepository.isElement(elem1));
    assert(testRepository.isElement(elem2));
    assert(!testRepository.isElement(elem3));

    int index1 = testRepository.searchElement(elem1);
    int index2 = testRepository.searchElement(elem2);
    int index3 = testRepository.searchElement(elem3);

    assert(index1 == 0);
    assert(index2 == 1);
    assert(index3 == -1);

    auto elem1Copy = testRepository.getElement(index1);
    auto elem2Copy = testRepository.getElement(index2);

    assert(elem1 == elem1Copy);
    assert(elem2 == elem2Copy);

    try
    {
        testRepository.getElement(index3);
    }
    catch (const std::exception &)
    {
        // Do nothing.
    }
}

void testRepositoryLinkAndUnlink()
{
    Repository<int> testRepository{equalInts};

    int elem1 = 1, elem2 = 2;

    testRepository.addElement(elem1);
    testRepository.addElement(elem2);

    assert(testRepository.areElementsNeighbours(elem1, elem2) == false);
    testRepository.linkElements(elem1, elem2, 1);
    assert(testRepository.areElementsNeighbours(elem1, elem2));
    assert(testRepository.getCost(elem1, elem2) == 1);
    testRepository.unlinkElements(elem1, elem2);
    assert(testRepository.areElementsNeighbours(elem1, elem2) == false);

    try
    {
        testRepository.getCost(elem1, elem2);
    }
    catch (const std::exception &)
    {
        // Do nothing.
    }
}
