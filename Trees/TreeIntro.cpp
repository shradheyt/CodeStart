#include<iostream>

using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} *root=NULL;

void inorder(struct TreeNode* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<< " ";
	inorder(root->right);
	
}
int main()
{
	
	struct TreeNode* newNode=new TreeNode;
	
	newNode->data =9;
	newNode->right=NULL;
	newNode->left=NULL;
	root=newNode;
	inorder(root);
	
}
