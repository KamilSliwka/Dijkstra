//
// Created by kamil on 28.07.2023.
//
#include "Vertex.h"
int Vertex::getDistanceFromStart() const {
    return distanceFromStart;
}

int Vertex::getVertexNumber() const {
    return vertexNumber;
}

void Vertex::setVertexNumber(int vertexNumber) {
    Vertex::vertexNumber = vertexNumber;
}

void Vertex::setDistanceFromStart(int distanceFromStart) {
    Vertex::distanceFromStart = distanceFromStart;
}


