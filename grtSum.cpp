#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

int modify(node *&root, int sum){
  if(root == NULL){
    return sum;
  }

  sum = modify(root->right, sum);
  sum +=root->val;
  root->val = sum;
  return modify(root->left, sum);
}

node* build(int arr[],int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	int mid=(s+e)/2;
	node* root=new node;
  root->val = arr[mid];
	root->left=build(arr,s,mid-1);
	root->right=build(arr,mid+1,e);
    return root;
}

void preOrder(node *root){
  if(root == NULL){
    return;
  }
  cout<<root->val<<" ";
  preOrder(root->left);
  preOrder(root->right);
  return;
}

int main()
{
	node* root=NULL;
	int n,a[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	root=build(a,0,n-1);
	modify(root, 0);
	preOrder(root);

  return 0;
}