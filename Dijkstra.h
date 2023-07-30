//
// Created by kamil on 29.07.2023.
//
#include "vector"
#include "Vertex.h"
#include "Graph.h"
#include "GraphNode.h"
#include "queue"
#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H

using namespace std;

class Dijkstra {
private:

    queue<Vertex> queue;
    vector<int> distances;
    vector<int> parent;
    vector<bool> visited;

    Vertex vertex;
    int startVertex;
    int endVertex;
    Graph graph;
    bool question;
    GraphNode* temp;
public:
    Dijkstra(int startVertex, int endVertex, Graph graph, bool question);

    void findShortestPath();

    void prepareForUsingDijkstra();

    void dijkstraAlgorithm();

    void checkAllNeighbors( int u);

    bool isShorterPath( int u);

    void updatePath( int u);

    void savePath();

    void printPath(vector<int> path);

    void showResultOfAlgorithm();

    void setDistances(int numberOfVertex, int value);

    void setParent(int numberOfVertex, int value);

    void setVisited(int numberOfVertex, bool value);
};


#endif //DIJKSTRA_DIJKSTRA_H
