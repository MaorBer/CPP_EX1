// ID: 212305965
// Email: maorw9@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include <vector>
#include "Graph.hpp"

namespace ariel
{
    class Algorithms
    {
    public:
        static void bellman_ford(Graph g, size_t start, std::vector<int> &d, std::vector<int> &pi);
        static size_t dfs_v(Graph g, size_t u, std::vector<size_t> &pi, std::vector<int> &colors, bool isSymmetrical);
        static bool dfs_c(Graph g, size_t u, std::vector<int>& colors);
        static bool isConnected(Graph g);
        static std::string shortestPath(Graph g, size_t src, size_t dest);
        static string isContainsCycle(Graph g);
        static std::string isBipartite(Graph g);
        static std::string negativeCycle(Graph g);
    };
}
#endif