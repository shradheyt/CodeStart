#include<iostream>
#include<queue>
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

int heightOfTree(struct TreeNode* root)
{
	if(root==NULL)
	return 0;
	int level=0;
	queue<TreeNode*> q;
	struct TreeNode* temp;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		
		if(temp==NULL)
		{
			if(!q.empty())
			q.push(NULL);
			
			level++;
			
		}
		else
		{
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
		}
	}
	return level;
}
void inorder(struct TreeNode* root)
{
	if(root==NULL)
	return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
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
	inorder(root);
	cout<<endl;
	cout<<heightOfTree(root);
}
