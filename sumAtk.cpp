#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

void printInorder(node *root){
  if(root == NULL){
    return;
  }
  printInorder(root->left);
  cout<<(root->val)<<" ";
  printInorder(root->right);
  return;
}
node* build(int val, int child){

   node *newNode = new node;
   newNode->val = val;

   if(child == 0){
     return newNode;
   }
   if(child == 1){

     int temp1, temp2;
     cin>>temp1>>temp2;

     if(temp1 < newNode->val){
       newNode->left = build(temp1, temp2);
     }else{
       newNode->right = build(temp1, temp2);
     }

     return newNode;
   }

   int temp1, temp2;
   cin>>temp1>>temp2;

   newNode->left = build(temp1, temp2);

   cin>>temp1>>temp2;

   newNode->right = build(temp1, temp2);

   return newNode;
}

int sumAtK(node *root, int k){
  if(root == NULL){
    return 0;
  }

  deque<node*> qu;
  qu.push_back(root);
  qu.push_back(NULL);

  int level = 0;
  int ans = 0;

  while(!qu.empty()){

    node *curr = qu.front();
    qu.pop_front();

    if(curr == NULL){
      if(qu.front() != NULL){
        level++;
        qu.push_back(NULL);
      }else{
        return 0;
      }
    }
    
    else if(level == k){
      while(curr != NULL){
        ans += curr->val;//1
        curr = qu.front();
        qu.pop_front();
      }
      return ans;
    }
    
    else{      
      qu.push_back(curr->left);
      qu.push_back(curr->right);
    }
  }
}

int main(){

  int val, child;
  cin>>val>>child;

  node *root = build(val, child);
  //printInorder(root);//2
  int k;
  cin>>k;

  cout<<sumAtK(root, k)<<endl;
}