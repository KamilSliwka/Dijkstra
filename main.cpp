#include <iostream>
#include "vector"
#include "queue"
using namespace std;

struct Vertex {
    int vertexNumber;
    int distanceFromStart;
};

struct GraphNode {
    int source;
    int destination;
    int cost;
    GraphNode* next;

    GraphNode(int source, int destination, int cost) {
        this->source = source;
        this->destination = destination;
        this->cost = cost;
        next = nullptr;
    }
};

struct Graph {
    int numVertices;
    GraphNode** adjacencyList;


    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjacencyList = new GraphNode * [numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjacencyList[i] = nullptr;
        }
    }

    void addEdge(int source, int destination, int cost) {
        GraphNode* newNode = new GraphNode(source, destination, cost);
        GraphNode* newNode1 = new GraphNode(destination, source, cost);
        newNode->next = adjacencyList[source];
        adjacencyList[source] = newNode;
        newNode1->next = adjacencyList[destination];
        adjacencyList[destination] = newNode1;
    }

    int GetnumVertices() {
        return numVertices;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            GraphNode* temp = adjacencyList[i];
            while (temp != nullptr) {
                cout << temp->destination << "(" << temp->cost << ")" << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

void dijkstra(int startVertex, int endVertex, Graph g,bool question) {

    queue<Vertex> pq;

    vector<int> distances(g.GetnumVertices(), INT_MAX);
    vector<int> parent(g.GetnumVertices(), -1);
    vector<bool> visited(g.GetnumVertices(), false);
    Vertex w;
    distances[startVertex] = 0;
    w.distanceFromStart = 0;
    w.vertexNumber = startVertex;
    pq.push(w);

    while (!pq.empty()) {

        int u = pq.front().vertexNumber;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        GraphNode* temp = g.adjacencyList[u];
        while (temp != nullptr) {
            int v = temp->destination;
            int cost = temp->cost;

            if (distances[u] != INT_MAX && distances[u] + cost < distances[v]) {
                distances[v] = distances[u] + cost;
                parent[v] = u;
                Vertex tmp;
                tmp.distanceFromStart = distances[v];
                tmp.vertexNumber = v;
                pq.push(tmp);
            }

            temp = temp->next;
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
