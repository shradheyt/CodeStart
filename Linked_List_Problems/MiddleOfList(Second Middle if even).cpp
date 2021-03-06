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


int middleOfList()
{
	struct Node *slow,*fast;
	slow=head;
	fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow->data;
}

void display(struct Node* head)
{
	
	struct Node* ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"-->";
		ptr=ptr->next;
	}
}

int main()
{
	
	head=insertLast(3);
	head=insertLast(5);
	head=insertLast(23);
	head=insertLast(9);
	head=insertLast(2);
	head=insertLast(3);
	display(head);
	cout<<endl;
	cout<<middleOfList();
	
	
	
	
	
}
