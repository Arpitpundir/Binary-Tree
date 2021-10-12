#include<bits/stdc++.h>
using namespace std;

class node {
  public:
  int val;
  int hd;
  node *right;
  node *left;
  node(int val){
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

node* build(){

  int d;
cin>>d;

node*root = new node(d);
queue<node*> q;
q.push(root);

while(!q.empty()){

	node*f = q.front();
	q.pop();
	int c1,c2;
	cin>>c1>>c2;

	if(c1!=-1){
		f->left = new node(c1);
		q.push(f->left);
	}
	if(c2!=-1){
		f->right = new node(c2);
		q.push(f->right);
	}
}
return root;
}

void topView(node *root){
  map<int, int> m;
  deque<node*> q;
  root->hd = 0;

  q.push_back(root);
  q.push_back(NULL);

  while(!q.empty()){

    node* root = q.front();
    q.pop_front();

    if(root == NULL){
      if(q.front() == NULL)
      break;
      else
      q.push_back(NULL);
    }else{

      if(m.count(root->hd) == 0)
      m[root->hd] = root->val;


      if(root->left != NULL){
        root->left->hd = root->hd-1;
        q.push_back(root->left);
      }

      if(root->right != NULL){
        root->right->hd = root->hd+1;
        q.push_back(root->right);
      }
    }
  }
  map<int, int>::iterator i;
  for(i = m.begin(); i != m.end(); i++){
    cout<<i->second<<" ";
  }
}

int main(){
  node *root = build();
  topView(root);
  return 0;
}