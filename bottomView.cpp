#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

unordered_map<int, pair<int, int> > mp;
int minDist = INT_MAX;
int maxDist = INT_MIN;

void bottomView(node *root, int height, int dist){
  if(root == NULL){
    return;
  }

  if(mp.find(height) != mp.end()){
    if(mp[height].first <= height){
      //cout<<"1 "<<dist<<" "<<root->val<<endl;
      mp[dist] = make_pair(height, root->val);
    }
  }else{
    mp[dist] = make_pair(height, root->val);
        //  cout<<"2 "<<dist<<" "<<root->val<<endl;

  }

  if(dist < minDist)
  minDist = dist;

  if(dist > maxDist)
  maxDist = dist;
  bottomView(root->left, height+1, dist-1);
  bottomView(root->right, height+1, dist+1);
}

node* build(){
  
  node *root = new node;

  int val;
  cin>>val;
  if(val == -1){
    return NULL;
  }
  root->val = val;

  deque<node*> dq;
  dq.push_back(root);
  int c1, c2;

  while(!dq.empty()){

    node *curr = dq.front();
    dq.pop_front();
    cin>>c1;
    if(c1 != -1){
      curr->left = new node;
      curr->left->val = c1;
      dq.push_back(curr->left);
    }

    cin>>c2;
    if(c2 != -1){
      curr->right = new node;
      curr->right->val = c2;
      dq.push_back(curr->right);
    }
  }
  return root;
}

void inOrder(node *root){
  if(root == NULL){
    return;
  } 

  inOrder(root->left);
  cout<<root->val;
  inOrder(root->right);

}

int main(){

  node *root = build();
  //inOrder(root);
  bottomView(root,0,0);
  for(int i = minDist;i <= maxDist;i++){
 //   cout<<i<<" ";
    cout<<mp[i].second<<" ";
  }
}