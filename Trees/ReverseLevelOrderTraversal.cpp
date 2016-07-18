#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
}*root=NULL;

struct TreeNode* createNode(int data)
{
	struct TreeNode* newNode=new TreeNode;
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

void insert(int data)
{
	struct TreeNode* newNode=createNode(data);
	struct TreeNode* temp;
	queue<TreeNode*> q;
	if(!newNode)
	cout<<"memory error";
	if(root==NULL)
	{
		root=newNode;
		return ;
	}
	
	q.push(root);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		
		if(temp->left)
		q.push(temp->left);
		else
		{
			temp->left=newNode;
			return;
		}
		
		if(temp->right)
		q.push(temp->right);
		else
		{
			temp->right=newNode;
			return;
		}
	}
}

void reverseLevelOrder(struct TreeNode* root)
{
	struct TreeNode* temp;
	queue<TreeNode*> q;
	stack<TreeNode*> s;
	
	if(root==NULL)
	return;
	q.push(root);
	
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp->right)
		q.push(temp->right);
		if(temp->left)
		q.push(temp->left);
		
		s.push(temp);
	}
		struct TreeNode* t;
	while(!s.empty())
	{
		
		t=s.top();
		s.pop();
		cout<<t->data<<" ";
	}
}

int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	reverseLevelOrder(root);
}
