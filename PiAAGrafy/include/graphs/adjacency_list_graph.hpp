#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include <iostream>
#include <list>
#include <memory>
#include <vector>

#include "graphs/graph.hpp"

class AdjacencyListGraph : public Graph
{
  private:
    std::vector<std::list<std::pair<int, double>>> adjList;

  public:
    // TODO: implement all required methods

    std::vector<std::list<std::pair<int, double>>> getAdjList();

    AdjacencyListGraph(int vertices) : Graph(vertices), adjList(vertices) {}

    void addEdge(int u, int v, double weight) override;

    void printGraph() const override;

    static std::unique_ptr<Graph> createGraph(std::istream& is);

    void setStartVertex(int v) override;

    std::list<std::pair<int, double>> getNeighbors(int u) const override;

    void addVertex();
    void removeVertex(int v);
    void removeEdge(int u, int v);
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
