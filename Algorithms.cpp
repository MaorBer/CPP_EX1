#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <queue>
#include <stack>
#include <limits>
#include <stdexcept>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <sstream>
using namespace ariel;
using namespace std;
bool Algorithms :: isConnected( Graph g){
    std::vector<bool> v=BFS(0,g);
    for( size_t i=0 ; i< g.getMatrix().size();i++){
        if (v[i]== false) return false;
    }
    return true ;
}
bool containsNumber(const std::stack<size_t>& stack, int target) {
    
    std::stack<size_t> temp = stack; 
    while (!temp.empty()) {
        if (temp.top() == target) {
            return true; 
        }
        temp.pop(); 
    }
    return false; 
}
  std::vector<bool> Algorithms :: BFS (size_t startVertex , Graph n) {
        std::vector<bool> visited(n.getMatrix().size(), false);
        std::queue<size_t> stuck;
        visited[startVertex] = true;
        stuck.push(startVertex);
        std::vector<int> visitedINT(n.getMatrix().size(), 0);
        while (!stuck.empty()) {
            size_t currentVertex = stuck.front();
            stuck.pop();
            for (size_t i = 0; i < n.getMatrix().size(); i++) {
                if (n.getMatrix()[currentVertex][i] ) {
                    visitedINT[i]++;
                    if( visited[i]== false){
                    visited[i] = true;
                    stuck.push(i);}
                }
            }
        }
        
        return visited ;
    }
bool Algorithms :: isContainsCycle(Graph g ){
    std::vector<bool> visited(g.getMatrix().size(), false);
    std:: stack <size_t> stuck ;
    visited[0] = true;
    stuck.push(0);
    bool iscontains =true;
    // dfs
    while (!stuck.empty()) {
        size_t currentVertex = stuck.top();
        stuck.pop();
            for (size_t i = 0; i < g.getMatrix().size(); i++) {
                if (g.getMatrix()[currentVertex][i] != 0) {
                    if( !visited[i]){
                    visited[i] = true;
                    stuck.push(i);}
                    // based on the dfs algorithem 
                    else{
                        if (containsNumber(stuck,i)) return true;
                    }
                }
            }
        if (stuck.empty()){
            for (size_t i=0; i<visited.size();i++){
                if (visited[i]==false) {
                    stuck.push(i);
                    break ;} 
            }
        }
        }
    
        return false ;
        
}

    string Algorithms::shortestPath(Graph g, size_t source, size_t destination) {
        // Number of vertices in the graph
        size_t V = g.getMatrix().size();
        
        // Initialize distances to all vertices as infinite and source distance as 0
        vector<int> dist(V, numeric_limits<int>::max());
        dist[source] = 0;

        // Array to store the parent vertices for path reconstruction
        vector<int> parent(V, -1);

        // Relax all edges |V| - 1 times
        for (size_t i = 0; i < V - 1; ++i) {
            for (const auto& edge : g.getEdges()) {
                size_t u = edge.first;
                size_t v = edge.second;
                int weight = g.getMatrix()[u][v];
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }
        if (dist[destination] >10000) return "-1";// checking if it didnt reached to the vertex
        // Check for negative-weight cycles
        for (const auto& edge : g.getEdges()) {
            size_t u = edge.first;
            size_t v = edge.second;
            int weight = g.getMatrix()[u][v];
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                return "Graph contains negative weight cycle!";
            }
        }

        // Construct the shortest path from source to destination
        stringstream ss;
        ss << destination;
        size_t current = destination;
        while (parent[current] != -1) {
            ss << ">-" << parent[current];
            current = (size_t) parent[current];
        }
        
        string path = ss.str();
        reverse(path.begin(), path.end());

        return  path;
    }
bool Algorithms :: isNegativeCycle(Graph g){
    size_t v=0;
    size_t s= g.getMatrix().size()-1;
    string final = shortestPath(g,v,s);
    if (final == "Graph contains negative weight cycle!"){
        return true ;
    }
    return false;
}
string Algorithms:: isBipartite(Graph g)  {
    size_t V = g.getMatrix().size();
    vector<int> color(V, -1);

    // Queue for BFS
    queue<size_t> q;

    // Start BFS from any vertex
    for (size_t i = 0; i < V; ++i) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                size_t u = q.front();
                q.pop();

                for (size_t v = 0; v < V; ++v) {
                    // An edge exists and destination is not colored
                    if (g.getMatrix()[u][v] && color[v] == -1) {
                        color[v] = 1 - color[u]; // Color opposite to u
                        q.push(v);
                    }
                    // An edge exists and destination has the same color as source
                    else if (g.getMatrix()[u][v] && color[v] == color[u]) {
                        return "0";
                    }
                }
            }
        }
    }

    // If we reach here, then all adjacent vertices can be colored with different colors
    // So, the graph is bipartite
    vector<int> A, B;
    for (size_t i = 0; i < V; ++i) {
        if (color[i] == 0) {
            A.push_back(i);
        } else {
            B.push_back(i);
        }
    }

    // Prepare the result string
    string result = "The graph is bipartite: A={";
    for (size_t i = 0; i < A.size(); ++i) {
        result += to_string(A[i]);
        if (i < A.size() - 1) {
            result += ", ";
        }
    }
    result += "}, B={";
    for (size_t i = 0; i < B.size(); ++i) {
        result += to_string(B[i]);
        if (i < B.size() - 1) {
            result += ", ";
        }
    }
    result += "}";

    return result;
}



    




