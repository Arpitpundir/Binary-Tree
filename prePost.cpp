#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node* left;
  node* right;
  node(int val){
    this->val=val;
    this->left=NULL;
    this->right=NULL;
  }
};

int preInd=0;
node* build(int st, int end, vector<int> pre, vector<int> post){
  if(st>end){
    return NULL;
  }
  node* root=new node(pre[preInd++]);

  if(st==end){
    return root;
  }
  int mid;
  for(int i=st;i<=end;i++){
    if(post[i]==pre[preInd]){
      mid=i;
      break;
    }
  }
  root->left=build(st,mid,pre,post);
  root->right=build(mid+1,end-1,pre,post);
  return root;
}

void inorder(node* root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->val;
  inorder(root->right);
}

int main(){
  int n;
  cin>>n;
  vector<int> pre,post;
  for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    pre.push_back(temp);
  }
  for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    post.push_back(temp);
  }
  node* root=build(0, n-1, pre, post);
  inorder(root);
}