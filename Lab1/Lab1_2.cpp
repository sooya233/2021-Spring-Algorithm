#include <iostream>
using namespace std;

class Stack1
{
private:
	int *stack;
	int p;
public:
	Stack1(int max = 100)
	{
		stack = new int[max]; p = 0;
	}
	~Stack1()
	{
		delete stack;
	}
	inline void push(int v)
	{
		stack[p++] = v;
	}
	inline int pop()
	{
		return stack[--p];
	}
	inline int empty()
	{
		return !p;
	}
};

int main()
{
	char c;
	Stack1 acc(50);
	int x;
	while ((c = cin.get()) != '\n')
	{
		x = 0;
		//다음 글자를 받기 위한 구분자
		while (c == ' ')
		{
			cin.get(c);
		}
		if (c == '+') x = acc.pop() + acc.pop();
		if (c == '*') x = acc.pop() * acc.pop();
		//형변환
		while (c >= '0' && c <= '9')
		{
			x = 10 * x + (c - '0');
			cin.get(c);
		}
		acc.push(x);
	}
	cout << acc.pop() << '\n';
}
