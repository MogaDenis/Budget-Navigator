#include "test_all.hpp"
#include "../Headers/graph.hpp"
#include "../Headers/city.hpp"
#include <assert.h>
#include <iostream>


void testAll()
{
    testGraph();
    testCity();
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