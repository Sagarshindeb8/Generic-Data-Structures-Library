//Singly Circular Linked List in C++ (OOP - Generic)

#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node<T> *next;
};

template<class T>
class SinglyCLL
{
	private:	//Characteristics
		struct node<T> *Head;
		struct node<T> *Tail;
	
	public:		//Behaviours
		SinglyCLL();
		void InsertFirst(T no);				
		void InsertLast(T no);			
		void InsertAtPos(T no, int ipos);				
		void DeleteFirst();		
		void DeleteLast();		
		void DeleteAtPos(int ipos);		
		void Display();		
		int Count();		
};


template<class T>
SinglyCLL<T>::SinglyCLL()
{
	Head = NULL;
	Tail = NULL;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;
	
	newn = new node<T>;	//Dynamic Memory allocation
	
	newn -> data = no;
	newn -> next = NULL;
	
	if((Head == NULL) && (Tail == NULL))	//To check if LL is empty
	{
		Head = newn;
		Tail = newn;
	}
	else	//If LL contains atleast one node
	{
		newn -> next = Head;
		Head = newn;
	}
	Tail -> next = Head;
}


template<class T>	
void SinglyCLL<T>::InsertLast(T no)
{
	struct node<T> * newn = NULL;
	
	newn = new node<T>;	//Dynamic Memory allocation
	
	newn -> data = no;
	newn -> next = NULL;
	
	if((Head == NULL) && (Tail == NULL))	//To check if LL is empty
	{
		Head = newn;
		Tail = newn;
	}
	else	//If LL contains atleast one node
	{
		Tail -> next = newn;
		Tail = newn;
	}
	Tail -> next = Head;
}


template<class T>
void SinglyCLL<T>::InsertAtPos(T no, int ipos)
{
	int iSize = Count();
	
	if((ipos < 1) || (ipos > (iSize+1)))
	{
		cout<<"Invalid Position\n";
		return;
	}
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	if(ipos == (iSize + 1))
	{
		InsertLast(no);
	}
	else
	{
		struct node<T> *newn = NULL;
	
		newn = new node<T>;	//Dynamic Memory allocation
	
		newn -> data = no;
		newn -> next = NULL;
		
		struct node<T> *temp = Head;
		int iCnt = 0;
		
		for(iCnt=1;iCnt<(ipos-1);iCnt++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next = newn;
	}
}	


template<class T>
void SinglyCLL<T>::DeleteFirst()
{
	if(Head == NULL && Tail == NULL)	//If LL is empty
	{
		return;
	}
	else if(Head == Tail)	//If LL contains 1 node
	{
		delete Head; // Or delete Tail;
		Head = NULL;
		Tail = NULL;
	}
	else	//If LL contains more than 1 node
	{
		Head = Head -> next;
		delete Tail -> next;
		
		Tail -> next = Head;
	}
}	


template<class T>
void SinglyCLL<T>::DeleteLast()
{
	if(Head == NULL && Tail == NULL)	//If LL is empty
	{
		return;
	}
	else if(Head == Tail)	//If LL contains 1 node
	{
		delete Head; // Or delete Tail;
		Head = NULL;
		Tail = NULL;
	}
	else	//If LL contains more than 1 node
	{
		struct node<T> *temp = Head;
		
		while(temp -> next != Tail)
		{
			temp = temp -> next;
		}
		delete Tail; //Or delete temp -> next
		Tail = temp;
		
		Tail -> next = Head;
	}
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
	int iSize = Count();
	
	if((ipos < 1) || (ipos > iSize))
	{
		cout<<"Invalid Position\n";
		return;
	}
	if(ipos == 1)
	{
		DeleteFirst();
	}
	if(ipos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp1 = Head;
		int iCnt = 0;
		
		for(iCnt=1;iCnt<(ipos-1);iCnt++)
		{
			temp1 = temp1 -> next;
		}
		
		struct node<T> *temp2 = temp1 -> next;
		temp1 -> next = temp2 -> next;
		delete temp2;
	}
}


template<class T>	
void SinglyCLL<T>::Display()
{
	struct node<T> *temp = Head;
	
	if(Head == NULL && Tail == NULL)	//If LL is empty
	{
		return;
	}
	
	if(Head == NULL && Tail == NULL) //If LL is empty
	{
		return;
	}
	do
	{
		cout<<"|"<<temp -> data<<"|->";
		temp = temp -> next;
	}while(temp != Head);	
	
	cout<<endl;
}	


template<class T>	
int SinglyCLL<T>::Count()
{	
	struct node<T> *temp = Head;
	int iCnt = 0;
	
	if(Head == NULL && Tail == NULL) //If LL is empty
	{
		return 0;
	}
	do
	{
		iCnt++;
		temp = temp -> next;
	}while(temp != Head);
	
	return iCnt;
}	

int main()
{
	SinglyCLL <int>obj;
	int iRet = 0;
	
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	
	obj.InsertLast(101);
	obj.InsertLast(111);
	obj.InsertLast(121);
	obj.InsertLast(151);
	obj.InsertLast(201);
	
	obj.Display();
	iRet = obj.Count();
	
	cout<<"Number of nodes are: "<<iRet<<endl;
	
	obj.InsertAtPos(75,4);
	
	//obj.DeleteFirst();
	//obj.DeleteLast();
	
	obj.Display();
	iRet = obj.Count();
	
	cout<<"Number of nodes are: "<<iRet<<endl;
	
    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;
	return 0;
}