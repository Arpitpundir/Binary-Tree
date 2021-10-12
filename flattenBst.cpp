#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

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
  int temp;
  cin>>temp;
  while(temp != -1){
    insertNode(root, temp);
    cin>>temp;
  }
}

void inOrderPrint(node *root){
  if(root == NULL){
    return;
  }
  inOrderPrint(root->left);
  cout<<root->val<<" ";
  inOrderPrint(root->right);
}

class LL{
  public:
  node *head;
  node *tail;
};

void printLL(LL l){
  node *temp = l.head;
  while(temp != NULL){
    cout<<temp->val<<" ";
    temp = temp->right;
  }
  cout<<endl;
}

LL flatten(node *root){
  LL newLL;
  if(root == NULL){
    newLL.head = NULL;
    newLL.tail = NULL;
    printLL(newLL);
    return newLL;
  }

  if(root->left == NULL && root->right == NULL){
    newLL.head = root;
    newLL.tail = root;
    printLL(newLL);

    return newLL;
  }
  
  //left tree exists and right tree do not exists

  if(root->left != NULL && root->right == NULL){
    LL leftLL = flatten(root->left);

    newLL.head = leftLL.head;
    leftLL.tail->right = root;

    newLL.tail = root;
    printLL(newLL);

    return newLL;
  }

  //right tree exists and left tree do not exists

  if(root->left == NULL && root->right != NULL){
    LL rightLL = flatten(root->right);

    newLL.head = root;

    root->right = rightLL.head;

    newLL.tail = rightLL.tail;
    printLL(newLL);

    return newLL;
  }

  //if both right and left tree exists

  LL leftLL = flatten(root->left);
  LL rightLL = flatten(root->right);

  newLL.head = leftLL.head;

  leftLL.tail->right = root;

  root->right = rightLL.head;

  newLL.tail = rightLL.tail;
  printLL(newLL);

  return newLL;
}

int main(){
  node* root = NULL;
  buildBst(root);

  LL bstLL = flatten(root);
  bstLL.tail->right = NULL;
  node *temp = bstLL.head;
  while(temp != NULL){
    cout<<temp->val<<" ";
    temp = temp->right;
  }

  return 0;
}