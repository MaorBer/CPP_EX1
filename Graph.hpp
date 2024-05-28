// 

#ifndef GRAPH_HPP
#pragma once
#define GRAPH_HPP
#include <vector>
#include <iostream>
using namespace std;
namespace ariel
{
    class Graph
    {
        private:
            std::vector<std::vector<int>> g;
            size_t edge_counter;
            size_t vertex_counter;
            bool dir;
        public:
            void loadGraph(std::vector<std::vector<int>> g);
            void printGraph();
            int weight(size_t s, size_t t);
            size_t get_ver();
    };
}

#endif