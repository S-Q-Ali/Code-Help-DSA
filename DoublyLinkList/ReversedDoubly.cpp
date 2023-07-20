#include<iostream>
 using namespace std;

  class Node{
  	int data;
  	Node* next;
     Node* prev;

   public:
  	Node()
	{
		//empty
	} 
 	void setData(int d){data = d;}
 	void setNext(Node* n){next = n;}
 	void setPrev(Node* n){prev = n;}

 	int getData(){return data;}
 	Node* getNext(){return next;}
 	Node* getPrev(){return prev;}
 	~Node()
	{
		//empty
	}
  };

  class List{
   int size;
   Node* head, *tail;		

  public: 
   List()
   {
    head = new Node();
    head -> setNext(NULL);
    head -> setPrev(NULL);
    tail = head;
    size = 0;
    }

    ~List()
	{
		delete head;
    } 

   void addNode(int value)
   {
    Node* newNode = new Node ();
    newNode -> setData (value);
    newNode -> setNext (NULL); 

    newNode -> setPrev(tail);
    tail -> setNext(newNode);
    tail = newNode;
    size++;
   }

   void displayList()
    {
    	Node* temp = head -> getNext();
     while(temp != NULL)
       {
       cout<<temp->getData()<<" ";
       temp = temp->getNext();
      }
    cout<<endl;
  }

  void displayReverse()
    {
    	Node* temp = tail;
     while(temp != head)
       {
       cout<<temp->getData()<<" ";
       temp = temp->getPrev();
      }
    cout<<endl;
  }

    void modifyList(int n, int v)
    {
    	Node* temp;
    	temp = head->getNext();
     int i = 1;
     cout<<"List Modified: ";
 	while(i++ < n)
         temp = temp->getNext();
     temp->setData(v);
    }

    int countList()
	{
		return size;
	}
  };

 int main()
 {
   List L1;
   L1.addNode(5);
   cout << "The Node is Added!" << endl;
   L1.displayList();
   cout << "The Node is Added!" << endl;
   L1.addNode(10);
   L1.displayList();
   cout << "The List is Reversed!" << endl;
   L1.displayReverse();
   cout << "The Node is Added!" << endl;
   L1.addNode(15);
   L1.displayList();
   cout << "The List is Reversed!" << endl;
   L1.displayReverse();
   L1.modifyList(2,50);
   L1.displayList();
   cout << "The List is Reversed!" << endl;
   L1.displayReverse();

   system("pause");
  return 0;	
  }