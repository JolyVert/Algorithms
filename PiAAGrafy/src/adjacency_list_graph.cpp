#include <fstream>

#include "graphs/adjacency_list_graph.hpp"
#include "graphs/graph.hpp"

std::vector<std::list<std::pair<int, double>>> AdjacencyListGraph::getAdjList()
{
    return adjList; // Return as const reference if possible to avoid copying
}

std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{
    int numVertices, numEdges, startVertex;
    is >> numVertices >> numEdges;

    auto graph = std::make_unique<AdjacencyListGraph>(numVertices);

    int u, v;
    double weight;
    for(int i = 0; i < numEdges; i++)
    {
        is >> u >> v >> weight;
        graph->addEdge(u, v, weight);
    }

    is >> startVertex;
    graph->setStartVertex(startVertex);

    return graph;
}

void AdjacencyListGraph::addEdge(int u, int v, double weight)
{
    adjList[u].push_back({v, weight}); // Dla grafu skierowanego
}

void AdjacencyListGraph::printGraph() const
{
    int numEdges = 0;
    for(const auto& list : adjList)
    {
        numEdges += list.size();
    }

    // Wyswietlanie informacji
    std::cout << numVertices << " " << numEdges << std::endl;
    for(int i = 0; i < numVertices; ++i)
    {
        for(const auto& edge : adjList[i])
        {
            std::cout << i << " " << edge.first << " " << edge.second << std::endl;
        }
    }
    std::cout << startVertex << std::endl;
}

void AdjacencyListGraph::setStartVertex(int v)
{
    startVertex = v;
}

std::list<std::pair<int, double>> AdjacencyListGraph::getNeighbors(int u) const
{
    if(u < 0 || u >= numVertices)
    {
        throw std::out_of_range("Vertex index out of range");
    }
    return adjList[u];
}

void AdjacencyListGraph::addVertex()
{
    adjList.push_back({});
    numVertices++;
}

void AdjacencyListGraph::removeVertex(int v)
{
    if(v < 0 || v >= numVertices)
    {
        throw std::out_of_range("Vertex index out of range");
    }
    adjList.erase(adjList.begin() + v);
    for(auto& list : adjList)
    {
        for(auto it = list.begin(); it != list.end();)
        {
            if(it->first == v)
            {
                it = list.erase(it);
            }
            else
            {
                if(it->first > v)
                {
                    it->first--;
                }
                ++it;
            }
        }
    }
    numVertices--;
}

void AdjacencyListGraph::removeEdge(int u, int v)
{
    if(u < 0 || u >= numVertices)
    {
        throw std::out_of_range("Vertex index out of range");
    }
    adjList[u].remove_if([v](const std::pair<int, double>& edge) { return edge.first == v; });
}