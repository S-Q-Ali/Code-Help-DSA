#include <iostream>
using namespace std;

class node
{
public:
	char* data;
	int value;
	node* next;

	node(const char* data, int value)
	{
		int length = strlen(data);
		this->data = new char[length + 1];
		strcpy_s(this->data, length + 1, data);
		this->value = value;
		next = nullptr;
	}

	~node()
	{
		delete[] data;
	}
};

class linkedlist
{
public:
	node* head;

	linkedlist()
	{
		head = nullptr;
	}

	void addnode(const char* str, int value)
	{
		node* newnode = new node(str, value);

		if (head == nullptr)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	bool match(const char* a, const char*b)
	{
		if (strlen(a) == strlen(b))
		{
			for (int i = 0; i < strlen(a) + 1; i++)
			if (a[i] != b[i])
			{
				return false;
			}
			return true;
		}
		else
			return false;
	}
	int comparefirstletter(const char* a, const char* b)
	{
		char firstlettera = a[0];
		char firstletterb = b[0];

		if (firstlettera < firstletterb)
		{
			return -1;
		}
		else if (firstlettera > firstletterb)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void removeduplicatesandsort()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}

		node* temp = nullptr;

		for (node* current = head; current != nullptr; current = current->next)
		{
			for (node* index = current; index->next != nullptr;)
			{
				if (match(current->data, index->next->data))
				{
					temp = index->next;
					index->next = temp->next;
					delete temp;
				}
				else
				{
					index = index->next;
				}
			}
		}

		bool swapped;
		node* current;
		node* nextnode = nullptr;

		for (node* i = head; i->next != nextnode; i = i->next)
		{
			swapped = false;
			current = head;

			for (node* j = head; j->next != nextnode; j = j->next)
			{
				if (j->data[0] > j->next->data[0])
				{
					char* tempdata = j->data;
					int tempvalue = j->value;
					j->data = j->next->data;
					j->value = j->next->value;
					j->next->data = tempdata;
					j->next->value = tempvalue;
					swapped = true;
				}
				current = current->next;
			}
			nextnode = current;

			if (!swapped)
			{
				break;
			}
		}
	}




	void display()
	{
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			cout << temp->data << ": " << temp->value << endl;
		}
	}

	~linkedlist()
	{
		node* current = head;
		while (current != nullptr)
		{
			node* nextnode = current->next;
			delete current;
			current = nextnode;
		}
	}
};

int main()
{
	linkedlist list;

	list.addnode("babar azam", 100);
	list.addnode("azam", 200);
	list.addnode("babar", 44);
	list.addnode("babar azam", 100);

	list.display();
	cout << endl;
	list.removeduplicatesandsort();
	list.display();

	cout << endl;

	list.addnode("Messi", 10);
	list.addnode("Ramos", 2);
	list.addnode("Nsymar", 4);
	list.addnode("Ronaldo", 990);

	list.display();
	cout << endl;
	list.removeduplicatesandsort();
	list.display();

	system("pause");
	return 0;
}