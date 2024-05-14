
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <unordered_set>

#include <utility>
using namespace std;
namespace ariel{
    class Graph{
        private:
        bool mekuvan ;
        std::vector<std::vector<int>> ourGraph;
        public:
        void loadGraph(std::vector<std::vector<int>> v);
        void printGraph();
        bool isConnected();
        std::vector<std::vector<int>> getMatrix();
        std::vector<std::pair<size_t, size_t>>  getEdges() ;
    };
}
#endif