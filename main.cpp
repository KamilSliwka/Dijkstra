#include <iostream>
#include"Vertex.h"
#include "GraphNode.h"
#include "Graph.h"
#include "vector"
#include "queue"
using namespace std;

void dijkstra(int startVertex, int endVertex, Graph g,bool question) {

    queue<Vertex> pq;

    vector<int> distances(g.getNumVertices(), INT_MAX);
    vector<int> parent(g.getNumVertices(), -1);
    vector<bool> visited(g.getNumVertices(), false);
    Vertex w;
    distances[startVertex] = 0;
    w.setDistanceFromStart(0);
    w.setVertexNumber(startVertex);
    pq.push(w);

    while (!pq.empty()) {

        int u = pq.front().getVertexNumber();
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        GraphNode* temp = g.getAdjacencyList()[u];

        while (temp != nullptr) {
            int v = temp->getDestination();
            int cost = temp->getCost();

            if (distances[u] != INT_MAX && distances[u] + cost < distances[v]) {
                distances[v] = distances[u] + cost;
                parent[v] = u;
                Vertex tmp;
                tmp.setDistanceFromStart( distances[v]);
                tmp.setVertexNumber(v);
                pq.push(tmp);
            }

            temp = temp->getNext();
        }
    }
    if (startVertex== endVertex) {
        cout << 0 << endl;
    }
    else if (parent[endVertex] == -1) {
        cout << "There is no path from vertex " << startVertex << " to vertex " << endVertex << endl;
    }
    else if(question==true) {
        cout<< "cost: "<< distances[endVertex]<<endl;
        int vertex = endVertex;
        vector<int> path;
        path.push_back(vertex);
        while (vertex != startVertex) {
            vertex = parent[vertex];
            path.push_back(vertex);
        }
        cout<<"path: ";
        for (int i = path.size()-1 ; i >= 0; i--) {
            cout << path[i];
            if (i != 0) {
                cout << "->";
            }
        }
        cout << endl;

    }
    else {
        cout << distances[endVertex] << endl;;
    }
}

int main() {
    Graph g(5);
    g.addEdge(0,1,4);
    g.addEdge(0,3,2);
    g.addEdge(0,4,3);
    g.addEdge(1,2,8);
    g.addEdge(2,4,1);
    g.addEdge(3,4,2);
    dijkstra(0,2,g,true);
    return 0;
}
