#include<iostream>

using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} *root=NULL;

//Preorder Traversal
void preorder(struct TreeNode* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<< " ";
	preorder(root->left);
	preorder(root->right);
}
//Inorder Traversal
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
//Postorder Traversal
void postorder(struct TreeNode* root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<< " ";
	
}


int main()
{
	struct TreeNode* newNode[7];
	for(int i=0;i<7;i++)
	{
		newNode[i]=new TreeNode;
	}
	root=newNode[0];
	
	newNode[0]->data =9;
    newNode[0]->left=newNode[1];
    newNode[0]->right=newNode[2];
    
    newNode[1]->data =1;
    newNode[1]->left=newNode[3];
    newNode[1]->right=newNode[4];
    
    newNode[2]->data =2;
    newNode[2]->left=newNode[5];
    newNode[2]->right=newNode[6];
    
    newNode[3]->data =5;
    newNode[3]->left=NULL;
    newNode[3]->right=NULL;
    
    newNode[4]->data =3;
    newNode[4]->left=NULL;
    newNode[4]->right=NULL;
    
    newNode[5]->data =8;
    newNode[5]->left=NULL;
    newNode[5]->right=NULL;
    
    newNode[6]->data =7;
    newNode[6]->left=NULL;
    newNode[6]->right=NULL;
	
	cout<<"PreOrder Traversal"<<endl;
	preorder(root);
	cout<<endl;
	
	cout<<"InOrder Traversal"<<endl;
	inorder(root);
	cout<<endl;
	
	cout<<"PostOrder Traversal"<<endl;
	postorder(root);
	cout<<endl;
}
