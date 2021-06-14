#pragma once

#include <vector>
#include<iostream>

template<typename T = int>
class Stack {

private:
    struct Node {
        T data;
        std::shared_ptr<Node> next = nullptr;
        Node(const T& t) : data{ t } {}
    };
public:
    std::shared_ptr<Node> top;

    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(const T& val) {

        std::shared_ptr<Node> newNode = std::make_shared<Node>(val);
        newNode->data = val;
        newNode->next = nullptr;
        if (top != nullptr) {
            newNode->next = top;
        }
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            std::cout << ("Nothing to pop. The Stack is empty!\n");
            return;
        }
        std::shared_ptr<Node> tmp = top->next;
        top = tmp;
    }

    T peek() {
        if (isEmpty()) {
            std::cout << "Empty Stack-> ";
            return NULL;
        }
        else {
            return top->data;
        }
    }
    int size() {
        int count = 0;
        std::shared_ptr<Node> temp = top;
        while (temp.get() != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display() {
        if (top == nullptr) {
            std::cout << ("The Stack is empty!\n");
        }
        else {
            std::cout << "All values in the Stack are :\n";
            std::shared_ptr<Node> temp = top;
            while (temp.get() != nullptr) {
                std::cout << "(" << temp->data << ")" << " -> ";
                temp = temp->next;
            }
            std::cout << "End of Stack!\n";
        }
    }

};

template<typename T = int>
class Queue {

private:
    struct Node {
        T data;
        std::shared_ptr<Node> next = nullptr;
        Node(const T& t) : data{ t } {}
    };
public:
    std::shared_ptr<Node> rear;
    std::shared_ptr<Node> front;


    Queue() {
        rear = nullptr;
        front = nullptr;
    }

    bool isEmpty() {
        if (front == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(const T& val) {

        std::shared_ptr<Node> newNode = std::make_shared<Node>(val);
        if (rear)
        {
            rear->next = newNode;
        }
        rear = newNode;
        if (!front)
        {
            front = rear;
        }
    }

    void pop() {
        if (front == nullptr) {
            std::cout << ("Nothing to pop. The Stack is empty!\n");
            return;
        }
        std::shared_ptr<Node> tmp = front->next;
        front = tmp;
        if (!front)
        {
            rear = front;
        }
    }

    T peek() {
        if (isEmpty()) {
            std::cout << "Empty Stack-> ";
            return NULL;
        }
        else {
            return front->data;
        }
    }
    int size() {
        int count = 0;
        std::shared_ptr<Node> tmp = front;
        while (tmp.get() != nullptr) {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
    void display() {
        if (front == nullptr) {
            std::cout << ("The Queue is empty!\n");
        }
        else {
            std::cout << "All values in the Queue are :\n";
            std::shared_ptr<Node> temp = front;
            while (temp.get() != nullptr) {
                std::cout << "(" << temp->data << ")" << " -> ";
                temp = temp->next;
            }
            std::cout << "End of Queue!\n";
        }
    }

};

using namespace std;

class Graph {
    int numVertices;
    vector<int>* adjLists = nullptr;
    bool* visited = nullptr;

public:
    //Graph(int vertices);
    //void addEdge(int src, int dest);
    //void BFS(int startVertex);

// Create a graph with given vertices,
// and maintain an adjacency list
Graph(const int& vertices) {
    numVertices = vertices;
    adjLists = new vector<int>[vertices];//= new list<int>(vertices);//
}
~Graph() {
    for (auto i = 0; i < numVertices;i++) {
        adjLists[i].clear();
    }
    delete[] adjLists;
}

// Add edges to the graph
void addEdge(int src, int dest) {
    //cout << adjLists[src] << ", " << adjLists[dest]<< "\n";
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

// BFS algorithm
void BFS(int startVertex) {
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    Queue queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    vector<int>::iterator i;

    while (!queue.isEmpty()) {
        int currVertex = queue.front->data;
        cout << "Visited " << currVertex << " ";
        queue.pop();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
    delete[] visited;
}
};