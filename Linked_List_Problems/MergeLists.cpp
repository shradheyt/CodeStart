#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node *next;
}*head1=NULL,*head2=NULL;;

struct Node* createNode(int x)
{
	struct Node* newptr=new struct Node;
	newptr->data=x;
	newptr->next=NULL;
	return newptr;
}

struct Node* insertLast(struct Node* head,int x)
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

struct Node* mergeLists()
{
	struct Node* newNode=new Node;
	struct Node* ptr;
	newNode->next=NULL;
	ptr=newNode;
	
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<=head2->data)
		{
			ptr->next=head1;
			ptr=ptr->next;
			head1=head1->next;
		}
		else
		{
			ptr->next=head2;
			ptr=ptr->next;
			head2=head2->next;
		}
		
	}
		if(head1!=NULL)
		{
			ptr->next=head1;
		}
		else
			ptr->next=head2;
			
			ptr=newNode->next;
			delete newNode;
			
			return ptr;
	
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
	
	head1=insertLast(head1,3);
	head1=insertLast(head1,5);
	head1=insertLast(head1,12);
	head1=insertLast(head1,15);
	head1=insertLast(head1,20);
	head1=insertLast(head1,23);
	display(head1);
	cout<<endl;
	head2=insertLast(head2,1);
	head2=insertLast(head2,2);
	head2=insertLast(head2,9);
	head2=insertLast(head2,14);
	head2=insertLast(head2,21);
	head2=insertLast(head2,25);
       display(head2);
	cout<<endl;
	cout<<"After merging:"<<endl;
	struct Node* newhead;
	newhead=mergeLists();
	display(newhead);
	
	
	
	
	
}
