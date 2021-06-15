#pragma once
#include"myGraph.hpp"
#include"myStack.hpp"
#include"myQueue.hpp"

struct test {
	int x, y;
	test() :x{NULL}, y{NULL} {};
	test(int x, int y) :x(x), y(y) {};

	friend std::ostream& operator<<(std::ostream& os, const test& tst);
	test(int) :x{ NULL }, y{ NULL } {};
};

std::ostream& operator<<(std::ostream& os, const test& tst)
{
	os << "{" << tst.x << ", " << tst.y << "}";
	return os;
}

int main() {

	std::cout << "\n------------STACK TEST--------------" << std::endl;
	Stack<test> stackTest;
	for (int i = 0; i < 10; i++)
	{
		stackTest.push({i,i});
	}
	std::cout << stackTest.peek() << std::endl;
	stackTest.display();
	std::cout << "Size: " << stackTest.size() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		stackTest.pop();
	}
	std::cout << stackTest.peek() << std::endl;
	stackTest.display();
	std::cout << "Size: " << stackTest.size() << std::endl;

	std::cout << "\n------------QUEUE TEST--------------" << std::endl;
	Queue<test> queueTest;
	for (int i = 0; i < 10; i++)
	{
		queueTest.push({ i,i });
	}
	std::cout << queueTest.peek() << std::endl;
	queueTest.display();
	std::cout << "Size: " << queueTest.size() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		queueTest.pop();
	}
	std::cout << queueTest.peek() << std::endl;
	queueTest.display();
	std::cout << "Size: " << queueTest.size() << std::endl;

	std::cout << "\n------------GRAPH TEST--------------" << std::endl;
	Graph graphTest(7);
	graphTest.addEdge(0, 1,1);
	graphTest.addEdge(0, 2,1);
	graphTest.addEdge(1, 3,1);
	graphTest.addEdge(1, 4,1);
	graphTest.addEdge(2, 5,1);
	graphTest.addEdge(2, 6,1);
	std::cout << "Depth First Search:	";
	graphTest.DFS(0);
	std::cout << "Breath First Search:	";
	graphTest.BFS(0);
	
	graphTest.Dijkstra(0);

}