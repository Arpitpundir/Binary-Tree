class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int> > mp;
        queue<pair<TreeNode*, int> > q;
        vector<vector<int> > ans;
        if(!root) return ans;
        
        q.push({root, 0});
        q.push({NULL, 0});
        /*
        * initialize queue with root and NULL
        * store node and its horizontal distance in map
        * vertical distance will be taken care by bfs
        * when processing a node push this node to map in its horizontal distance vector
        */
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode *currNode = curr.first;
            int currDist = curr.second;
            
            if(currNode == NULL){
                if(!q.empty()){
                    q.push({NULL, -1});
                }
                continue;
            }
            
            if(mp.find(currDist) == mp.end()){
                mp[currDist] = {};
            }
            mp[currDist].push_back(currNode->val);
            
            if(currNode->left){
                q.push({currNode->left, currDist-1});
            }
            
            if(currNode->right){
                q.push({currNode->right, currDist+1});
            }
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};