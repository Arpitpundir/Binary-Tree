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

node* deleteBst(node *&root, int val){
  if(root == NULL){
    return NULL;
  }
  if(root->val == val){
    if(root->left == NULL && root->right == NULL){
      return NULL;
    }

    if(root->left != NULL && root->right == NULL){
      node *temp = root->left;
      delete root;
      return temp;
    }else if(root->left == NULL && root->right != NULL){
      node *temp = root->right;
      delete root;
      return temp;
    }

    node *temp = root->right;
    while(temp->left != NULL){
      temp = temp->left;
    }
    root->val = temp->val;
    deleteBst(root->right, temp->val);
    return root;
  }

  root->left = deleteBst(root->left, val);
  root->right = deleteBst(root->right, val);
  return root;
}

void inOrderPrint(node *root){
  if(root == NULL){
    return;
  }
  inOrderPrint(root->left);
  cout<<root->val<<" ";
  inOrderPrint(root->right);
}

int main(){
  node* root = NULL;
  buildBst(root);
  inOrderPrint(root);
  int temp;
  cin>>temp;
  deleteBst(root, temp);
  inOrderPrint(root);
}

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//Accepts the old root node & data and returns the new root node
node *insertInBST(node *root, int data)
{
    //Base Case
    if (root == NULL)
    {
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if (data <= root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node *deleteInBST(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = deleteInBST(root->left, data);
        return root;
    }
    else if (data == root->data)
    {
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        //3. Case 2 children
        node *replace = root->right;
        //Find the inorder successor from right subtree
        while (replace->left != NULL)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    }
    else
    {
        root->right = deleteInBST(root->right, data);
        return root;
    }
}

void printPreOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        node *root = NULL;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            root = insertInBST(root, x);
        }

        int m;
        cin >> m;

        while (m--)
        {
            int temp;
            cin >> temp;
            root = deleteInBST(root, temp);
        }

        printPreOrder(root);
        cout << endl;
    }

    return 0;
}