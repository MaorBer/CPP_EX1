// #ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <vector>
#include <string>

using namespace std;
namespace ariel{
    class Algorithms{
        public:
        static bool isConnected (Graph g);
        static std::vector<bool> BFS(size_t startVertex , Graph n);
        static bool isContainsCycle(Graph g);
        static string shortestPath(Graph g, size_t h, size_t s);
        static bool isNegativeCycle(Graph g);
        static string  isBipartite(Graph g);
    };
    }