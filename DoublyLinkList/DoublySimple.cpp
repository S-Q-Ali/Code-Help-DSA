#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node *prev;
public:

	Node()
	{
		//Empty
	}

	~Node()
	{
		//Empty
	}
};

class DoublyList
{
	int size;
	Node *head;
	Node *tail;
public:

	DoublyList()
	{
		size = 0;
		head = new Node();
		head->next = nullptr;
		head->prev = nullptr;
		tail = head;
	}

	~DoublyList()
	{
		delete head;
	}

	void addNode(int v)
	{
		Node*N = new Node();
		N->data = v;
		N->next = nullptr;
		N->prev = tail;
		tail->next = N;
		tail = N;
		size++;
	}

	void display()
	{
		Node*N = head->next;
		while (N != nullptr)
		{
			cout << N->data << endl;
			N = N->next;
		}
		cout << endl;
	}

	void ReverseList()
	{
		Node *N = tail;
		while (N != head)
		{
			cout << N->data << endl;
			N = N->prev;
		}
		cout << endl;
	}

	void ModifyList(int n, int v)
	{
		Node*N = head->next;
		int c = 1;
		while (++c < n)
		{
			N = N->next;
			N->data = v;
		}
	}
};

int main()
{
	DoublyList DL;
	DL.addNode(34);
	DL.addNode(14);
	DL.addNode(90);
	DL.display();
	DL.ReverseList();
	DL.ModifyList(3, 20);
	DL.display();





	system("pause");
	return 0;
}