//
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
    int row = graph.size();
    int col = graph[0].size();
    if (row != col)
    {
        throw invalid_argument("Invalid graph: The graph is not a square matrix.");
    }
    this->g = graph;
    this->vertex_counter = graph.size();
    size_t c = 0;
    for (size_t i = 0; i < this->vertex_counter; i++)
    {
        for (size_t j = 0; j < this->vertex_counter; j++)
        {
            if (graph[i][j] != 0 && graph[j][i] != 0)
            {
                c++;
            }
            if (graph[i][j] != 0 && graph[j][i] == 0 || graph[j][i] != 0 && graph[i][j] == 0)
            {
                this->dir = true;
            }
            graph[i][i] = 0; // Remove self loops caused by matrix initialization
        }
    }
    if (dir)
    {
        this->edge_counter = c;
    }
    else
    {
        this->edge_counter = (size_t)c / 2;
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