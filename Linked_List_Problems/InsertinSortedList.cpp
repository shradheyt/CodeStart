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


struct Node* insertSortedList(int key)
{
	struct Node *ptr=head,*prev;
	if(head==NULL)
	{
		head=createNode(key);
		return head;
	}
	if(head->data>key)
	{
		struct Node* newNode=createNode(key);
		newNode->next=head;
		head=newNode;
		return head;
	
	}
	else
	{
		while(ptr!=NULL&& ptr->data < key)
     	{
     		prev=ptr;
     		ptr=ptr->next;
     	}
     	struct Node* newNode=createNode(key);
     	newNode->next=ptr;
     	prev->next=newNode;
	}
	
     return head;
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
	head=insertLast(7);
	head=insertLast(9);
	head=insertLast(10);
	head=insertLast(13);
	display(head);
	cout<<endl;
	head=insertSortedList(15);
	display(head);
	
	
	
	
	
}
