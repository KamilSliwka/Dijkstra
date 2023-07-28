cmake_minimum_required(VERSION 3.24)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 17)

add_executable(Dijkstra main.cpp Vertex.h Vertex.cpp GraphNode.cpp GraphNode.h Graph.cpp Graph.h)
