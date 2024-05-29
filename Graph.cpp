// ID: 212305965
// Email: maorw9@gmail.com

#include <iostream>
#include <vector>
#include "Graph.hpp"
using namespace std;
using namespace ariel;







void Graph::loadGraph(std::vector<std::vector<int>> graph)
{
    if (graph.empty())
    {
        throw invalid_argument("Invalid graph: The graph is empty.");
    }
    
    size_t n = graph.size(); // Assuming the graph is square
    for (size_t i = 0; i < n; ++i)
    {
        if (graph[i].size() != n)
        {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }

    g = graph;
    vertex_counter = n;

    // Reset edge counter
    edge_counter = 0;

    // Detect if the graph is directed or not
    bool hasDirectedEdge = false;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (graph[i][j] != 0)
            {
                edge_counter++;
                if (i != j && graph[j][i] != 0) // Undirected edge
                {
                    dir = false;
                }
                else // Directed edge
                {
                    hasDirectedEdge = true;
                }
            }
        }
    }

    // If the graph has directed edges but no undirected edges, consider it directed
    dir = hasDirectedEdge || dir;

    // If the graph is directed, ensure self-loops are removed
    if (dir)
    {
        for (size_t i = 0; i < n; ++i)
        {
            g[i][i] = 0;
        }
    }
}


void Graph::printGraph()
{
    std::cout << "Graph with " << vertex_counter << " vertices and " << edge_counter << " edges." << std::endl;
}

int Graph::weight(size_t s, size_t t)
{
    return this->g[s][t];
}

size_t Graph::get_ver()
{
    return this->vertex_counter;
}

bool Graph::isSymmetrical() {
    size_t n = get_ver();
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (weight(i, j) != weight(j, i)) {
                return false;
            }
        }
    }
    return true;
}
