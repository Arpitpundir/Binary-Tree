#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left;
  node *right;
  node(){
    this->left = NULL;
    this->right = NULL;
  }
  node(int val){
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

node *head = NULL;
node *tail = NULL;

void printLL(node *head){
  node *temp = head;
  while(temp->right != NULL){
    cout<<temp->val<<" ";
    temp = temp->right;
  }
}

void soln(node* &root){

  if(root == NULL){
    cout<<"kl"<<endl;
    return;
  }
  //if(root->val == 3)
  cout<<"st"<<" "<<root->val;
  if(root->right != NULL)
  cout<<"rtv1"<<" "<<root->right->val<<endl;
  soln(root->left);
  
  if (root->right != NULL)
    cout << "rtv2"<< " " << root->right->val << endl;
  if(head == NULL){
    head = root;
  }else{
    tail->right = root;
    root->left = tail;
    cout<<"rtv"<<" "<<root->val<<endl;
    if(root->right != NULL)
    cout<<"else"<<" "<<root->right->val<<endl;
  }

  tail = root;
  cout<<"tl"<<" "<<tail->val<<endl;
  if(root->right != NULL)
  cout<<"rt"<<root->right->val<<endl;
  if (root->val == 6)
  return;
  soln(root->right);
cout<<root->val<<endl;
  return;
}

int main() 
{ 
    // Let us create binary tree given in 
    // the above example 
    node *root = new node(1); 
    cout<<root->val<<endl;
    root->left = new node(2);

    root->right = new node(3);

    root->left->left = new node(4); 

    root->left->right = new node(5);

    root->right->left = new node(6);

    root->right->right = new node(7);

    root->right->left->right = new node(8); 

    cout<<root->right->left->right->val<<endl;

    soln(root);

    tail->right = NULL;

    cout<<tail->val<<endl;

    printLL(head);

    return 0; 
} 
