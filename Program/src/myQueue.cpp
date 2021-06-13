#include<iostream>

template<typename T>
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