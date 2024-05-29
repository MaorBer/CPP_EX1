// ID: 212305965
// Email: maorw9@gmail.com

#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <stack>
#include <climits>
#include <limits>
#include <stdexcept>
#include <queue>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;
using namespace ariel;

void Algorithms::bellman_ford(Graph g, size_t start, vector<int> &d, vector<int> &pi)
{
    d[start] = 0;
    for (size_t i = 0; i < g.get_ver() - 1; i++)
    {
        for (size_t j = 0; j < g.get_ver(); j++)
        {
            for (size_t k = 0; k < g.get_ver(); k++)
            {
                if (g.weight(j, k) != 0 && d[j] != INT32_MAX && d[k] > d[j] + g.weight(j, k))
                {
                    d[k] = d[j] + g.weight(j, k);
                    pi[k] = j;
                }
            }
        }
    }
    for (size_t i = 0; i < g.get_ver(); i++)
    {
        for (size_t j = 0; j < g.get_ver(); j++)
        {
            if (g.weight(i, j) != 0 && d[i] != INT32_MAX && (d[j] > d[i] + g.weight(i, j) || d[i] == INT32_MIN))
            {
                d[j] = INT32_MIN;
                pi[j] = i;
            }
        }
    }
}

bool Algorithms::isConnected(Graph g)
{
    for (size_t s = 0; s < g.get_ver(); s++)
    {
        vector<int> d(g.get_ver(), INT32_MAX);
        vector<int> pi(g.get_ver(), -1);
        bellman_ford(g, s, d, pi);
        for (size_t i = 0; i < g.get_ver(); i++)
        {
            if (d[i] == INT32_MAX)
                return false; 
        }
    }
    return true;
}

std::string Algorithms::shortestPath(Graph g, size_t src, size_t dest)
{
    string str = "";
    str += std::to_string(dest);
    vector<int> d(g.get_ver(), INT32_MAX);
    std::vector<int> pi(g.get_ver(), -1);
    bellman_ford(g, src, d, pi);
    if (d[dest] == INT32_MIN)
    {
        return "There is a negative cycle"; 
    }
    if (pi[dest] == -1)
    {
        str = std::to_string(-1) + " :(there is no path between " + std::to_string(src) + " to " + std::to_string(dest) + ")";
        return str;
    }
    int t = (int)dest;
    while (t != src)
    {
        str = std::to_string(pi[(size_t)t]) + "-->" + str;
        t = pi[(size_t)t];             
    }
    return str;
}

size_t Algorithms::dfs_v(Graph g, size_t u, std::vector<size_t> &pi, std::vector<int> &colors, bool isSymmetrical)
{
    colors[u] = 1;
    for (size_t j = 0; j < g.get_ver(); j++)
    {
        if (g.weight(u, j) == 0)
        {
            continue;
        }
        if (colors[j] == 0)
        {
            pi[j] = u;
            size_t res = dfs_v(g, j, pi, colors, isSymmetrical);
            if (res != SIZE_MAX)
            {
                return res;
            }
        }
        else if (colors[j] == 1 && (!isSymmetrical || pi[u] != j))
        {
            pi[j] = u;
            return j;
        }
    }

    colors[u] = 2;
    return SIZE_MAX;
}


string Algorithms::isContainsCycle(Graph g)
{
    string str = "0";
    vector<int> colors(g.get_ver(), 0);
    vector<size_t> pi(g.get_ver(), SIZE_MAX);

    // Check if the graph is symmetrical
    bool isSymmetrical = g.isSymmetrical();

    for (size_t i = 0; i < g.get_ver(); i++)
    {
        if (colors[i] == 0)
        {
            size_t s = dfs_v(g, i, pi, colors, isSymmetrical);
            if (s != SIZE_MAX)
            {
                str = std::to_string(s);
                size_t parent = pi[s];
                while (parent != s)
                {
                    str = std::to_string(parent) + "-->" + str;
                    parent = pi[parent];
                }
                str = std::to_string(s) + "-->" + str;
                return "The cycle is:" + str;
            }
        }
    }
    return str;
}


bool Algorithms::dfs_c(Graph g, size_t u, vector<int> &colors)
{
    for (size_t j = 0; j < g.get_ver(); j++)
    {
        if (g.weight(u, j) == 0)
        {
            continue;
        }
        if (colors[j] == 0)
        {
            colors[j] = 3 - colors[u];
            bool res = dfs_c(g, j, colors);
            if (!res)
            {
                return res;
            }
        }
        else if (colors[j] == colors[u] && j != u)
        {
            return false;
        }
    }
    return true;
}

std::string Algorithms::isBipartite(Graph g)
{
    std::vector<int> colors(g.get_ver(), 0);
    std::string setA = "{";
    std::string setB = "{";

    for (size_t i = 0; i < g.get_ver(); i++)
    {
        if (colors[i] != 0)
        {
            continue;
        }
        
        // Initialize color for the current vertex
        colors[i] = 1;
        setA += std::to_string(i) + ", ";

        // Perform BFS from the current vertex to assign colors to vertices
        std::queue<size_t> q;
        q.push(i);
        while (!q.empty())
        {
            size_t u = q.front();
            q.pop();

            for (size_t v = 0; v < g.get_ver(); v++)
            {
                if (g.weight(u, v) != 0 && colors[v] == 0)
                {
                    colors[v] = 3 - colors[u]; // Assign opposite color to neighbor
                    if (colors[v] == 1)
                        setA += std::to_string(v) + ", ";
                    else
                        setB += std::to_string(v) + ", ";
                    q.push(v);
                }
                else if (g.weight(u, v) != 0 && colors[u] == colors[v])
                {
                    // If adjacent vertices have the same color, the graph is not bipartite
                    return "The graph isn't bipartite";
                }
            }
        }
    }

    // Remove trailing comma and space
    if (!setA.empty()) setA.pop_back(); 
    if (!setB.empty()) setB.pop_back();

    // Close sets
    setA += "}";
    setB += "}";

    return "The graph is bipartite: A=" + setA + ", B=" + setB;
}


string Algorithms::negativeCycle(Graph g)
{
    string str = "There isn't a negative cycle";
    vector<size_t> points;
    for (size_t s = 0; s < g.get_ver(); s++)
    {
        vector<int> d(g.get_ver(), INT32_MAX);
        vector<int> pi(g.get_ver(), -1);
        bellman_ford(g, s, d, pi);
        if (d[s] < 0)
        {
            str = "";
            points.push_back(s);
            for (size_t t = 0; t < points.size(); t++)
            {
                if (pi[s] == points[t])
                {
                    for (size_t k = 1; k < points.size(); k++)
                    {
                        str += std::to_string(points[k]) + ", ";
                    }
                    str += std::to_string(points[0]);
                    return str;
                }
                else
                {
                    points.push_back(t);
                }
            }
        }
    }
    return str;
}
