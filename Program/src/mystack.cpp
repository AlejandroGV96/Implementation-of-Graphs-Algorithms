#include<iostream>

template<typename T>
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