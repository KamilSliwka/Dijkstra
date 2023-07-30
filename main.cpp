#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"

using namespace std;

int main() {
    Graph g(5);
    g.addEdge(0,1,4);
    g.addEdge(0,3,2);
    g.addEdge(0,4,3);
    g.addEdge(1,2,8);
    g.addEdge(2,4,1);
    g.addEdge(3,4,2);
    Dijkstra d(1,2,g,true);
    d.findShortestPath();

    return 0;
}
