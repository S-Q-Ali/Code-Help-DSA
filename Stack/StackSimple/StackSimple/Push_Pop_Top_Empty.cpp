#include<iostream>
using namespace std;

template<class t>

class stack
{
protected:
	t* stackarr;
	int maxsize;
	int stacktop;
public:

	stack()
	{
		stackarr = new t[maxsize];
		maxsize = 0;
		stacktop = 0;
	}

	stack(int m)
	{
		maxsize = m;
		stackarr = new t[maxsize];
		stacktop = 0;
	}

	~stack()
	{
		if (stackarr)
		{
			delete[]stackarr;
			cout << "destructor is called!" << endl;
		}
	}

	virtual void push(t) = 0;
	virtual t pop()=0;
	virtual t top() = 0;
	virtual int size() = 0;
	virtual void display()=0;
};

template<class t>

class mystack:public stack<t>
{
public:

	mystack() :stack<t>{}

	mystack(int m) :stack<t>(m)
	{
		maxsize = m;
	}

	bool isempty()
	{
		return (stacktop == 0);
	}

	bool isfull()
	{
		return (stacktop >= maxsize);
	}

	void push(t p)
	{
		if (!isfull())
		{
			stackarr[stacktop++] = p;
		}
		else
		{
			cout << "stack is full!" << endl;
		}
	}

	t pop()
	{
		if (!isempty())
		{
			return stackarr[--stacktop];
		}
		else
		{
			cout << "stack is empty!" << endl;
			return -1;
		}

	}

	t top()
	{
		if (!isempty())
		{
			return stackarr[stacktop - 1];
		}
		else
		{
			cout << "stack is empty!" << endl;
			return -1;
		}
	}

	int size()
	{
		return maxsize;
	}

	void display()
	{
		cout << "the stack has : " << endl;
		for (int i = 0; i < stacktop; i++)
		{
			cout << stackarr[i] << " at " << i + 1 << endl;
		}
	}
};

int main()
{
	int len ,value= 0;
	char select = '\0';
	cout << "enter the length of the stack: ";
	cin >> len;
	mystack<int>ms(len);

	do {
		cout << "press 1 to add a new item to the stack" << endl;
		cout << "press 2 to remove and return the last element from the stack" << endl;
		cout << "press 3 to check if the stack is full" << endl;
		cout << "press 4 to check if the stack is empty" << endl;
		cout << "press 5 to return the size of the stack" << endl;
		cout << "press 6 to display the stack" << endl;
		cout << "enter 7 for displaying top: " << endl;
		cout << "press 0 to exit" << endl;
		cout << "enter the selecton: ";
		cin >> select;
		if (select == '1')
		{
			cout << "enter the value: ";
			cin >> value;
			ms.push(value);
		}
		else if (select == '2')
		{
			ms.pop();
		}
		else if (select == '3')
		{
			cout << ms.isfull() << endl;
		}
		else if (select == '4')
		{
			cout << ms.isempty() << endl;
		}
		else if (select == '5')
		{
			cout << ms.size() << endl;
		}
		else if (select == '6')
		{
			ms.display();
			cout << endl;
		}
		else if (select == '7')
		{
			cout << ms.top();
			cout << endl;
		}
	} while (select != '0');
				





	system("pause");
	return 0;
}