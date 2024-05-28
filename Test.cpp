#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

using namespace std;

// TEST_CASE("Test isConnected")
// {
//     ariel::Graph g;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isConnected(g) == true);

//     vector<vector<int>> graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::isConnected(g) == false);
// }

// TEST_CASE("Test shortestPath")
// {
//     ariel::Graph g;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

//     vector<vector<int>> graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
//     graph2={{0, 1, 1, 0, 0 },
//             {1, 0, 1, 0, 2 },
//             {1, 1, 0, 1, 0 },
//             {0, 6, 1, 3, 0 },
//             {0, 0, 0, 0, 0 }
//                             };
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->1->4");
//     graph2={{0, 1, 1, 0, 0 },
//             {1, 0, 1, 0, 2 },
//             {1, 1, 0, 3, 0 },
//             {0, 6, 1, 3, 9 },
//             {0, 0, 0, 7, 0 }
//                             };
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->2->3");
//     graph2={{1, 1, 1, 0, 2 },
//             {1, 0, 1, 0, 2 },
//             {1, 1, 0, 1, 0 },
//             {0, 6, 1, 3, 0 },
//             {1, 0, 0, 0, 2 }
//                             };
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::shortestPath(g, 4, 2) == "4->0->2");
//     graph2={{0, 1, 1, 0, 0 },
//             {1, 0, 0, 0, 0 },
//             {1, 0, 0, 0, 0 },
//             {0, 0, 0, 0, 0 },
//             {0, 0, 0, 0, 0 }
//                             };
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
//     graph2={{0, -1, 1, 0, 0 },
//             {1, 0, -7, 0, 2 },
//             {1, -2, 0, 1, 0 },
//             {0, -6, 1, 3, 0 },
//             {1, 0, 0, 7, 2 }
//                             };
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::shortestPath(g, 4, 1) == "Graph contains negative weight cycle!");

                            
// }
// TEST_CASE("Test isContainsCycle")
// {
//     ariel::Graph g;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);

//     vector<vector<int>> graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == true);
//     graph = {
//         {1, 1, 0},
//         {1, 1, 1},
//         {1, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == true);
//     graph = {
//         {0, 1, 0},
//         {0, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
// }
// TEST_CASE("Test isBipartite")
// {
//     ariel::Graph g;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
//     graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 1}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isBipartite(g) == "0");
//     graph = {
//         {1 ,1, 0},
//         {1, 1, 1},
//         {0, 1, 2}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isBipartite(g) == "0");

//     vector<vector<int>> graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::isBipartite(g) == "0");

//     vector<vector<int>> graph3 = {
//         {0, 1, 0, 0, 0},
//         {1, 0, 3, 0, 0},
//         {0, 3, 0, 4, 0},
//         {0, 0, 4, 0, 5},
//         {0, 0, 0, 5, 0}};
//     g.loadGraph(graph3);
//     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
// }
// TEST_CASE("Test invalid graph")
// {
//     ariel::Graph g;
//     vector<vector<int>> graph = {
//         {0, 1, 2, 0},
//         {1, 0, 3, 0},
//         {2, 3, 0, 4},
//         {0, 0, 4, 0},
//         {0, 0, 0, 5}};
//     CHECK_THROWS(g.loadGraph(graph));
//     vector<vector<int>> graph1 = {
//         {0, 1, 2, 0},
//         {1, 0, 3, 0},
//         {0, 0, 0, 5}};
//     CHECK_THROWS(g.loadGraph(graph1));

// }
