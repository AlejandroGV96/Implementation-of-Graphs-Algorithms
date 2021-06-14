#pragma once
#include"myGraph.hpp"

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

	std::cout << "------------STACK TEST--------------" << std::endl;
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

	std::cout << "------------QUEUE TEST--------------" << std::endl;
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

	std::cout << "------------GRAPH TEST--------------" << std::endl;
	Graph graphTest(6);
	graphTest.addEdge(0, 1);
	graphTest.addEdge(0, 2);
	graphTest.addEdge(1, 2);
	graphTest.addEdge(1, 3);
	graphTest.addEdge(2, 3);
	graphTest.addEdge(2, 4);
	graphTest.addEdge(3, 4);
	graphTest.addEdge(3, 5);
	graphTest.addEdge(4, 5);
	graphTest.BFS(3);
	
}