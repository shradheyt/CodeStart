#include<iostream>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} *root=NULL;


bool searchInTree(struct TreeNode* root,int data)
{
	if(root==NULL)
	return false;
	struct TreeNode* ptr;
	queue<TreeNode*> q;
	q.push(root);
	
	while(!q.empty())
	{
		ptr=q.front();
		q.pop();
		
		if(ptr->data==data)
		return true;
		
		if(ptr->left)
		q.push(ptr->left);
		
		if(ptr->right)
		q.push(ptr->right);
	}
return false;

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
    
    newNode[6]->data =10;
    newNode[6]->left=NULL;
    newNode[6]->right=NULL;
	
	int n;
	cin>>n;
	cout<<"Search Result"<<endl;
	cout<<searchInTree(root,n);
	cout<<endl;
	

}
