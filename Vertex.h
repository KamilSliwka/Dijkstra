//
// Created by kamil on 28.07.2023.
//

#ifndef DIJKSTRA_VERTEX_H
#define DIJKSTRA_VERTEX_H


class Vertex {
private:
    int vertexNumber;
    int distanceFromStart;
public:
    int getDistanceFromStart() const;

    int getVertexNumber() const;

    void setVertexNumber(int vertexNumber) ;

    void setDistanceFromStart(int distanceFromStart) ;
};


#endif //DIJKSTRA_VERTEX_H
