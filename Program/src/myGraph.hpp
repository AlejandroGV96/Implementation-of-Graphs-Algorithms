#pragma once

#include <vector>
#include<iostream>

struct edge
{
    edge(int e_src, int e_dest, int e_dist = INT_MAX) : src(e_src), dest(e_dest), dist(e_dist) {};
    int src;
    int dest;
    int dist;
    friend std::ostream& operator<<(std::ostream& os, const edge& edge) {
        os << "{" << edge.src << ", " << edge.dest << ", " << edge.dist << "}";
        return os;
    }
};

class Graph {
private:
    int numVertices;
    std::vector<std::vector<edge>> adjLists;

public:
    Graph(const int& vertices);
    void addEdge(const int& src, const int& dest, const int& dist);
    void DFS(int vertex);
    void BFS(const int& startVertex);
    void Dijkstra(const int& startVertex);

};


