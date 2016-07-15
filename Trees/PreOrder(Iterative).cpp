#include<iostream>
#include<stack>
using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} *root=NULL;

//Preorder Interative Traversal
void preorder(struct TreeNode* root)
{
	stack<TreeNode*> s;
	while(true)
	{
		while(root)
		{
			cout<<root->data<<" ";
			s.push(root);
			root=root->left;
		}
		if(s.empty())
		break;
		root=s.top();
		s.pop();
		root=root->right;
		
	}
	
	
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
	

}
