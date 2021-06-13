#include<iostream>
#include"mystack.cpp"
#include"myQueue.cpp"

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
	
	Stack<test> stackTest;
	for (int i = 0; i < 10; i++)
	{
		stackTest.push({i,i});
	}
	std::cout << stackTest.peek() << std::endl;
	stackTest.display();
	for (int i = 0; i < 10; i++)
	{
		stackTest.pop();
	}
	std::cout << stackTest.peek() << std::endl;
	stackTest.display();
	
	Queue<test> queueTest;
	for (int i = 0; i < 10; i++)
	{
		queueTest.push({ i,i });
	}
	std::cout << queueTest.peek() << std::endl;
	queueTest.display();
	for (int i = 0; i < 10; i++)
	{
		queueTest.pop();
	}
	std::cout << queueTest.peek() << std::endl;
	queueTest.display();

}