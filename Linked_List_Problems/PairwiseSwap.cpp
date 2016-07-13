#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node *next;
}*head=NULL;

struct Node* createNode(int x)
{
	struct Node* newptr=new struct Node;
	newptr->data=x;
	newptr->next=NULL;
	return newptr;
}

struct Node* insertLast(int x)
{
	if(head==NULL)
	{
		struct Node *newNode=createNode(x);
		head=newNode;
	}
	else
	{
		struct Node* ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=createNode(x);
	}
	return head;
}
int len=0;

void pairWiseSwap()
{
	struct Node* curr=head->next;
	struct Node* prev=head;
	head=curr;
	if(head==NULL||head->next==NULL)
	{
		return;
	}
	
	while(true)
	{
		struct Node* next=curr->next;
		curr->next=prev;
		
		if(next==NULL||next->next==NULL)
		{
			prev->next=next;
			break;
		}
		prev->next=next->next;
		prev=next;
		curr=prev->next;
		
	}
}

void display(struct Node* head)
{
	
	struct Node* ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"-->";
		ptr=ptr->next;
		len++;
	}
}

int main()
{
	struct Node* newhead=NULL;
	head=insertLast(3);
	head=insertLast(5);
	head=insertLast(1);
	head=insertLast(9);
	head=insertLast(2);
//	head=insertLast(7);
	display(head);
	cout<<endl;
	pairWiseSwap();
	display(head);
	
	
	
	
}
