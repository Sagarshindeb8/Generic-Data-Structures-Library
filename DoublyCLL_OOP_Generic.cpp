//Doubly Circular Linked List in C++ (OOP - Generic)

#include<iostream>
using namespace std;

template <class T>
struct node
{
	T data;
	struct node<T> *next;
	struct node<T> *prev;
};

template <class T>
class DoublyCLL
{
		private:
			struct node<T> *Head;
			struct node<T> *Tail;
			
			int CountNode; //For counting the struct node<T>*s
		
		public:	
			DoublyCLL(); //Constructor
		//Function declarations	
			void InsertFirst(T no);
			void InsertLast(T no);
			void InsertAtPos(T no, int iPos);			
			void DeleteFirst();
			void DeleteLast();
			void DeleteAtPos(int iPos);			
			int Count();
			void Display();
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
	Head = NULL;
	Tail = NULL;
	CountNode = 0;
}


template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;
	
	newn = new node<T>;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(CountNode == 0) //if(Head==NULL) && (Tail==NULL)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn -> next = Head;
		Head -> prev = newn;
		Head = newn;
	}
	
	Head -> prev = Tail;
	Tail -> next = Head;
	
	CountNode++;
}


template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
	struct node<T> *newn = NULL;
	
	newn = new node<T>;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(CountNode == 0) //if(Head==NULL) && (Tail==NULL)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail -> next = newn;
		newn -> prev = Tail;
		
		Tail = newn;
	}
	
	Head -> prev = Tail;
	Tail -> next = Head;
	
	CountNode++;
}


template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int iPos)
{
	if((iPos < 1) || (iPos > CountNode+1))
	{
		cout<<"Invalid Position\n";
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == CountNode+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node<T> *newn = NULL;
		
		newn = new node<T>;
		
		newn -> data = no;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		struct node<T> *temp = Head;
		
		for(int i=1;i<(iPos-1);i++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		temp -> next -> prev = newn;
		temp -> next = newn;
		newn -> prev = temp;
		
		CountNode++;
	}
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
	if(CountNode == 0)
	{
		return;
	}
	else if(CountNode == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Head = Head -> next;
		delete Tail -> next; //delete Head -> prev;
	}
	
	Head -> prev = Tail;
	Tail -> next = Head;
	
	CountNode--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
		if(CountNode == 0)
	{
		return;
	}
	else if(CountNode == 1)
	{
		delete Tail;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Tail = Tail -> prev;
		delete Tail -> next; //delete Head -> prev;
	}
	
	Head -> prev = Tail;
	Tail -> next = Head;
	
	CountNode--;
}


template <class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
	if((iPos < 1) || (iPos > CountNode))
	{
		cout<<"Invalid Position\n";
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == CountNode)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp = Head;
		
		for(int i=1;i<(iPos-1);i++)
		{
			temp = temp -> next;
		}
		
		temp -> next = temp -> next -> next;
		delete temp -> next -> prev;
		temp -> next -> prev = temp;
		
		CountNode--;
	}
}

template <class T>
void DoublyCLL<T>::Display()
{
	int i = 0;
	struct node<T> *temp = Head;
	
	for(i=1;i<=CountNode;i++)
	{
		cout<<"|"<<temp -> data<<"|->";
		temp = temp -> next;
	}
	cout<<"\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
	return CountNode;
}

int main()
{
	DoublyCLL <int>obj;
	
	int iRet = 0;
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(101);
	obj.InsertLast(121);
	obj.Display();
	iRet = obj.Count();	
	cout<<"Number of nodes are: "<<iRet<<endl;
	
	obj.InsertAtPos(31,3);
	obj.Display();
	iRet = obj.Count();	
	cout<<"Number of nodes are: "<<iRet<<endl;
	
	obj.DeleteFirst();
	obj.Display();
	iRet = obj.Count();	
	cout<<"Number of nodes are: "<<iRet<<endl;
	
	obj.DeleteLast();
	obj.Display();
	iRet = obj.Count();	
	cout<<"Number of nodes are: "<<iRet<<endl;
	
	obj.DeleteAtPos(3);
	obj.Display();
	iRet = obj.Count();	
	cout<<"Number of nodes are: "<<iRet<<endl;
	
	return 0;
}

