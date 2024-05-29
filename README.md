# Graph Algorithms Project

## Overview

This project implements several graph algorithms using C++. It includes two main components: `Graph` and `Algorithms`. The `Graph` class is used to represent a graph structure, while the `Algorithms` class provides various algorithms to operate on the graph, such as Bellman-Ford, depth-first search (DFS), cycle detection, and bipartiteness checking.

## Project Structure

The project consists of four main files:
1. `Graph.hpp`
2. `Graph.cpp`
3. `Algorithms.hpp`
4. `Algorithms.cpp`

### Graph.hpp

This header file defines the `Graph` class, which includes the following methods:

- **loadGraph(std::vector<std::vector<int>> g):** Loads a graph from a given adjacency matrix.
- **printGraph():** Prints the graph's details.
- **weight(size_t s, size_t t):** Returns the weight of the edge from vertex `s` to vertex `t`.
- **get_ver():** Returns the number of vertices in the graph.
- **isSymmetrical():** Checks if the graph is symmetrical, which indicates whether it is undirected.

### Graph.cpp

This source file provides the implementation of the methods declared in `Graph.hpp`. The `loadGraph` method also determines whether the graph is directed or undirected based on its adjacency matrix.

### Algorithms.hpp

This header file defines the `Algorithms` class, which includes static methods for various graph algorithms:

- **bellman_ford(Graph g, size_t start, std::vector<int> &d, std::vector<int> &pi):** Implements the Bellman-Ford algorithm.
- **dfs_v(Graph g, size_t u, std::vector<size_t> &pi, std::vector<int> &colors, bool isSymmetrical):** Performs a DFS for cycle detection.
- **dfs_c(Graph g, size_t u, std::vector<int>& colors):** Helper function for bipartiteness checking.
- **isConnected(Graph g):** Checks if the graph is connected.
- **shortestPath(Graph g, size_t src, size_t dest):** Finds the shortest path from `src` to `dest`.
- **isContainsCycle(Graph g):** Checks if the graph contains a cycle.
- **isBipartite(Graph g):** Checks if the graph is bipartite.
- **negativeCycle(Graph g):** Checks for the presence of a negative cycle.

### Algorithms.cpp

This source file provides the implementation of the methods declared in `Algorithms.hpp`. Each algorithm operates on the `Graph` class to perform specific tasks such as finding the shortest path, detecting cycles, and checking graph properties.

## Usage

1. **Loading a Graph:**
    ```cpp
    ariel::Graph g;
    std::vector<std::vector<int>> adjMatrix = {
        {0, 6, 0, 0},
        {0, 0, 5, 2},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };
    g.loadGraph(adjMatrix);
    g.printGraph();
    ```

2. **Running Algorithms:**
    ```cpp
    std::vector<int> d(g.get_ver(), INT32_MAX);
    std::vector<int> pi(g.get_ver(), -1);
    ariel::Algorithms::bellman_ford(g, 0, d, pi);

    bool connected = ariel::Algorithms::isConnected(g);
    std::cout << "Graph is connected: " << (connected ? "Yes" : "No") << std::endl;

    std::string shortest_path = ariel::Algorithms::shortestPath(g, 0, 3);
    std::cout << "Shortest path from 0 to 3: " << shortest_path << std::endl;

    std::string cycle = ariel::Algorithms::isContainsCycle(g);
    std::cout << cycle << std::endl;

    std::string bipartite = ariel::Algorithms::isBipartite(g);
    std::cout << bipartite << std::endl;

    std::string negCycle = ariel::Algorithms::negativeCycle(g);
    std::cout << negCycle << std::endl;
    ```

## Dependencies

- C++ Standard Library

## Compilation

Use the following command to compile the project:
```sh
g++ -o graph_algorithms Graph.cpp Algorithms.cpp -std=c++11
