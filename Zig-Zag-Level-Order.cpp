class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> l,r;
        bool L = true, R = false;
        vector<vector<int> > ans;
        if(!root) return ans;
        else 
        l.push(root);
        vector<int> currLevel;
        /*
        * initilize left stack with root
        * process left first and mark L as true
        * while processing left push children in right stack
        * push right children later as they need to be processed first
        * when done with left stack mark L as false and R as true and push currLevel to ans
        * clear currLevel
        */
        while(!l.empty() || !r.empty()){
            if(L){ // curr level is Left to right
                TreeNode* curr = l.top();
                l.pop();
                currLevel.push_back(curr->val);
                if(curr->left){
                    r.push(curr->left);
                }
                if(curr->right){
                    r.push(curr->right);
                }
                if(l.empty()){
                    L=false;
                    R=true;
                    ans.push_back(currLevel);
                    currLevel = {};
                }
            }else{
                TreeNode* curr = r.top();
                r.pop();
                currLevel.push_back(curr->val);
                if(curr->right){
                    l.push(curr->right);
                }
                if(curr->left){
                    l.push(curr->left);
                }
                if(r.empty()){
                    R=false;
                    L=true;
                    ans.push_back(currLevel);
                    currLevel = {};
                }
            }
        }
        return ans;
    }
};