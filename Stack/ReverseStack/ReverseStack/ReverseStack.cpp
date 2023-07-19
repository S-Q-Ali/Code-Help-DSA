#include<iostream>
using namespace std;
template<class T>
class stack
{
protected:
	T * arr;
	int currentSize;
	int maxSize;
public:
	stack()
	{
		currentSize = 0;
		maxSize = 10;
		arr = new T[maxSize];
	}
	stack(int m)
	{
		currentSize = 0;
		maxSize = m;
		arr = new T[maxSize];
	}
	virtual void push(T) = 0;
	virtual T pop() = 0;
	virtual void top() = 0;
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
};
template<class T>
class myStack : public stack<T>
{
public:
	myStack() :stack()
	{
	}
	myStack(int m) :stack(m)
	{
	}
	void push(T v)
	{
		arr[currentSize] = v;
		currentSize++;
	}
	T pop()
	{
		T x = arr[--currentSize];
		return x;
	}
	void top()
	{
		int t = currentSize;
		cout << arr[--t];
	}
	bool isFull()
	{
		return currentSize == maxSize;
	}
	bool isEmpty()
	{
		return currentSize == 0;
	}
	void display()
	{
		for (int i = 0; i < currentSize; i++)
		{
			cout << arr[i] << " ";
		}
	}
};
int main()
{
	myStack <char>s(6);
	s.push('[');
	s.push('{');
	s.push('(');
	s.push(')');
	s.push('}');
	s.push(']');
	myStack <char>s1(6);
	s1.push(s.pop());
	s1.push(s.pop());
	s1.push(s.pop());
	s1.push(s.pop());
	s1.push(s.pop());
	s1.push(s.pop());
	for (int i = 0; i < 6; i++)
	{
		cout << s1.pop() << " ";
	}
	cout << endl;
	system("pause");
}