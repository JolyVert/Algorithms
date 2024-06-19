#ifndef ADJACENCY_MATRIX_GRAPH_HPP_
#define ADJACENCY_MATRIX_GRAPH_HPP_

#include <iostream>
#include <list>
#include <memory>
#include <vector>

#include "graphs/graph.hpp"

class AdjacencyMatrixGraph : public Graph
{
  private:
    std::vector<std::vector<double>> matrix;

  public:
    // TODO: implement

    std::vector<std::vector<double>> getMatrix();

    AdjacencyMatrixGraph(int vertices) : Graph(vertices), matrix(vertices, std::vector<double>(vertices, 0)) {}

    void addEdge(int u, int v, double weight) override;

    void printGraph() const override;

    void setStartVertex(int v) override;

    static std::unique_ptr<Graph> createGraph(std::istream& is);

    std::list<std::pair<int, double>> getNeighbors(int u) const override;

    void addVertex();
    void removeVertex(int v);
    void removeEdge(int u, int v);
};

#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
