// ID: 212305965
// Email: maorw9@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

using namespace std;


TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0-->1-->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1 :(there is no path between 0 to 4)");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->1-->2-->0");
    
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2,}, B={1,}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph isn't bipartite");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4,}, B={1, 3,}");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "There isn't a negative cycle");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "There isn't a negative cycle");

    vector<vector<int>> graph3 = {
        {0, 1, 3},
        {-1, 0, 1},
        {1, -1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "There isn't a negative cycle");

    vector<vector<int>> graph4 = {
        {0, 1, -1},
        {-1, 0, -1},
        {1, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == "0, 1, 2, 0");
}

TEST_CASE("Test loadGraph with invalid arguments")
{
    ariel::Graph g;
    // Empty graph
    CHECK_THROWS_AS(g.loadGraph({}), std::invalid_argument);
    // Non-square graph
    CHECK_THROWS_AS(g.loadGraph({{0, 1}, {1, 0}, {0, 1}}), std::invalid_argument);
}

TEST_CASE("Test isSymmetrical")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(g.isSymmetrical() == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(g.isSymmetrical() == true);

    vector<vector<int>> graph3 = {
        {0, 1, -1},
        {-1, 0, 1},
        {1, -1, 0}};
    g.loadGraph(graph3);
    CHECK(g.isSymmetrical() == false);
}

TEST_CASE("Test weight")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g.loadGraph(graph);
    CHECK(g.weight(0, 1) == 1);
    CHECK(g.weight(1, 0) == 3);
    CHECK(g.weight(2, 2) == 0);
}

TEST_CASE("Test isConnected with larger graph")
{
    ariel::Graph g;
    // Graph with 5 vertices connected in a cycle
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Disconnected graph with 5 vertices
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath with larger graph")
{
    ariel::Graph g;
    // Graph with 5 vertices connected in a cycle
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0-->1-->2");

    // Disconnected graph with 5 vertices
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1 :(there is no path between 0 to 4)");
}

TEST_CASE("Test isContainsCycle with larger graph")
{
    ariel::Graph g;
    // Graph with 5 vertices connected in a cycle
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->1-->2-->3-->4-->0");

    // Disconnected graph with 5 vertices
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
}

TEST_CASE("Test isBipartite with larger graph")
{
    ariel::Graph g;
    // Graph with 5 vertices connected in a cycle
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph isn't bipartite");

    // Bipartite graph with 5 vertices
    vector<vector<int>> graph2 = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 0, 1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph isn't bipartite");
}

TEST_CASE("Test negativeCycle with larger graph")
{
    ariel::Graph g;
    // Graph with 5 vertices connected in a cycle
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "There isn't a negative cycle");

    // Graph with negative cycle
    vector<vector<int>> graph2 = {
        {0, -1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, -1},
        {1, 0, 0, -1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "0, 1, 2, 3, 4, 0");
}

TEST_CASE("Test loadGraph with invalid arguments (larger graph)")
{
    ariel::Graph g;
    // Empty graph
    CHECK_THROWS_AS(g.loadGraph({}), std::invalid_argument);
    // Non-square graph
    CHECK_THROWS_AS(g.loadGraph({{0, 1}, {1, 0}, {0, 1}}), std::invalid_argument);
}

TEST_CASE("Test isSymmetrical with larger graph")
{
    ariel::Graph g;
    // Symmetrical graph
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK(g.isSymmetrical() == true);

    // Non-symmetrical graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(g.isSymmetrical() == false);
}

TEST_CASE("Test weight with larger graph")
{
    ariel::Graph g;
    // Graph with 5 vertices connected in a cycle
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(g.weight(0, 1) == 1);
    CHECK(g.weight(1, 0) == 1);
    CHECK(g.weight(2, 4) == 0);
    CHECK(g.weight(4, 3) == 1);
    CHECK(g.weight(3, 2) == 1);
    CHECK(g.weight(1, 3) == 0);
}

TEST_CASE("Test shortestPath with negative weights")
{
    ariel::Graph g;
    // Graph with negative weights
    vector<vector<int>> graph = {
        {0, 1, -3, 0, 5},
        {0, 0, 2, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, -2},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0-->2-->3-->4");

    // Graph with negative cycle
    vector<vector<int>> graph2 = {
        {0, 1, -3, 0, 5},
        {0, 0, 2, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, -2},
        {0, 0, 0, -6, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "There is a negative cycle");
}

TEST_CASE("Test isContainsCycle with disconnected graph")
{
    ariel::Graph g;
    // Disconnected graph with cycle in each component
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    // Disconnected graph with no cycle
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
}

TEST_CASE("Test isBipartite with disconnected graph")
{
    ariel::Graph g;
    // Disconnected graph with bipartite components
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4,}, B={1, 3,}");

    // Disconnected graph with non-bipartite components
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph isn't bipartite");
}
