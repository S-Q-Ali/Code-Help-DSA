#include<iostream>
using namespace std;

template<class T>

class Cqueue{
	int size;
	int count;
	T *qPointer;
	int front;
	int rear;
public:
	/*Cqueue(int);
	~Cqueue(){ delete[] qPointer; }
	void enQueue(T);
	T deQueue();
	int isempty();
	int isfull();
	void display();
*/
	//template<class T>
	Cqueue(int s)
	{
		qPointer = new T[s];
		size = s;
		front = 0;
		count = 0;
		rear = 0;
	}
	

	//template<class T>
	int isempty()
	{
		return (rear == front ? 1 : 0);
	}
	//template<class T>
	int isfull() 
	{
		return ((rear + 1) % size == front ? 1 : 0); 
	}

	//template<class T>
	void enQueue(T i)
	{
		if (count == size)
			cout << "Queue is full\n";
		else
		{
			cout << "Count :" << count << " Front :" << front << " Rear :" << rear << endl;

			qPointer[rear] = i;
			rear = (rear + 1) % size;
			count = count + 1;
		}
	}

	//template<class T>
	T deQueue()
	{
		if (count == 0)
			cout << "Queue is empty\n";
		else
		{
			cout << "Count :" << count << " Front :" << front << " Rear :" << rear << endl;
			cout << "Number Deleted = " << qPointer[front] << endl;
			front = (front + 1) % size;
			count = count - 1;
		}
		return count;
	}
	//template<class T>
	void display()
	{

		if (count == 0)
			cout << "Queue is empty\n";
		else
		{
			cout << "Count :" << count << " Front :" << front << " Rear :" << rear << endl;
			int x = front;
			for (int i = 1; i <= count; i++)
			{
				cout << qPointer[x] << " ";
				x = (x + 1) % size;

			}
			cout << endl;
		}
	}

};


int main(){
	int length;
	cout << "Enter the queue size :"; cin >> length;
	Cqueue <int>q(length);
	q.isempty();
	q.enQueue(5);
	q.display();
	q.enQueue(10);
	q.display();
	q.enQueue(15);
	q.display();

	q.deQueue();
	q.display();
	q.enQueue(20);
	q.display();
	q.enQueue(25);
	q.display();
	q.deQueue();
	q.display();
	q.enQueue(25);
	q.display();


	Cqueue <char>p(length);
	
	p.enQueue('A');
	p.enQueue('E');
	p.enQueue('I');
	p.display();
	p.deQueue();
	p.display();

	system("pause");
	return 0;
}
