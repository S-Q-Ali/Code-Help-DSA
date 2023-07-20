#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
	T Data;
	Node<T> *Next;

	Node(T Data) : Data(Data), Next(nullptr) {}
};

template<class T>
class List
{
public:
	virtual void insertAtFront(T value) = 0;
	virtual void insertAtEnd(T value) = 0;
	virtual void insertNext(T Nvalue, T value) = 0;
	virtual void insertSorted(T value) = 0;
	virtual void sortLinkedList() = 0;
	virtual T removeFromFront() = 0;
	virtual T removeNext(T Nvalue) = 0;
	virtual void removeFromEnd() = 0;
};

template<class T>
class MyList : public List<T>
{
private:
	Node<T> *head;

public:
	MyList() : head(nullptr) {}

	bool isEmpty()
	{
		return (head == nullptr);
	}

	int sizeOfList()
	{
		int count = 0;
		Node<T> *current = head;
		while (current != nullptr)
		{
			count++;
			current = current->Next;
		}
		return count;
	}

	void insertAtFront(T v)
	{
		Node<T>* New = new Node<T>(v);
		New->Next = head;
		head = New;
	}

	void insertAtEnd(T v)
	{
		Node<T>*temp = new Node<T>(v);
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			Node<T> *N = head;
			while (N->Next != NULL)
			{
				N = N->Next;
			}
			N->Next = temp;
		}
	}

	void insertNext(T Nvalue, T value)
	{
		Node<T> *current = head;
		while (current != nullptr && current->Data != Nvalue)
		{
			current = current->Next;
		}

		if (current == nullptr)
		{
			cout << "Node " << Nvalue << " not found." << endl;
			return;
		}

		Node<T> *newNode = new Node<T>(value);
		newNode->Next = current->Next;
		current->Next = newNode;
	}

	void insertSorted(T value)
	{
		Node<T> *newNode = new Node<T>(value);

		if (head == nullptr || value <= head->Data)
		{
			newNode->Next = head;
			head = newNode;
			return;
		}

		Node<T> *current = head;
		while (current->Next != nullptr && current->Next->Data < value)
		{
			current = current->Next;
		}

		newNode->Next = current->Next;
		current->Next = newNode;
	}

	void sortLinkedList()
	{
		if (head == nullptr || head->Next == nullptr)
		{
			return;
		}

		T temp;
		for (Node<T> *current = head; current != nullptr; current = current->Next)
		{
			for (Node<T> *Index = head; Index != nullptr; Index = Index->Next)
			{
				if (Index->Data > current->Data)
				{
					temp = Index->Data;
					Index->Data = current->Data;
					current->Data = temp;
				}
			}
		}
	}

	T removeFromFront()
	{
		if (isEmpty())
		{
			cout << "List is empty." << endl;
			return T();

		}

		Node<T> *temp = head;
		T value = temp->Data;
		head = head->Next;
		delete temp;
		return value;
	}

	T removeNext(T Nvalue)
	{
		Node<T> *current = head;
		while (current != nullptr && current->Data != Nvalue)
		{
			current = current->Next;
		}

		if (current == nullptr || current->Next == nullptr)
		{
			cout << "Next node not found" << endl;
			return T();
		}

		Node<T> *temp = current->Next;
		current->Next = temp->Next;
		T value = temp->Data;
		delete temp;
		return value;
	}

	void removeFromEnd()
	{
		if (isEmpty())
		{
			cout << "Empty." << endl;
			return;
		}

		if (head->Next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node<T> *current = head;
		while (current->Next->Next != nullptr)
		{
			current = current->Next;
		}

		delete current->Next;
		current->Next = nullptr;
	}
	void display()
	{
		Node<T> *current = head;
		cout << "Data in list is : ";
		while (current != nullptr)
		{
			cout << current->Data << " ";
			current = current->Next;
		}
		cout << endl;
	}
};

int main()
{
	MyList<int> myList;
	myList.insertAtEnd(1);
	myList.insertAtEnd(5);
	myList.insertAtEnd(8);
	myList.insertAtEnd(9);
	myList.insertAtFront(20);
	cout << "Size of list : " << myList.sizeOfList() << endl;
	myList.display();

	myList.insertNext(9, 10);
	cout << "The Value is Inserted at the Next Successfully!" << endl;
	myList.display();
	myList.insertNext(5, 10);
	cout << "The Value is Inserted at the Next Successfully!" << endl;
	myList.display();
	myList.insertSorted(2);
	cout << "The Value is Inserted Sorted Successfully!" << endl;
	myList.display();
	myList.insertSorted(6);
	cout << "The Value is Inserted Sorted Successfully!" << endl;
	myList.display();
	cout << "The List is now Sorted Successfully!" << endl;
	myList.sortLinkedList();
	myList.display();

	cout << "Removed from front : " << myList.removeFromFront() << endl;
	cout << "Removed next to the given node : " << myList.removeNext(9) << endl;
	myList.display();

	myList.removeFromEnd();
	cout << "Size of list : " << myList.sizeOfList() << endl;
	myList.display();

	system("pause");
	return 0;
}

