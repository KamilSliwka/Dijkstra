//
// Created by kamil on 29.07.2023.
//

#include <climits>
#include <iostream>
#include "Dijkstra.h"

using namespace std;

Dijkstra::Dijkstra(int startVertex, int endVertex, Graph graph,bool question){
    this->startVertex = startVertex;
    this->endVertex = endVertex;
    this->graph = graph;
    this->question = question;

}

void Dijkstra::findShortestPath() {
    prepareForUsingDijkstra();
    dijkstraAlgorithm();
    showResultOfAlgorithm();
}

void Dijkstra::prepareForUsingDijkstra(){
   // vector<int> distances(graph.getNumVertices(), INT_MAX);
    setDistances(graph.getNumVertices(), INT_MAX);
    //vector<int> parent(graph.getNumVertices(), -1);
    setParent(graph.getNumVertices(), -1);
   // vector<bool> visited(graph.getNumVertices(), false);
    setVisited(graph.getNumVertices(), false);
    distances[startVertex] = 0;
    vertex.setDistanceFromStart(0);
    vertex.setVertexNumber(startVertex);
    queue.push(vertex);
}
void Dijkstra::dijkstraAlgorithm(){
    while (!queue.empty()) {
        int u = queue.front().getVertexNumber();
        queue.pop();
        if (visited[u]){
            continue;
            }
        visited[u] = true;

        this->temp = graph.getAdjacencyList()[u];
        checkAllNeighbors(u);
    }
}

void Dijkstra::checkAllNeighbors( int u){
    while (temp != nullptr) {
        if (isShorterPath(u)) {
            updatePath(u);
        }
        temp = temp->getNext();
    }
}

bool Dijkstra::isShorterPath(int u){
    int v = temp->getDestination();
    int cost = temp->getCost();
    if (distances[u] != INT_MAX && distances[u] + cost < distances[v])
        return true;
    else
        return false;
}

void Dijkstra::updatePath(int u){
    int v = temp->getDestination();
    int cost = temp->getCost();
    distances[v] = distances[u] + cost;
    parent[v] = u;
    Vertex tmp;
    tmp.setDistanceFromStart( distances[v]);
    tmp.setVertexNumber(v);
    queue.push(tmp);
}

void Dijkstra::showResultOfAlgorithm(){
    if (startVertex== endVertex) {
        cout << 0 << endl;
    }
    else if (parent[endVertex] == -1) {
        cout << "There is no path from vertex " << startVertex << " to vertex " << endVertex << endl;
    }
    else if(question==true) {
        cout<< "cost: "<< distances[endVertex]<<endl;
        savePath();
        cout << endl;

    }
    else {
        cout << distances[endVertex] << endl;;
    }
}

void Dijkstra::savePath(){
    int vertex = endVertex;
    vector<int> path;
    path.push_back(vertex);
    while (vertex != startVertex) {
        vertex = parent[vertex];
        path.push_back(vertex);
    }
    cout<<"path: ";
    printPath(path);
}

void Dijkstra::printPath( vector<int> path){
    for (int i = path.size()-1 ; i >= 0; i--) {
        cout << path[i];
        if (i != 0) {
            cout << "->";
        }
    }
}
void Dijkstra::setDistances(int numberOfVertex , int value){
    for(int i= 0;i<numberOfVertex;i++){
        distances.push_back(value);
    }
}

void Dijkstra::setParent(int numberOfVertex , int value){
    for(int i= 0;i<numberOfVertex;i++){
        parent.push_back(value);
    }
}

void Dijkstra::setVisited(int numberOfVertex , bool value){
    for(int i= 0;i<numberOfVertex;i++){
       visited.push_back(value);
    }
}