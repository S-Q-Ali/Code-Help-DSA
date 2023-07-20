#include<iostream>
using namespace std;

template<class T>

class queue{
	int size;
	T *qPointer;
	int front;
	int rear;
public:
	queue(int);
	~queue(){ delete[] qPointer; }
	void enQueue(T);
	T deQueue();
	int isempty();
	int isfull();
	void display();
};

template<class T>
queue<T>::queue(int s){
	qPointer = new T[s];
	size = s;
	front = 0;
	rear = 0;
}

template<class T>
int queue<T>::isempty(){ return (front == rear ? 1 : 0); }
template<class T>
int queue<T>::isfull() { return (rear == size ? 1 : 0); }

template<class T>
void queue<T>::enQueue(T i){
	if (!isfull()){
		cout << " Front = " << front << " ... " << " Rear = " << rear << " ... ";
		cout << "Enqueuing " << i << endl;
		qPointer[rear] = i;
		rear++;
		cout << "The value has been added Successfully." << endl;
	}
	else
		cout << "Queue is FULL!!! No insertion allowed further.";
}
template<class T>
T queue<T>::deQueue(){
	if (!isempty()){
		cout << " Front = " << front << " ... " << " Rear = " << rear << " ... ";
		cout << "DeQueuing " << qPointer[front] << endl;
		cout << "The value has been deQueued Successfully." << endl;
		return(qPointer[front++]);
		//top;
	}
	else
		cout << "Queue Empty!!! Value returned will be garbage.";

	return -1;
}
template<class T>
void queue<T>::display(){
	if (!isempty()){
		for (int i = front; i<rear; i++){
			cout << " Position = " << i + 1 << " ... ";
			cout << "Value = " << qPointer[i] << endl;
		}
	}
	else
		cout << "Queue is empty!!";
}


int main(){
	int length;
	cout << "Enter the queue size :"; cin >> length;
	queue <int>q(length);

	q.enQueue(5);
	q.enQueue(10);
	q.enQueue(15);
	q.display();
	q.deQueue();
	q.display();

	queue <char>p(length);

	p.enQueue('A');
	p.enQueue('E');
	p.enQueue('I');
	p.display();
	p.deQueue();
	p.display();

	system("pause");
	return 0;
}
