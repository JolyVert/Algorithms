#include "graphs/shortest_path_algorithms.hpp"

using ShortestPathResult = std::map<int, std::pair<int, std::vector<int>>>;

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    // TODO: implement
    const int numVertices = graph.getNumVertices();
    std::vector<double> dist(numVertices, std::numeric_limits<double>::max());
    std::vector<int> predecessors(numVertices, -1);
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>,
                        std::greater<std::pair<double, int>>>
        minHeap;

    minHeap.emplace(0, sourceIndex);
    dist[sourceIndex] = 0;

    while(!minHeap.empty())
    {
        auto [currDist, u] = minHeap.top();
        minHeap.pop();

        if(currDist > dist[u])
            continue;

        for(const auto& [v, weight] : graph.getNeighbors(u))
        {
            double newDist = dist[u] + weight;
            if(newDist < dist[v])
            {
                dist[v] = newDist;
                predecessors[v] = u;
                minHeap.emplace(newDist, v);
            }
        }
    }

    for(int v = 0; v < numVertices; ++v)
    {
        if(dist[v] < std::numeric_limits<double>::max())
        {
            std::vector<int> path;
            for(int at = v; at != -1; at = predecessors[at])
            {
                path.push_back(at);
            }
            std::reverse(path.begin(), path.end());
            result[v] = {dist[v], path};
        }
    }
}

bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    // TODO: implement
    const int numVertices = graph.getNumVertices();
    std::vector<double> dist(numVertices, std::numeric_limits<double>::max());
    std::vector<int> predecessors(numVertices, -1);

    dist[sourceIndex] = 0;
    for(int i = 0; i < numVertices - 1; ++i)
    {
        for(int u = 0; u < numVertices; ++u)
        {
            for(const auto& [v, weight] : graph.getNeighbors(u))
            {
                if(dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    predecessors[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for(int u = 0; u < numVertices; ++u)
    {
        for(const auto& [v, weight] : graph.getNeighbors(u))
        {
            if(dist[u] + weight < dist[v])
            {
                return false; // Negative cycle detected
            }
        }
    }

    for(int v = 0; v < numVertices; ++v)
    {
        if(dist[v] < std::numeric_limits<double>::max())
        {
            std::vector<int> path;
            for(int at = v; at != -1; at = predecessors[at])
            {
                path.push_back(at);
            }
            std::reverse(path.begin(), path.end());
            result[v] = {dist[v], path};
        }
    }
    return true;
}


