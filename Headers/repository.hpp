#pragma once
#include "graph.hpp"
#include <memory>


template <typename TElem>
class Repository
{
private:
    Graph<TElem> graph;

    using EqualityFunction = bool(*)(const TElem&, const TElem&);

public:
    Repository()
    {
        this->graph = Graph<TElem>();
    }

    Repository(EqualityFunction eqFunc)
    {
        this->graph = Graph<TElem>(eqFunc);
    }

    ~Repository() = default;

    std::vector<TElem> getAllelements() const
    {
        return this->graph.parseAllVertices();
    }

    int size() const
    {
        return this->graph.size();
    }

    bool isEmpty() const
    {
        return this->graph.isEmpty();
    }

    bool addElement(TElem& element)
    {
        return this->graph.addVertex(element);
    }

    bool deleteElement(TElem& element)
    {
        return this->graph.deleteVertex(element);
    }

    bool isElement(TElem& element) const
    {
        return this->graph.isVertex(element);
    }
    
    int searchElement(TElem& element) const
    {
        return this->graph.searchVertex(element);
    }
    
    TElem& getElement(int index)
    {
        return this->graph.getVertex(index);
    }
    
    bool linkElements(TElem& firstElement, TElem& secondElement, int cost)
    {
        return this->graph.addEdge(firstElement, secondElement, cost);
    }
    
    bool unlinkElements(TElem& firstElement, TElem& secondElement)
    {
        return this->graph.deleteEdge(firstElement, secondElement);
    }
    
    bool areElementsNeighbours(TElem& firstElement, TElem& secondElement) const
    {
        return this->graph.isEdge(firstElement, secondElement);
    }
    
    int getCost(TElem& firstElement, TElem& secondElement)
    {
        return this->graph.getCost(firstElement, secondElement);
    }  
};