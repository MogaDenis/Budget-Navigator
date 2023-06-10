#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <exception>


template <typename TElem>
class Graph
{
private:
    std::map<TElem, std::vector<TElem>> neighbours;
    std::map<std::pair<TElem, TElem>, int> costs;
    std::vector<TElem> vertices;

public:
    Graph()
    {
        this->vertices = std::vector<TElem>();
        this->neighbours = std::map<TElem, std::vector<TElem>>();
        this->costs = std::map<std::pair<TElem, TElem>, int>();
    }   

    ~Graph() = default;

    std::vector<TElem> parseAllVertices() const
    {
        return this->vertices;
    }

    std::vector<TElem> parseNeighbours(const TElem& vertex)
    {
        if (!this->isVertex(vertex))
            throw std::exception();

        return this->neighbours[vertex];
    }

    int size() const
    {
        return (int)this->vertices.size();
    }

    bool isEmpty() const
    {
        return (int)this->vertices.size() == 0;
    }

    bool addVertex(const TElem& vertex)
    {
        if (this->isVertex(vertex))
            return false;

        this->vertices.push_back(vertex);

        this->neighbours[vertex] = std::vector<TElem>();

        return true;
    }

    bool deleteVertex(const TElem& vertex)
    {
        auto positionIterator = std::find(this->vertices.begin(), this->vertices.end(), vertex);

        if (positionIterator == this->vertices.end())
            return false;

        this->vertices.erase(positionIterator);

        for (const TElem& neighbour : this->neighbours[vertex])
        {
            positionIterator = std::find(this->neighbours[neighbour].begin(), this->neighbours[neighbour].end(), vertex);

            this->neighbours[neighbour].erase(positionIterator);
        }

        this->neighbours.erase(vertex);

        return true;
    }

    bool isVertex(const TElem& vertex) const
    {
        if (std::find(this->vertices.begin(), this->vertices.end(), vertex) == this->vertices.end())
            return false;

        return true;
    }

    bool isEdge(const TElem& source, const TElem& target) const
    {
        if (!this->isVertex(source) || !this->isVertex(target))
            return false;

        return this->costs.count(std::pair<TElem, TElem>(source, target)) != 0;
    }

    int getCost(const TElem& source, const TElem& target) const
    {
        if (!this->isVertex(source) || !this->isVertex(target))
            throw std::exception();

        return this->costs[std::pair<TElem, TElem>(source, target)];
    }

    bool addEdge(const TElem& source, const TElem& target, int cost)
    {
        if (this->isEdge(source, target))
            return false;

        this->neighbours[source].push_back(target);
        this->neighbours[target].push_back(source);

        this->costs[std::pair<TElem, TElem>(source, target)] = cost;

        return true;
    }

    bool deleteEdge(const TElem& source, const TElem& target)
    {
        if (!this->isEdge(source, target))
            return false;

        this->costs.erase(std::pair<TElem, TElem>(source, target));

        auto positionIterator = std::find(this->neighbours[source].begin(), this->neighbours[source].end(), target);
        this->neighbours[source].erase(positionIterator);
        positionIterator = std::find(this->neighbours[target].begin(), this->neighbours[target].end(), source);
        this->neighbours[target].erase(positionIterator);

        return true;
    }
};