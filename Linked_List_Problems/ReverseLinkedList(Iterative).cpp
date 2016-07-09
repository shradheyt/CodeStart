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

struct Node* reverseList(struct Node *head)
{
	struct Node *curr,*prev,*next;
	curr=head;
	prev=NULL;
	next=NULL;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
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
	display(head);
	cout<<endl;
	newhead=reverseList(head);
	display(newhead);
	
	
	
	
}
