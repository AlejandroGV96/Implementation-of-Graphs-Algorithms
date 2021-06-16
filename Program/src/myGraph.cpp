#include <list>
#include <algorithm>
#include "myGraph.hpp"
#include "myQueue.hpp"
#include "myStack.hpp"

Graph::Graph(const int& vertices) :numVertices(vertices), adjLists{vertices} {};

void Graph::addEdge(const int& src, const int& dest, const int& dist) {
    adjLists[src]. push_back({ src,dest,dist });
    adjLists[dest].push_back({ dest,src,dist });
}

void Graph::DFS(int currVertex)
{
    std::vector<bool> visited(numVertices, false);
    Stack stack;
    stack.push(currVertex);

    while (!stack.isEmpty())
    {
        currVertex = stack.pop();

        if (!visited[currVertex])
        {
            std::cout << "Visited " << currVertex << " ";
            visited[currVertex] = true;
        }


        for (int i = 0; i < adjLists[currVertex].size(); i++) {
            if (!visited[adjLists[currVertex][i].dest]) stack.push(adjLists[currVertex][i].dest);
        }
    }
    std::cout << std::endl;
}

void Graph::BFS(const int& startVertex) {
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    Queue queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.isEmpty()) {
        int currVertex = queue.front->data;
        std::cout << "Visited " << currVertex << " ";
        queue.pop();

        for (int i = 0; i < adjLists[currVertex].size(); i++) {
            int adjVertex = adjLists[currVertex][i].dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
    std::cout << std::endl;
    delete[] visited;
}

void Graph::Dijkstra(const int& startVertex) {

    int* dist = new int[numVertices];
    int* prev = new int[numVertices];

    for (int u = 0; u < numVertices; u++) {
        dist[u] = 10000000;
        prev[u] = -1;
    }

    dist[startVertex] = 0;
    std::list<int> queue;

    for (int u = 0; u < numVertices; u++) {
        queue.push_back(u);
    }

    while (!queue.empty()) {
        int u = *std::min_element(queue.begin(), queue.end());
        queue.remove(u);

        for (auto& el : adjLists[u]) {
            if ((dist[u] + (el.dist)) < dist[el.dest]) {
                dist[el.dest] = (dist[u] + (el.dist));
                prev[el.dest] = u;
            }
        }

    }
    for (int i = 0; i < numVertices; i++)
        if (i != startVertex)
            std::cout << "From " << startVertex << " to " << i << ", Cost: " << dist[i] << " Previous vertex: " << prev[i] << std::endl;
    delete[] dist;
    delete[] prev;
}