#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <iostream>
#include <list>
#include <vector>

class Graph
{
  protected:
    int numVertices;
    int startVertex;

  public:
    // TODO: implement all required methods
    // virtual int getNumVertices() = 0;
    // virtual int getStartVertex() = 0;
    int getNumVertices() const { return numVertices; }

    int getStartVertex() const { return startVertex; }
    virtual void addEdge(int u, int v, double weight) = 0;
    virtual void printGraph() const = 0;
    virtual void setStartVertex(int v) = 0;
    virtual std::list<std::pair<int, double>> getNeighbors(int u) const = 0;
    virtual void addVertex() = 0;
    virtual void removeVertex(int v) = 0;
    virtual void removeEdge(int u, int v) = 0;

    Graph(int vertices) : numVertices(vertices) {}
    Graph() {}
    virtual ~Graph() {}
};

#endif /* GRAPH_HPP_ */