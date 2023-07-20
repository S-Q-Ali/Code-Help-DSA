////#include<iostream>
////using namespace std;
////
////template<class T>
////class Cqueue{
////	int size;
////	int count;
////	T *qPointer;
////	int front;
////	int rear;
////public:
////	Cqueue(int);
////	~Cqueue(){ delete[] qPointer; }
////	void enQueue(T);
////	T deQueue();
////	bool isempty();
////	bool isfull();
////	void display();
////};
////
////template<class T>
////Cqueue<T>::Cqueue(int s){
////	qPointer = new T[s];
////	size = s;
////	front = 0; count = 0;
////	rear = 0;
////}
////
////template<class T>
////bool Cqueue<T>::isempty(){ return ( rear == front  ? 1 : 0);}
////template<class T>
////bool Cqueue<T>::isfull() { return ((rear+1)%size == front?1:0);}
////
////template<class T>
////void Cqueue<T>::enQueue(T i){
////	if (count == size)
////		cout << "Queue is full\n";
////	else
////	{
////		cout << "Count :" << count << " Front :" << front << " Rear :" << rear << endl;
////
////		qPointer[rear] = i;
////		rear = (rear + 1) % size;
////		count = count + 1;
////	}
////}
////
////template<class T>
////T Cqueue<T>::deQueue(){
////	if (count == 0)
////		cout << "Queue is empty\n";
////	else
////	{
////		cout << "Count :" << count << " Front :" << front << " Rear :" << rear << endl;
////		cout << "Number Deleted = " << qPointer[front] << endl;
////		front = (front + 1) % size;
////		count = count - 1;
////		return qPointer[front];
////	}
////}
////template<class T>
////void Cqueue<T>::display(){
////
////	if (count == 0)
////		cout << "Queue is empty\n";
////	else
////	{
////		cout << "Count :" << count << " Front :" << front << " Rear :" << rear << endl;
////		int x = front;
////		for (int i = 1; i <= count; i++)
////		{
////			cout << qPointer[x] << " ";
////			x = (x + 1) % size;
////
////		}
////		cout << endl;
////	}
////}
////
////
////int main(){
////	int length;
////	cout << "Enter the queue size :"; cin >> length;
////	Cqueue <int>q(length);
////
////	q.enQueue(5);
////	q.display();
////	q.enQueue(10);
////	q.display();
////	q.enQueue(15);
////	q.display();
////
////	q.deQueue();
////	q.display();
////	q.enQueue(20);
////	q.display();
////	q.enQueue(25);
////	q.display();
////	q.deQueue();
////	q.display();
////	q.enQueue(25);
////	q.display();
////
////
////	//Cqueue <char>p(length);
////	//
////	//p.enQueue('A');
////	//p.enQueue('E');
////	//p.enQueue('I');
////	//p.display();
////	//p.deQueue();
////	//p.display();
////	system("pause");
////	return 0;
////}
//
//
//#include<iostream>
//using namespace std;
//
//#include <iostream>
//using namespace std;
//
//template<class T>
//class CircularQueue
//{
//protected:
//	T* qPointer;
//	int size;
//	int front;
//	int rear;
//public:
//	CircularQueue(int s)
//	{
//		qPointer = new T[s];
//		size = s;
//		front = 0;
//		rear = 0;
//	}
//
//	~CircularQueue()
//	{
//		if (qPointer)
//		{
//			delete[] qPointer;
//		}
//	}
//
//	bool isEmpty()
//	{
//		return (front == rear);
//	}
//
//	bool isFull()
//	{
//		return ((rear + 1) % size == front);
//	}
//
//	void enQueue(T e)
//	{
//		if (!isFull())
//		{
//			qPointer[rear] = e;
//			rear = (rear + 1) % size;
//			cout << "Enqueued element: " << e << endl;
//		}
//		else
//		{
//			cout << "Queue is Full!" << endl;
//		}
//	}
//
//	T deQueue()
//	{
//		if (!isEmpty())
//		{
//			T dequeuedElement = qPointer[front];
//			front = (front + 1) % size;
//			cout << "Dequeued element: " << dequeuedElement << endl;
//			return dequeuedElement;
//		}
//		else
//		{
//			cout << "Queue is Empty!" << endl;
//			return -1;
//		}
//	}
//
//	void display()
//	{
//		if (isEmpty())
//		{
//			cout << "The Queue is Empty!" << endl;
//		}
//		else
//		{
//			cout << "The Queue has:" << endl;
//			while (front != rear)
//			{
//				cout << "\t\t" << qPointer[front] << " at " << front + 1 << endl << endl;
//				front = (front + 1) % size;
//			}
//		}
//	}
//};
//
//int main()
//{
//	int len = 0;
//	cout << "Enter the Length of the Circular Queue: ";
//	cin >> len;
//	CircularQueue<int> CQ(len);
//
//	int value,choice=0;
//
//	do
//	{
//		cout << "To enQueue a Number Press 1.\n" << "To deQueue a Number Press 2.\n" << "To Check Wether Queue is Full Press 3.\n" << "To Check Wether Queue is Empty Press 4.\n" << "To Display the Circular Queue Press 5.\n" << "To Exit Press 6" << endl;
//		cout << "Enter Your Choice: ";
//		cin >> choice;
//		if (choice == 1)
//		{
//			cout << "Enter the Value: ";
//			cin >> value;
//			CQ.enQueue(value);
//		}
//		else if (choice == 2)
//		{
//			CQ.deQueue();
//		}
//		else if (choice == 3)
//		{
//			cout << CQ.isFull() << endl;
//		}
//		else if (choice == 4)
//		{
//			cout << CQ.isEmpty() << endl;
//		}
//		else if (choice == 5)
//		{
//			CQ.display();
//		}
//	} while (choice != 6);
//
//
//
//
//
//
//
//
//
//	system("pause");
//	return 0;
//}