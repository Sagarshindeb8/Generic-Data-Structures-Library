//Singly Linear Linked List in C++ (OOP - Generic)

#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
};

typedef struct node node;
typedef struct node *Pnode;
typedef struct node **PPnode;

template<class T>
class SinglyLL
{
	private:
		typedef struct node<T> *Head;
	public:
		SinglyLL();
		void Display();
		int Count();
		void InsertFirst(T no);				
		void InsertLast(T no);			
		void InsertAtPos(T no, int ipos);				
		void DeleteFirst();		
		void DeleteLast();		
		void DeleteAtPos(int ipos);		
};

template<class T>
SinglyLL<T>::SinglyLL()
{
	Head = NULL;
}

template<class T>
void SinglyLL<T>::Display()
{
	struct node<T> *temp = Head;
	while(temp != NULL)
	{
		cout<<"|"<<temp -> data<<"| -> ";
		temp = temp -> next;
	}	
	cout<<"NULL"<<endl;
}

template<class T>
int SinglyLL<T>::Count()
{
	struct node<T> *temp = Head;
	int iCnt = 0;
	while(temp != NULL)
	{
		iCnt++;
		temp = temp -> next;
	}
	return iCnt;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;
	newn = new node;
	newn -> data = no;
	newn -> next = NULL;
	
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{		
		newn -> next = Head;
		Head = newn;
	}	
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;
	newn -> data = no;
	newn -> next = NULL;
	
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{		
		struct node<T> *temp = Head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}	
}

template<class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
	int iSize = 0;
	iSize = Count();
	
	if((iPos < 1)||(iPos > (iSize+1)))
	{
		cout<<"Invalid position"<<endl;
		return;
	}
	else if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == (iSize+1))
	{
		InsertLast(no);
	}
	else
	{	
		struct node<T> *newn = NULL;
		newn = new node<T>;
		newn -> data = no;
		newn -> next = NULL;
		
		int iCnt = 0;
		struct node<T> *temp = Head;
		for(iCnt=1;iCnt<(iPos-1);iCnt++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next = newn;		
	}
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
	if(Head == NULL)
	{
		return;
	}
	else
	{
		struct node<T> *temp = Head;
		Head = temp -> next;
		delete temp;
	}
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
	if(Head == NULL)
	{
		return;
	}
	else if(Head -> next == NULL)
	{
		delete(Head);
		Head = NULL;
	}
	else
	{
		struct node<T> *temp = Head;
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		delete(temp -> next);
		temp -> next = NULL;
	}
}

template<class T>
void SinglyLL::DeleteAtPos(int iPos)
{
	int iSize = 0;
	iSize = Count();
	
	if((iPos < 1)||(iPos > iSize))
	{
		cout<<"Invalid position"<<endl;
		return;
	}
	else if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{			
		int iCnt = 0;
		struct node<T> *temp = Head;
		struct node<T> *tempdelete = NULL;
		for(iCnt=1;iCnt<(iPos-1);iCnt++)
		{
			temp = temp -> next;
		}
		tempdelete = temp -> next;
		temp -> next = temp -> next -> next;
		delete tempdelete;		
	}
}

int main()
{
	SinglyLL<T>obj;
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