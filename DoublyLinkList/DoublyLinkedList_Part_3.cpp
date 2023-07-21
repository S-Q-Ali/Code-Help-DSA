#include<iostream>
using namespace std;
class node{
	int data;
	node* next;
	node* prev;

public:
	node()
	{
		//empty
	}
	void setdata(int d)
	{
		data = d;
	}
	void setnext(node* n)
	{
		next = n;
	}
	void setprev(node* n)
	{
		prev = n;
	}

	int getdata()
	{
		return data;
	}
	node* getnext()
	{
		return next;
	}
	node* getprev()
	{
		return prev;
	}
	~node()
	{
		//empty 
	}
};

class list
{
	int size;
	node* head, *tail;

public:
	list()
	{
		head = new node();
		head->setnext(nullptr);
		head->setprev(nullptr);
		tail = head;
		size = 0;
	}

	~list()
	{
		delete head;
	}

	void addnode(int value)
	{
		node* newnode = new node();
		newnode->setdata(value);
		newnode->setnext(nullptr);
		newnode->setprev(tail);
		tail->setnext(newnode);
		tail = newnode;
		size++;
	}

	void displaylist()
	{
		node* temp = head->getnext();
		while (temp != nullptr)
		{
			cout << temp->getdata() << " ";
			temp = temp->getnext();
		}
		cout << endl;
	}

	void displayreverse()
	{
		node* temp = tail;
		while (temp != head)
		{
			cout << temp->getdata() << " ";
			temp = temp->getprev();
		}
		cout << endl;
	}

	int searchnode(int key)
	{
		node* temp = head->getnext();
		int i = 1;
		while (temp != nullptr)
		{
			if (temp->getdata() == key)
				return i;
			temp = temp->getnext();
			i++;
		}
		return -1;
	}

	void sortlist()
	{
		node* temp1, *temp2;
		for (int i = 1; i <= size; i++)
		{
			temp1 = head;
			temp2 = head->getnext();
			for (int j = 1; j <= size - 1; j++)
			{
				temp1 = temp1->getnext();
				temp2 = temp2->getnext();
				if (temp1->getdata() > temp2->getdata())
				{
					int temp = temp1->getdata();
					temp1->setdata(temp2->getdata());
					temp2->setdata(temp);
				}
			}
		}
	}

	int countlist()
	{
		return size;
	}
};

int main()
{
	list l1;
	l1.addnode(15);
	cout << "The Node has added!" << endl;
	cout << "The List has: ";
	l1.displaylist();
	l1.addnode(5);
	cout << "The Node has added!" << endl;
	cout << "The List has: ";
	l1.displaylist();
	l1.addnode(20);
	cout << "The Node has added!" << endl;
	cout << "The List has: ";
	l1.displaylist();
	l1.addnode(10);
	cout << "The Node has added!" << endl;
	cout << "The List has: ";
	l1.displaylist();
	int index = l1.searchnode(20);
	if (index != -1)
	{
		cout << "value found in node :" << index << endl;
	}
	else
	{
		cout << "value not found." << endl;
	}

	l1.addnode(12);
	cout << "The Node has added!" << endl;
	cout << "The List has: ";
	l1.displaylist();

	l1.sortlist();
	cout << "The list contains: ";
	l1.displaylist();

	system("pause");
	return 0;
}