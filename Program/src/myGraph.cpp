#include "myGraph.hpp"
#include "myQueue.hpp"
#include "myStack.hpp"


Graph::Graph(const int& vertices) :numVertices(vertices), adjLists(new std::vector<edge>[vertices]), vertList(new std::vector<vertex>[vertices]) {};
Graph::~Graph() {
    for (auto i = 0; i < numVertices; i++) {
        adjLists[i].clear();
        vertList[i].clear();
    }
    delete[] adjLists;
    delete[] vertList;
}

void Graph::addEdge(const int& src, const int& dest, const int& dist) {
    adjLists[src]. push_back({ src,dest,dist });
    adjLists[dest].push_back({ dest,src,dist });
}

void Graph::DFS(int currVertex)
{
    // Initially mark all verices as not visited
    std::vector<bool> visited(numVertices, false);

    // Create a stack for DFS
    Stack stack;

    // Push the current source node.
    stack.push(currVertex);

    while (!stack.isEmpty())
    {
        // Pop a vertex from stack and print it
        currVertex = stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[currVertex])
        {
            std::cout << "Visited " << currVertex << " ";
            visited[currVertex] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
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
    std::vector<int> distFromVrtx(numVertices, INT_MAX);
    std::vector<bool> visitedVrtx(numVertices, false);
    std::vector<edge>* shortestPaths = new std::vector<edge>[numVertices];
    //shortestPath->push_back({ 1,2,3 });

    distFromVrtx[startVertex] = 0;
    visitedVrtx[startVertex] = true;
    auto& closestNode = adjLists[startVertex][0];
    for (int i = 0; i < numVertices; i++) {

        if (visitedVrtx[i]) continue;

        auto& closestNode = adjLists[i][0];
        for (auto& el : adjLists[i]) {
            distFromVrtx[el.dest] = el.dist;
            if (closestNode.dist > el.dist) closestNode = el;
        }
        visitedVrtx[closestNode.src] = true;
        shortestPaths[i].push_back(closestNode);
    }
    /*
    auto& closestNode = adjLists[startVertex][0];
    for (auto& el : adjLists[startVertex]) {
        distFromVrtx[el.dest] = el.dist;
        if (closestNode.dist > el.dist) closestNode = el;
    }
    visitedVrtx[closestNode.src] = true;
    shortestPaths[startVertex].push_back(closestNode);
    */

    for (auto el : distFromVrtx) {
        std::cout << el << ", ";
    }

}