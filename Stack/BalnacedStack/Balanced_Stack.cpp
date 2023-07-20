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
		arr[currentSize++] = v;
	}
	T pop()
	{
		return arr[--currentSize];
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
	s.push(']');              // change any character to check answer
	char arr[6];
	for (int i = 0; i < 6; i++)
	{
		arr[i] = s.pop();
	}
	int check = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = i; j < 6; j++)
		{
			if (arr[i] == arr[j])
			{
				check++;
			}
		}
	}
	if (check == 6)
	{
		cout << "Balanced...\n";
	}
	else
	{
		cout << "Unbalanced...\n";
	}
	system("pause");
	return 0;
}
