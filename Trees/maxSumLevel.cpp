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

int maxSumLevel(struct TreeNode* root)
{
   int level=0,maxlevel=0,currsum=0,maxsum=0;
   struct TreeNode* temp;
   queue<TreeNode*> q;
   if(root==NULL)
   return 0;
   
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
   		temp=q.front();
   		q.pop();
   		if(temp)
   		{
   			currsum+=temp->data;
   			if(temp->left)
   			q.push(temp->left);
   			if(temp->right)
   			q.push(temp->right);
   		}
   		else
   		{
   			if(currsum>maxsum)
   			{
   				maxsum=currsum;
   				maxlevel=level;
   			}
   			currsum=0;
   			if(!q.empty())
   			{
   				q.push(NULL);
   			}
   			level++;
   		}
   }
   return maxlevel;
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
	insert(5);
	insert(7);
	insert(4);
	insert(1);
	insert(1);
	insert(1);
	insert(6);
	
	inorder(root);
	cout<<endl;
	cout<<maxSumLevel(root);
}
