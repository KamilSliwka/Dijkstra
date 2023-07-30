#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"

using namespace std;

bool isConnection(int cost){
    if(cost!=0){
        return true;
    }
    return false;
}

int main() {
    int numberOfVertex;
    cout<<"enter the size of the matrix: "<<endl;
    cin>>numberOfVertex;
    getchar();
    Graph graph(numberOfVertex);
    char x;
    cout<<"enter a matrix of only values between 0 and 9: "<<endl;
    for(int i = 0;i < numberOfVertex;i++){
        for(int j = 0;j < numberOfVertex;j++){
            cin.get(x);
            int cost =(int)x-48;
            if(isConnection(cost)){
                graph.addEdge(i,j,cost);
            }
        }
    }
    cout<<"select the starting vertex of only values between 0 and "<<numberOfVertex-1<<": "<<endl;
    int startVertex;
    cin>>startVertex;
    cout<<"select the ending vertex of only values between 0 and "<<numberOfVertex-1<<": "<<endl;
    int endVertex;
    cin>>endVertex;
    Dijkstra algorithm(startVertex,endVertex,graph,true);
    algorithm.findShortestPath();

    return 0;
}
