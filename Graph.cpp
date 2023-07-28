//
// Created by kamil on 28.07.2023.
//

#include "Graph.h"

Graph::Graph(int numberOfVertices) {
    this->numberOfVertices = numberOfVertices;
    makeEmptyAdjacencyList();
}

void Graph::makeEmptyAdjacencyList() {
    adjacencyList = new GraphNode *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++) {
        adjacencyList[i] = nullptr;
    }
}

void Graph::addEdge(int source, int destination, int cost) {
    GraphNode * connectionFromSourceToDestination = new GraphNode(source, destination, cost);
    GraphNode *connectionFromDestinationToSource = new GraphNode(destination, source, cost);
    makeConnection(connectionFromSourceToDestination);
    makeConnection(connectionFromDestinationToSource);
}

void Graph::makeConnection(GraphNode * connectionFromSourceToDestination){
    connectionFromSourceToDestination->setNext(adjacencyList[connectionFromSourceToDestination->getSource()]);
    adjacencyList[connectionFromSourceToDestination->getSource()] = connectionFromSourceToDestination;
}

int Graph::getNumVertices() const {
    return numberOfVertices;
}

void Graph::setNumVertices(int numVertices) {
    Graph::numberOfVertices = numVertices;
}

GraphNode **Graph::getAdjacencyList() const {
    return adjacencyList;
}

void Graph::setAdjacencyList(GraphNode **adjacencyList) {
    Graph::adjacencyList = adjacencyList;
}
