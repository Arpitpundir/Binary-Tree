class Solution
{
      public:
      //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
      {
        queue<pair<Node*, int> > q;
        q.push({root, 0});
        int level = -1;
        vector<int> ans;
        if(!root) return ans;
        
        while(!q.empty()){
            auto currPair = q.front();
            q.pop();
            Node* currNode = currPair.first;
            int currNodeLevel = currPair.second;
            
            if(currNodeLevel > level){
                ans.push_back(currNode->data);
                level = currNodeLevel;
            }
            if(currNode->right){
                q.push({currNode->right, currNodeLevel+1});
            }
            if(currNode->left){
                q.push({currNode->left, currNodeLevel+1});
            }
        }
        return ans;
      }
};