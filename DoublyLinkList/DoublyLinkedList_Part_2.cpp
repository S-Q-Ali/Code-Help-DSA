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
    head -> setnext(nullptr);
    head -> setprev(nullptr);
    tail = head;
    size = 0;
    }

    ~list()
	{
    delete head; 
     } 

   void addnode(int value)
   {
    node* newnode = new node ();
    newnode -> setdata (value);
    newnode -> setnext (nullptr); 
    newnode -> setprev(tail);
    tail -> setnext(newnode);
    tail = newnode;
    size++;
   }

   void displaylist()
    {
    	node* temp = head -> getnext();
     while(temp != nullptr)
       {
       cout<<temp->getdata()<<" ";
       temp = temp->getnext();
      }
    cout<<endl;
  }

   void displayreverse()
    {
    	node* temp = tail;
     while(temp != head)
       {
       cout<<temp->getdata()<<" "; 
       temp = temp->getprev(); 
      }
    cout<<endl;
  }
  
   void insertnode(int p, int v)
   {
	node* temp = head;
     int i = 1;
 	while(i++ < p)
         temp = temp->getnext();

 	node* newnode = new node();
 	newnode->setdata(v);

     if (p != size+1)
	 {
 	  	newnode->setnext(temp->getnext());
 	    newnode->setprev(temp);
 	   (temp -> getnext())-> setprev(newnode);
 	   	temp->setnext(newnode);
     }
 	else
	{
 	   newnode->setnext(nullptr); 
 	   newnode->setprev(temp); 
 	   temp->setnext(newnode);
 	   tail = newnode;
 	  } 
 	size++;
   }

   void deletenode(int p)
    {
 	node* temp1 = head;
 	node* temp2 = head->getnext();
     int i = 1;
 	while(i++ < p)
	{
		temp1 = temp1->getnext();
		temp2 = temp2->getnext();
	}
	if (p != size)
	{
		temp1->setnext(temp2->getnext());
		(temp2->getnext())->setprev(temp1);
	}
	else
	{
		temp1->setnext(temp2->getnext());
		tail = temp1;
	}
	delete temp2;
	size--;
    }

    int countlist()
	{
		return size;
	}
  };

 int main(){
   list l1;
   l1.addnode(5);
   cout << "The Node is Added!" << endl;
   cout << "The List has: ";
   l1.displaylist();
   cout << "The Reversed List is: ";
   l1.displayreverse();
   cout << "The Node is Added!" << endl;
   l1.addnode(10);
   cout << "The List has: ";
   l1.displaylist();
   cout << "The Reversed List is: ";
   l1.displayreverse();
   l1.addnode(15);
   cout << "The Node is Added!" << endl;
   cout << "The List has: ";
   l1.displaylist();
   cout << "The Reversed List is: ";
   l1.displayreverse();
   l1.insertnode(3,50);
   cout << "The Node is Inserted!" << endl;
   cout << "The List has: ";
   l1.displaylist();
   cout << "The Reversed List is: ";
   l1.displayreverse();
   l1.insertnode(1,500);
   cout << "The Node is inserted!" << endl;
   cout << "The List has: ";
   l1.displaylist();
   cout << "The Reversed List is: ";
   l1.displayreverse();
   l1.insertnode(1,1000);
   cout << "The Node is inserted!" << endl;
   cout << "The List has: ";
   l1.displaylist();
   cout << "The Reversed List is: ";
   l1.displayreverse();
   l1.deletenode(3);
   cout << "The Node is Deleted!" << endl;
   l1.displaylist();

   system("pause");
  return 0;	
}