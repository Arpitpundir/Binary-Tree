#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

void printPreorder(node *root){
  if(root == NULL){
    return;
  }
  cout<<(root->val)<<" ";
  printPreorder(root->left);
  printPreorder(root->right);
  return;
}

void insertNode(node *&root, int val){
  if(root == NULL){
    root = new node;
    root->val = val;
    return;
  }
  if(val < root->val){
    insertNode(root->left, val);
    return;
  }
  insertNode(root->right, val);
  return;
}
void buildBst(node *&root){
  int n;
  cin>>n;
  while(n--){
    int temp;
    cin>>temp;
    insertNode(root, temp);
  }
}

void printInRange(node *root, int k1, int k2){
  if(root == NULL){
    return;
  }

  if(root->val <= k1){
	  if(root->val == k1)
          cout<<root->val<<" ";

    printInRange(root->right, k1, k2);
    return;
  }

  if(root->val >= k2){

    printInRange(root->left, k1, k2);
	if(root->val == k2)
    cout<<root->val<<" ";

    return;
  }

  printInRange(root->left, k1, k2);

   cout<<root->val<<" ";
  printInRange(root->right, k1, k2);

  return;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    node *root = NULL;
    buildBst(root);
    cout<<"# Preorder : ";
    printPreorder(root);
    cout<<endl;
    int k1, k2;
    cin>>k1>>k2;
    cout<<"# Nodes within range are : ";
    printInRange(root, k1, k2);
  }
}