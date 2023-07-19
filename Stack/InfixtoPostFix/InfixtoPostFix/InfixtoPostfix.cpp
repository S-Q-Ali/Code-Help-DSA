#include<iostream>
using namespace std;

template <class T>
class Stack
{
protected:
	T* arr;
	int maxsize;
	int StackTop;
public:
	Stack()
	{
		maxsize = 0;
		StackTop = -1;
		arr = new T[maxsize];
	}

	Stack(int s)
	{
		maxsize = s;
		StackTop = -1;
		arr = new T[maxsize];
	}

	Stack(const Stack& obj)
	{
		if (this != &obj)
		{
			maxsize = obj.maxsize;
			StackTop = obj.StackTop;
			arr = new T[maxsize];
			for (int i = 0; i <= StackTop; i++)
			{
				arr[i] = obj.arr[i];
			}
		}
	}

	~Stack()
	{
		delete[] arr;
	}

	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual void push(T) = 0;
	virtual T pop() = 0;
	virtual T Top() = 0;
};

template <class T>
class Conversion :public Stack<T>
{
	char* infix;
	char* postfix;
public:
	Conversion(int s) : Stack<char>(s)
	{
		infix = new char[s];
		postfix = new char[s];
	}

	int Precedence(char op1, char op2)
	{
		if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-'))
			return false;
		else if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
			return true;
		else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
			return false;
		else
			return true;
	}

	bool Alphabatically(char a)
	{
		if (a >= 'a'&&a <= 'z' || a >= 'A'&&a <= 'Z')
		{
			return true;
		}
		else {
			return false;
		}
	}

	void inputinfix()
	{
		cout << "Enter the Infix: ";
		cin >> infix;
	}

	void Displayinfix()
	{
		cout << "The Infix is: " << infix << endl;
	}

	void Displaypostfix()
	{
		cout << "The Postfix is: " << postfix << endl;
	}

	void push(T v)
	{
		if (Stack<T>::StackTop == Stack<T>::maxsize - 1)
		{
			cout << "OverFlow...\n";
			return;
		}
		Stack<T>::StackTop++;
		Stack<T>::arr[Stack<T>::StackTop] = v;
	}

	T pop()
	{
		if (Stack<T>::StackTop == -1)
		{
			cout << "BelowFlow...\n";
		}
		T temp = Stack<T>::arr[Stack<T>::StackTop];
		Stack<T>::StackTop--;
		return temp;
	}

	T Top()
	{
		return Stack<T>::arr[Stack<T>::StackTop];
	}

	bool isEmpty() const override {
		return Stack<T>::StackTop == -1;
	}

	bool isFull() const override {
		return Stack<T>::StackTop == Stack<T>::maxsize - 1;
	}

	void infixToPostfix()
	{
		int i = 0;
		int j = 0;
		char a, b;

		postfix = new char[strlen(infix) + 1];

		while ((a = infix[i++]) != '\0')
		{
			if (Alphabatically(a))
			{
				postfix[j++] = a;
			}
			else if (a == '(')
			{
				push(a);
			}
			else if (a == ')')
			{
				while (Stack<T>::arr[Stack<T>::StackTop] != '(' && !isEmpty())
				{
					postfix[j++] = pop();
				}
				if (Stack<T>::arr[Stack<T>::StackTop] == '(')
				{
					pop();
				}
			}
			else
			{
				while (Precedence(a, Stack<T>::arr[Stack<T>::StackTop]) && !isEmpty())
				{
					postfix[j++] = pop();
				}
				push(a);
			}

		}

		while (!isEmpty())
		{
			postfix[j++] = pop();
		}
		postfix[j] = '\0';
	}
};

int main()
{
	Conversion<char>C(5);
	C.inputinfix();
	C.Displayinfix();
	C.infixToPostfix();
	C.Displaypostfix();

	system("pause");
	return 0;
}