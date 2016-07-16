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


int findMax(struct TreeNode* root)
{
	int max=INT_MIN;
	struct TreeNode* temp;
	queue<TreeNode*> q;
	
	q.push(root);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		
		if(max<temp->data)
		max=temp->data;
		
		if(temp->left)
		q.push(temp->left);
		
		if(temp->right)
		q.push(temp->right);
	}
	
	return max;
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
	
	cout<<"Maximum Element"<<endl;
	cout<<findMax(root);
	cout<<endl;
	

}
