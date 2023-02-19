vector<int> leftView(Node *root)
{
    queue<pair<Node*, int> > q;
    q.push({root, 0});
    int level = -1;
    vector<int> ans;
    if(!root) return ans;
    
    /*
    * use iterative level order traversal
    * in queue push a paitr of node and its level
    * maintain a currLevel, if node's level is greater than currLevel then this is the first node in that level
    * push this node to ans
    */
    while(!q.empty()){
        auto currPair = q.front();
        q.pop();
        Node* currNode = currPair.first;
        int currNodeLevel = currPair.second;
        
        if(currNodeLevel > level){
            ans.push_back(currNode->data);
            level = currNodeLevel;
        }
        if(currNode->left){
            q.push({currNode->left, currNodeLevel+1});
        }
        if(currNode->right){
            q.push({currNode->right, currNodeLevel+1});
        }
    }
    return ans;
}