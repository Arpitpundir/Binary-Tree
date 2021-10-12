class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        vector<vector<int> > ans;
        if(root==NULL)
        return ans;
        ans.push_back({});

        st1.push(root);
        bool isLR=true;
        int level=0;
        while(!st1.empty()||!st2.empty()){
            TreeNode* curr;
            if(isLR){
                curr=st1.top();
                ans[level].push_back(curr->val);
                st1.pop();
                if(curr->left){
                    st2.push(curr->left);
                }
                if(curr->right){
                    st2.push(curr->right);
                }
                if(st1.empty()&&!st2.empty()){
                    isLR=false;
                    level++;
                    ans.push_back({});
                }
            }else{
                curr=st2.top();
                ans[level].push_back(curr->val);
                st2.pop();
                if(curr->right){
                    st1.push(curr->right);
                }
                if(curr->left){
                    st1.push(curr->left);
                }
                if(st2.empty()&&!st1.empty()){
                    isLR=true;
                    level++;
                    ans.push_back({});
                }
            }
        }
    //    ans.pop_back();
        return ans;
    }
};