#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node *next;
}*head=NULL;


struct Node* StartOfLoop()
{
	bool isCycle=false;
	struct Node* slowptr=head;
	struct Node* fastptr=head;
	
	while(slowptr!=NULL && fastptr!=NULL && fastptr->next!=NULL)
	{
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;
		
		if(slowptr==fastptr)
		{
			isCycle=true;
			break;
		}
	}
	
	
	if(isCycle)
	{
		slowptr=head;
		
		while(slowptr!=fastptr)
		{
			slowptr=slowptr->next;
			fastptr=fastptr->next;
		}
		return slowptr;
	}
	return NULL;
	
}

int main()
{
	struct Node* n[7];
	for(int i=0;i<7;i++)
	{
		 n[i]=new Node;
	}
	head=n[0];
	n[0]->data=5;
	n[0]->next=n[1];
	
	n[1]->data=5;
	n[1]->next=n[2];
	
	n[2]->data=5;
	n[2]->next=n[3];
	
	n[3]->data=5;
	n[3]->next=n[4];
	
	n[4]->data=5;
	n[4]->next=n[5];
	
	n[5]->data=5;
	n[5]->next=n[6];
	
	n[6]->data=5;
	n[6]->next=n[3];  //Cycle
	//n[6]->next=NULL;  //NoCycle
	
	struct Node *start;
	start=StartOfLoop();
	cout<<start->data;
	
}
