class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int, Node*> mp;
        queue<pair<Node*, int> > q;
        q.push({root, 0}); q.push({NULL, 0});
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            Node* currNode = curr.first;
            int currDist = curr.second;
            
            if(currNode == NULL){
                if(!q.empty()){
                    q.push({NULL,0});
                }
                continue;
            }
            
            if(mp.find(currDist) == mp.end()){
                mp[currDist] = currNode;
            }
            if(currNode->left){
                q.push({currNode->left, currDist-1});
            }
            if(currNode->right){
                q.push({currNode->right, currDist+1});
            }
        }
        
        for(auto it: mp){
            ans.push_back(it.second->data);
        }
        return ans;
    }

};