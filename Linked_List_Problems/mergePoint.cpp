#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node *next;
}*head1=NULL,*head2=NULL;

int mergePoint(struct Node* head1,struct Node* head2)
{
	struct Node *ptr1,*ptr2;
	int L1=0,L2=0,diff;
	ptr1=head1;
	ptr2=head2;
	
	while(ptr1->next!=NULL)
	{
		L1++;							//calculating length of List 1
		ptr1=ptr1->next;
	}
	
	while(ptr2->next!=NULL)
	{
		L2++;								//calculating length of List 2
		ptr2=ptr2->next;
	}
	
	if(L1<L2)
	{
		diff=L2-L1;
		ptr2=head1;					//ptr2 points to bigger list
		ptr1=head2;
	}
	else
	{
		diff=L1-L2;
		ptr1=head1;   //ptr1 points to bigger list
		ptr2=head2;
	}
	
	for(int i=0;i<diff;i++)
	{
		ptr1=ptr1->next;
	}
	
	while(ptr1&&ptr2)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
		
		if(ptr1==ptr2)
		return ptr1->data;
	}
	return 0;
	
	
	
}

int main()
{
	struct Node* n[7];
	for(int i=0;i<7;i++)
	{
		 n[i]=new Node;
	}
	
	struct Node* n1[5];
	for(int i=0;i<5;i++)
	{
		n1[i]=new Node;
	}
	//LIST1
	head1=n[0];
	n[0]->data=5;
	n[0]->next=n[1];
	
	n[1]->data=4;
	n[1]->next=n[2];
	
	n[2]->data=2;
	n[2]->next=n[3];
	
	n[3]->data=7;
	n[3]->next=n[4];
	
	n[4]->data=9;
	n[4]->next=n[5];
	
	n[5]->data=2;
	n[5]->next=n[6];
	
	n[6]->data=5;
	n[6]->next=NULL; 
	
	//LIST2
	
	head2=n1[0];
	
	n1[0]->data=2;
	n1[0]->next=n1[1];
	
	n1[1]->data=6;
	n1[1]->next=n[4];   //merge Point 
	
	
	
	
	cout<<mergePoint(head1,head2);
	
}
