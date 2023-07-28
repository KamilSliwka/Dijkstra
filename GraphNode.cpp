//
// Created by kamil on 28.07.2023.
//

#include "GraphNode.h"

GraphNode::GraphNode(int source, int destination, int cost) {
    this->source = source;
    this->destination = destination;
    this->cost = cost;
    next = nullptr;
}

int GraphNode::getSource() const {
    return source;
}

void GraphNode::setSource(int source) {
    GraphNode::source = source;
}

int GraphNode::getDestination() const {
    return destination;
}

void GraphNode::setDestination(int destination) {
    GraphNode::destination = destination;
}

int GraphNode::getCost() const {
    return cost;
}

void GraphNode::setCost(int cost) {
    GraphNode::cost = cost;
}

GraphNode *GraphNode::getNext() const {
    return next;
}

void GraphNode::setNext(GraphNode *next) {
    GraphNode::next = next;
}
