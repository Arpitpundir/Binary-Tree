vector<int> bottomView(node* root){
    unordered_map<int, int> hdMap;
    queue<pair<node*, int> > q;
    vector<int> ans;
    if(!root) return ans;
    q.push({root,0});
    q.push({NULL, -1});
    /*
    * use iterative level order traversal
    * in queue push a paitr of node and its horizontal distance
    * maintain a map of horizontal distance and last node encountered at that distance
    */
    while(!q.empty()){
        auto currPair = q.front();
        q.pop();
        node *currNode = currPair.first;
        int currHd = currPair.second;
        
        if(!currNode){
            if(!q.empty()) q.push({NULL,-1});
            continue;
        }
        hdMap[currHd] = currNode->val;
        if(currNode->left){
            q.push({currNode->left, currHd-1});
        }
        if(currNode->right){
            q.push({currNode->right, currHd+1});
        }
    }
    for(auto ite=hdMap.begin(); ite != hdMap.end(); ite++){
        ans.push_back(ite->second);
    } 
    return ans;  
}