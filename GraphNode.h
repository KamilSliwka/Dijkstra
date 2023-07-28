//
// Created by kamil on 28.07.2023.
//

#ifndef DIJKSTRA_GRAPHNODE_H
#define DIJKSTRA_GRAPHNODE_H


class GraphNode {
private:
    int source;
    int destination;
    int cost;
    GraphNode* next;
public:
    GraphNode(int source, int destination, int cost);

    int getSource() const;

    void setSource(int source);

    int getDestination() const;

    void setDestination(int destination);

    int getCost() const;

    void setCost(int cost);

    GraphNode *getNext() const;

    void setNext(GraphNode *next);
};


#endif //DIJKSTRA_GRAPHNODE_H
