class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > ans;
        if(!root) return ans;
        
        vector<int> currLevel;
        /*
        *   1. Push root to queue
        *   2. Push NULL to queue
        *   3. Pop from queue and push to currLevel
        *   4. If currNode is not there check if tree is complete by checking if queue is empty
        *   5. If queue is not empty push NULL to queue
        *   6. Push currLevel to ans
        *   7. Clear currLevel
        *   8. Repeat from step 3
        */
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode *currNode = q.front();
            q.pop();
            if(!currNode){
                if(!q.empty()) q.push(NULL); //mistake: missed this case
                ans.push_back(currLevel);
                currLevel = {};
                continue;
            }
            currLevel.push_back(currNode->val);
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
        }
        return ans;
    }
};