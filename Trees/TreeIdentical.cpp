#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
}*root1=NULL,*root2=NULL;

struct TreeNode* createNode(int data)
{
	struct TreeNode* newNode=new TreeNode;
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

struct TreeNode* insert(int data,struct TreeNode* root)
{
	struct TreeNode* newNode=createNode(data);
	struct TreeNode* temp;
	queue<TreeNode*> q;
	if(!newNode)
	cout<<"memory error";
	if(root==NULL)
	{
		root=newNode;
		return root;
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
			return root;
		}
		
		if(temp->right)
		q.push(temp->right);
		else
		{
			temp->right=newNode;
			return root;
		}
	}
	return root;
}

bool areIdentical(struct TreeNode* root1,struct TreeNode* root2)
{
	if(root1==NULL&&root2==NULL)
	return true;
	if(root1==NULL || root2==NULL)
	return false;
	
	return(root1->data==root2->data &&areIdentical(root1->left,root2->left) && areIdentical(root1->right,root2->right));
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
	root1=insert(1,root1);
	root1=insert(2,root1);
	root1=insert(3,root1);
	root1=insert(4,root1);
	root1=insert(5,root1);
	root1=insert(6,root1);
	root1=insert(8,root1);
	inorder(root1);
	cout<<endl;
	
	root2=insert(1,root2);
	root2=insert(2,root2);
	root2=insert(3,root2);
	root2=insert(4,root2);
	root2=insert(5,root2);
	root2=insert(6,root2);
	root2=insert(8,root2);
	inorder(root2);
	cout<<endl;
	
	cout<<areIdentical(root1,root2);
	
}
