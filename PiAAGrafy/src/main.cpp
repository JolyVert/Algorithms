#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include "graphs/adjacency_list_graph.hpp"
#include "graphs/adjacency_matrix_graph.hpp"
#include "graphs/shortest_path_algorithms.hpp"

#include "graphs/test.hpp"

using namespace std::chrono;
using ShortestPathResult = std::map<int, std::pair<int, std::vector<int>>>;

int main(int argc, char* argv[])
{
    std::cout << "Tu wykonujemy testy efektywnosci algorytmow" << std::endl;

    std::ifstream file10("C:/Users/Anton/source/repos/PiAAGrafy/sp_data/graph/graphV10D1.txt");
    std::ifstream file50("C:/Users/Anton/source/repos/PiAAGrafy/sp_data/graph/graphV50D1.txt");
    std::ifstream file100("C:/Users/Anton/source/repos/PiAAGrafy/sp_data/graph/graphV100D1.txt");
    std::ifstream file150("C:/Users/Anton/source/repos/PiAAGrafy/sp_data/graph/graphV150D1.txt");
    std::ifstream file200("C:/Users/Anton/source/repos/PiAAGrafy/sp_data/graph/graphV200D1.txt");

    /*if(!file)
    {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }*/

    /*try
    {
        auto graph = AdjacencyMatrixGraph::createGraph(file);
        graph->printGraph();
        ShortestPathResult result;
        int sourceIndex;
        sourceIndex = graph->getStartVertex();
        dijkstra(*graph, sourceIndex, result);
       
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }*/

    // C:/Users/Anton/source/repos/PiAAGrafy/src/

    auto graph10 = AdjacencyMatrixGraph::createGraph(file10);
    auto graph50 = AdjacencyMatrixGraph::createGraph(file50);
    auto graph100 = AdjacencyMatrixGraph::createGraph(file100);
    auto graph150 = AdjacencyMatrixGraph::createGraph(file150);
    auto graph200 = AdjacencyMatrixGraph::createGraph(file200);
    
    //graph10->printGraph();
    ShortestPathResult resultDijkstra10;
    ShortestPathResult resultDijkstra50;
    ShortestPathResult resultDijkstra100;
    ShortestPathResult resultDijkstra150;
    ShortestPathResult resultDijkstra200;

    ShortestPathResult resultFord10;
    ShortestPathResult resultFord50;
    ShortestPathResult resultFord100;
    ShortestPathResult resultFord150;
    ShortestPathResult resultFord200;

    int sourceIndex10 = graph10->getStartVertex();
    int sourceIndex50 = graph50->getStartVertex();
    int sourceIndex100 = graph100->getStartVertex();
    int sourceIndex150 = graph150->getStartVertex();
    int sourceIndex200 = graph200->getStartVertex();
    
    //dijkstraa(*graph10, sourceIndex10, result10);
    //bellmanFordd(*graph10, sourceIndex10, result10);

    auto start = high_resolution_clock::now();
    dijkstraa(*graph10, sourceIndex10, resultDijkstra10);
    auto stop = high_resolution_clock::now();
    auto durationDijkstra10 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    dijkstraa(*graph50, sourceIndex50, resultDijkstra50);
    stop = high_resolution_clock::now();
    auto durationDijkstra50 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    dijkstraa(*graph100, sourceIndex100, resultDijkstra100);
    stop = high_resolution_clock::now();
    auto durationDijkstra100 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    dijkstraa(*graph150, sourceIndex150, resultDijkstra150);
    stop = high_resolution_clock::now();
    auto durationDijkstra150 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    dijkstraa(*graph200, sourceIndex200, resultDijkstra200);
    stop = high_resolution_clock::now();
    auto durationDijkstra200 = duration_cast<microseconds>(stop - start);



    start = high_resolution_clock::now();
    bellmanFordd(*graph10, sourceIndex10, resultFord10);
    stop = high_resolution_clock::now();
    auto durationFord10 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    bellmanFordd(*graph50, sourceIndex50, resultFord50);
    stop = high_resolution_clock::now();
    auto durationFord50 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    bellmanFordd(*graph100, sourceIndex100, resultFord100);
    stop = high_resolution_clock::now();
    auto durationFord100 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    bellmanFordd(*graph150, sourceIndex150, resultFord150);
    stop = high_resolution_clock::now();
    auto durationFord150 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    bellmanFordd(*graph200, sourceIndex200, resultFord200);
    stop = high_resolution_clock::now();
    auto durationFord200 = duration_cast<microseconds>(stop - start);
    


    std::cout << "Time taken by Dijkstra algorithm on 10V graph: " << durationDijkstra10.count() << "ms" << std::endl;
    std::cout << "Time taken by Dijkstra algorithm on 50V graph: " << durationDijkstra50.count() << "ms" << std::endl;
    std::cout << "Time taken by Dijkstra algorithm on 100V graph: " << durationDijkstra100.count() << "ms" << std::endl;
    std::cout << "Time taken by Dijkstra algorithm on 150V graph: " << durationDijkstra150.count() << "ms" << std::endl;
    std::cout << "Time taken by Dijkstra algorithm on 200V graph: " << durationDijkstra200.count() << "ms" << std::endl;
    std::cout << std::endl;
    std::cout << "Time taken by Bellman-Ford algorithm on 10V graph: " << durationFord10.count() << "ms" << std::endl;
    std::cout << "Time taken by Bellman-Ford algorithm on 50V graph: " << durationFord50.count() << "ms" << std::endl;
    std::cout << "Time taken by Bellman-Ford algorithm on 100V graph: " << durationFord100.count() << "ms" << std::endl;
    std::cout << "Time taken by Bellman-Ford algorithm on 150V graph: " << durationFord150.count() << "ms" << std::endl;
    std::cout << "Time taken by Bellman-Ford algorithm on 200V graph: " << durationFord200.count() << "ms" << std::endl;



    return 0;
}