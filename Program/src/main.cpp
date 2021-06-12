#include<iostream>
#include"mystack.cpp"

int main() {
	Stack<int> x;
	for (int i = 0; i < 5; i++)
	{
		x.push(i);
	}
	x.display();
	std::cout << x.peek() << std::endl;
	x.pop();
	x.display();
}