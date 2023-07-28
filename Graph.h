//
// Created by kamil on 28.07.2023.
//

#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H


#include "GraphNode.h"

class Graph {
private:
    int numberOfVertices;
    GraphNode **adjacencyList;
public:
    Graph(int numVertices) ;

    void addEdge(int source, int destination, int cost) ;

    void makeEmptyAdjacencyList();

    int getNumVertices() const;

    void setNumVertices(int numVertices);

    GraphNode **getAdjacencyList() const;

    void setAdjacencyList(GraphNode **adjacencyList);

    void makeConnection(GraphNode * connectionFromSourceToDestination);
};


#endif //DIJKSTRA_GRAPH_H
