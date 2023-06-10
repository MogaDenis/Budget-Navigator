#include "test_all.hpp"
#include "../Headers/graph.hpp"
#include <assert.h>
#include <iostream>


void testAll()
{
    testGraph();
}

void testGraph()
{
    std::cout << "Test graph\n";
    testGraphConstructor();
    testGraphAdd();
    testGraphDelete();
    testGraphParse();
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