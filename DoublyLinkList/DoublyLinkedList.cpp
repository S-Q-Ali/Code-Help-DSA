#include<iostream>
using namespace std;

class Node
{
public:
	Node *next;
	Node* prev;
	int data;

	Node(int d)
	{
		data = d;
	}

	~Node()
	{
		//empty
	}
};

class DoublyList
{
public:

	virtual void insertAtFront(int) = 0;
	virtual void insertAtEnd(int) = 0;
	virtual void insertNext(int Nodevalue, int) = 0;
	virtual void insertSorted(int) = 0;
	virtual void sortLinkedList() = 0;
	virtual int removeFromFront() = 0;
	virtual int removeNext() = 0;
	virtual void removeFromEnd() = 0;
};

class MyDoublyList :public DoublyList
{
private:
	Node* head;

public:
	MyDoublyList() : head(nullptr) {}

	bool isEmpty() {
		return (head == nullptr);
	}

	int sizeOfList() {
		Node* N = head;
		int count = 0;

		while (N != nullptr) {
			count++;
			N = N->next;
		}

		return count;
	}

	void insertAtFront(int value) {
		Node* newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void insertAtEnd(int value) {
		Node* newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* N = head;

			while (N->next != nullptr) {
				N = N->next;
			}

			N->next = newNode;
			newNode->prev = N;
		}
	}

	void insertNext(int existingValue, int value) {
		Node* N = head;

		while (N != nullptr) {
			if (N->data == existingValue) {
				Node* newNode = new Node(value);

				newNode->prev = N;
				newNode->next = N->next;

				if (N->next != nullptr) {
					N->next->prev = newNode;
				}

				N->next = newNode;
				return;
			}
			N = N->next;
		}

		cout << "Existing node not found." << endl;
	}

	void insertSorted(int value) {
		Node* newNode = new Node(value);

		if (head == nullptr || value <= head->data) {
			newNode->next = head;

			if (head != nullptr) {
				head->prev = newNode;
			}

			head = newNode;
		}
		else {
			Node* N = head;

			while (N->next != nullptr && value > N->next->data) {
				N = N->next;
			}

			newNode->prev = N;
			newNode->next = N->next;

			if (N->next != nullptr) {
				N->next->prev = newNode;
			}

			N->next = newNode;
		}
	}

	void sortLinkedList()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}

		bool swapped;
		Node* N;

		do {
			swapped = false;
			N = head;

			while (N->next != nullptr) {
				if (N->data > N->next->data) {
					int temp = N->data;
					N->data = N->next->data;
					N->next->data = temp;
					swapped = true;
				}
				N = N->next;
			}
		} while (swapped);
	}

	int removeFromFront() {
		if (head == nullptr) {
			cout << "The list is empty." << endl;
			return -1;
		}

		Node* front = head;

		if (head->next != nullptr) {
			head = head->next;
			head->prev = nullptr;
		}
		else {
			head = nullptr;
		}

		int removedValue = front->data;
		delete front;
		return removedValue;
	}

	int removeNext()
	{
		if (head == nullptr || head->next == nullptr)
		{
			cout << "Invalid node or no node to delete." << endl;
			return -1;
		}

		Node* temp = head->next;
		head->next = temp->next;

		if (temp->next != nullptr)
		{
			temp->next->prev = head;
		}

		int deletedValue = temp->data;
		delete temp;
		return deletedValue;
	}

	void removeFromEnd() {
		if (head == nullptr) {
			cout << "The list is empty." << endl;
			return;
		}

		Node* N = head;

		while (N->next != nullptr) {
			N = N->next;
		}

		if (N->prev != nullptr) {
			N->prev->next = nullptr;
		}
		else {
			head = nullptr;
		}

		delete N;
	}

	void display() {
		Node* N = head;

		while (N != nullptr) {
			cout << N->data << " ";
			N = N->next;
		}

		cout << endl;
	}

};

class MyList
{
	Node *tail;

public:

	MyList()
	{
		tail = nullptr;
	}

	bool isEmpty()
	{
		return (tail == nullptr ? 1 : 0);
	}
	int sizeOfList()
	{
		Node*N = tail;
		int c = 0;
		while (N != nullptr)
		{
			N = N->next;
			c++;
		}
		return c;
	}

	void insertAtFront(int v)
	{
		Node*N = new Node(v);
		if (tail == nullptr)
		{
			tail = N;
		}
		else
		{
			N->prev = tail;
			tail->next = N;
			tail = N;
		}
	}

	void insertAtEnd(int v)
	{
		Node* N = new Node(v);
		if (tail == nullptr)
		{
			tail = N;
		}
		else
		{
			N->prev = tail;
			tail->next = N;
			tail = N;
		}
	}

	void insertNext(int existingValue, int value)
	{
		Node* temp = tail;

		while (temp != nullptr)
		{
			if (temp->data == existingValue)
			{
				Node* newNode = new Node(value);

				newNode->next = temp->next;
				newNode->prev = temp;
				temp->next = newNode;

				if (newNode->next != nullptr)
				{
					newNode->next->prev = newNode;
				}
				else
				{
					tail = newNode;
				}

				return;
			}
			temp = temp->prev;
		}

		cout << "Existing node not found." << endl;
	}

	void insertSorted(int value)
	{
		Node* newNode = new Node(value);

		if (tail == nullptr)
		{
			tail = newNode;
		}
		else if (value <= tail->data)
		{
			newNode->next = tail;
			tail->prev = newNode;
			tail = newNode;
		}
		else
		{
			Node* N = tail;

			while (N->prev != nullptr && N->prev->data < value)
			{
				N = N->prev;
			}

			newNode->prev = N->prev;
			newNode->next = N;
			N->prev = newNode;

			if (newNode->prev != nullptr)
			{
				newNode->prev->next = newNode;
			}
			else
			{
				tail = newNode;
			}
		}
	}

	void sortLinkedList()
	{
		if (tail == nullptr || tail->prev == nullptr)
		{
			return;
		}

		Node* N = tail;

		while (N->prev != nullptr)
		{
			if (N->data < N->prev->data)
			{
				int temp = N->data;
				N->data = N->prev->data;
				N->prev->data = temp;
				N = tail;
			}
			else
			{
				N = N->prev;
			}
		}
	}

	void removeFromFront()
	{
		if (tail == nullptr)
		{
			cout << "The list is empty." << endl;
			return;
		}

		Node* front = tail;
		while (front->prev != nullptr)
		{
			front = front->prev;
		}

		if (front->next != nullptr)
		{
			front->next->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}

		delete front;
	}

	void removeNext(Node* node)
	{
		if (node == nullptr || node->next == nullptr)
		{
			cout << "Invalid node or no node to delete." << endl;
			return;
		}

		Node* temp = node->next;
		node->next = temp->next;

		if (temp->next != nullptr)
		{
			temp->next->prev = node;
		}

		delete temp;
	}

	void removeFromEnd()
	{
		if (tail == nullptr)
		{
			cout << "The list is empty." << endl;
			return;
		}

		Node* nodeToDelete = tail;

		if (tail->prev != nullptr)
		{
			tail = tail->prev;
			tail->next = nullptr;
		}
		else
		{
			tail = nullptr;
		}

		delete nodeToDelete;
	}

	void display()
	{
		Node* N = tail;
		while (N != nullptr)
		{
			cout << N->data << " ";
			N = N->prev;
		}
		cout << endl;
	}
};



int main()
{
	MyList T;
	cout << "Inserted at End Successfully!" << endl;
	T.insertAtEnd(9);
	T.display();
	cout << "Inserted at Front Successfully!" << endl;
	T.insertAtFront(3);
	T.display();
	cout << "Inserted at Front Successfully!" << endl;
	T.insertAtFront(4);
	T.display();
	cout << "Inserted at Next Successfully!" << endl;
	T.insertNext(3, 54);
	T.display();
	MyDoublyList H;
	H.insertAtEnd(90);
	cout << "Inserted at End Successfully!" << endl;
	H.display();
	H.insertAtFront(10);
	cout << "Inserted at Front Successfully!" << endl;
	H.display();
	H.insertNext(3, 67);
	cout << "Inserted at Next Successfully!" << endl;
	H.display();
	cout << "Inserted Sorted Successfully!" << endl;
	H.insertSorted(13);
	H.display();




	system("pause");
	return 0;
}