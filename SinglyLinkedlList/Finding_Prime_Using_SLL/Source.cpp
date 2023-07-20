#include <iostream>
#include <fstream>
using namespace std;

class Node 
{
public:
	int data;
	Node* next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

class List
{
public:
	Node* head;

	List()
	{
		head = NULL;
	}

	void addNode(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}

	Node* findMinNode() 
	{
		Node* minNode = head;
		Node* current = head;
		while (current != NULL)
		{
			if (current->data < minNode->data)
			{
				minNode = current;
			}
			current = current->next;
		}
		return minNode;
	}

	List deletePrimeNodes() 
	{
		List primeNodes;
		Node* current = head;
		Node* prev = NULL;
		while (current != NULL) {
			if (isPrime(current->data))
			{
				if (prev == NULL)
				{
					head = current->next;
				}
				else
				{
					prev->next = current->next;
				}
				primeNodes.addNode(current->data);
			}
			else 
			{
				prev = current;
			}
			current = current->next;
		}
		return primeNodes;
	}

	bool isPrime(int n)
	{
		if (n < 2) 
		{
			return false;
		}
		for (int i = 2; i*i <= n; i++)
		{
			if (n % i == 0) 
			{
				return false;
			}
		}
		return true;
	}

	void concatenate(List& otherList)
	{
		if (head == NULL)
		{
			head = otherList.head;
		}
		else
		{
			Node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = otherList.head;
		}
		otherList.head = NULL;
	}

	void writeToFile(char* filename)
	{
		ofstream fout(filename);
		Node* current = head;
		while (current != NULL)
		{
			fout << current->data << " ";
			current = current->next;
		}
		fout.close();
	}

};

int main()
{
	List myList;
	ifstream fin("input.csv");
	int num;
	for (int i = 0; i < 50; i++) {
		fin >> num;
		myList.addNode(num);
	}
	fin.close();

	
	Node* minNode = myList.findMinNode();
	cout << "Minimum value: " << minNode->data << endl;
	cout << "Node address: " << minNode << endl;

	
	List primeNodes = myList.deletePrimeNodes();
	primeNodes.writeToFile("prime_numbers.csv");
	cout << endl;
	myList.writeToFile("no_prime_numbers.csv");
	cout << endl;


	myList.concatenate(primeNodes);
	myList.writeToFile("output.csv");

	system("pause");		
	return 0;
}