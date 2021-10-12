#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

node* buildFromPre(vector<int> pre){
  stack<node*> st;
  int n = pre.size();
  node *root = new node;
  root->val = pre[0];
  st.push(root);

  for(int i = 1;i < n;i++){
cout<<"jk"<<endl;
cout<<st.top()->val<<endl;
cout<<st.empty()<<endl;
    node *newNode = new node;
    newNode->val = pre[i];

    node *temp = NULL;

    while(!st.empty() && st.top()->val < pre[i]){
cout<<"jk"<<endl;
      //so while the new value to be inserted is greater than st top till than pop out element
      //and when it stops than temp will store the value of such node which is the largest node which
      //is smaller than curr node and if temp is null than this node is the left node of out stack top
      temp = st.top();
      st.pop();
    }
    cout<<"jkl"<<endl;

    if(temp != NULL){
      cout<<"not NULL "<<temp->val<<" "<<newNode->val<<endl;
      temp->right = newNode;
      st.push(newNode);
    }else{
      cout<<"NULL "<<st.top()->val<<" "<<newNode->val<<endl;
      st.top()->left = newNode;
      st.push(newNode);
    }
  }
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
  int n;
  cin>>n;
  vector<int> pre;

  while(n--){
    int temp;
    cin>>temp;
    pre.push_back(temp);
  }

  node *root = buildFromPre(pre);
  inOrderPrint(root);
}