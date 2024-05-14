#include "Graph.hpp"
#include <iostream>
using namespace ariel;
using namespace std;
#include <unordered_set>

void Graph :: loadGraph(std::vector<std::vector<int>> v){

    if (v.empty()){
        std :: __throw_invalid_argument("matrx is enpty ");
    }
    if ( v.size() != v[0].size()){
        std :: __throw_invalid_argument("matrix is not a square");
    }
    this->ourGraph=v;
    this->mekuvan=(bool) isConnected();

}
void Graph :: printGraph(){
    int edges = 0;
    for(size_t i=0;i<this->ourGraph.size();i++){
        for (size_t j=0;j<this->ourGraph[0].size();j++){
            if(this->ourGraph[i][j] != 0){
                edges++;
            }
        }
    }
    if (this->mekuvan){
        edges=edges/2;
    }
    std::cout << "Graph with " << this->ourGraph.size() << " vertices and " << edges << " edges.\n";
}

bool Graph :: isConnected (){
    for(size_t i=0;i<this->ourGraph.size();i++){
        for (size_t j=0;j<this->ourGraph[0].size();j++){
            if(this->ourGraph[i][j] != this->ourGraph[j][i]){
                return false;
            }
        }
    }
    return true;
}
std::vector<std::vector<int>> Graph :: getMatrix(){
    return this->ourGraph;
}
// returns the pair of the edge
std::vector<std::pair<size_t, size_t>> Graph :: getEdges()  {
            std::vector<std::pair<size_t, size_t>> edges;
            size_t numVertices = this->ourGraph.size();
            for (size_t i = 0; i < numVertices; ++i) {
                for (size_t j = 0; j < numVertices; ++j) {
                    if (this->ourGraph[i][j] != 0) {
                        edges.push_back({i, j});
                    }
                }
            }
            return edges;
        }

