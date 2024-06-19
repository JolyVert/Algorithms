#include "graphs/adjacency_matrix_graph.hpp"
#include "graphs/graph.hpp"
#include <fstream>

std::vector<std::vector<double>> AdjacencyMatrixGraph::getMatrix()
{
    return matrix;
}

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    // TODO: implement

    int numVertices, numEdges, startVertex;
    is >> numVertices >> numEdges;

    auto graph = std::make_unique<AdjacencyMatrixGraph>(numVertices);

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

void AdjacencyMatrixGraph::addEdge(int u, int v, double weight)
{
    matrix[u][v] = weight; // Dla grafu skierowanego
}

void AdjacencyMatrixGraph::printGraph() const
{
    int numEdges = 0;
    // Liczymy krawedzie
    for(int i = 0; i < numVertices; ++i)
    {
        for(int j = 0; j < numVertices; ++j)
        {
            if(matrix[i][j] != 0)
            {
                numEdges++;
            }
        }
    }
    // Wyswietlanie informacji
    std::cout << numVertices << " " << numEdges << std::endl;
    for(int i = 0; i < numVertices; ++i)
    {
        for(int j = 0; j < numVertices; ++j)
        {
            if(matrix[i][j] != 0)
            {
                std::cout << i << " " << j << " " << matrix[i][j] << std::endl;
            }
        }
    }
    std::cout << startVertex << std::endl;
}

void AdjacencyMatrixGraph::setStartVertex(int v)
{
    startVertex = v;
}

std::list<std::pair<int, double>> AdjacencyMatrixGraph::getNeighbors(int u) const
{
    std::list<std::pair<int, double>> neighbors;
    for(int v = 0; v < numVertices; ++v)
    {
        if(matrix[u][v] != 0)
        {
            neighbors.push_back({v, matrix[u][v]});
        }
    }
    return neighbors;
}

void AdjacencyMatrixGraph::addVertex()
{
    numVertices++;
    for(auto& row : matrix)
    {
        row.push_back(0);
    }
    matrix.push_back(std::vector<double>(numVertices, 0));
}

void AdjacencyMatrixGraph::removeVertex(int v)
{
    if(v < 0 || v >= numVertices)
    {
        throw std::out_of_range("Vertex index out of range");
    }
    matrix.erase(matrix.begin() + v);
    for(auto& row : matrix)
    {
        row.erase(row.begin() + v);
    }
    numVertices--;
}

void AdjacencyMatrixGraph::removeEdge(int u, int v)
{
    if(u < 0 || u >= numVertices || v < 0 || v >= numVertices)
    {
        throw std::out_of_range("Vertex index out of range");
    }
    matrix[u][v] = 0;
}
// std::numeric_limits<double>::infinity()