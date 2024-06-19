#ifndef TEST_HPP_
#define TEST_HPP_

#include <map>
#include <utility>
#include <vector>
#include <limits>
#include <queue>
#include <functional>

#include "graphs/graph.hpp"
#include <iostream>



using ShortestPathResult = std::map<int, std::pair<int, std::vector<int>>>;

void dijkstraa(Graph& graph, int sourceIndex, ShortestPathResult& result);
bool bellmanFordd(Graph& graph, int sourceIndex, ShortestPathResult& result);

void test();

#endif