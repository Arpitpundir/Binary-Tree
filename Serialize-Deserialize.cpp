class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        vector<int> levelOrder;
        string serializedTree;
        queue<TreeNode*> q;
        q.push(root);
        levelOrder.push_back(root->val);
        while(!q.empty()){
            TreeNode *topNode = q.front();
            q.pop();
            if(topNode->left != NULL){
                q.push(topNode->left);
                levelOrder.push_back(topNode->left->val);
            }else{
                levelOrder.push_back(-1001);
            }
            if(topNode->right != NULL){
                q.push(topNode->right);
                levelOrder.push_back(topNode->right->val);
            }else{
                levelOrder.push_back(-1001);
            }
        }
        int n = levelOrder.size();
        for(int i=0;i<n;i++){
            serializedTree += (to_string(levelOrder[i])+"/");
        }
        return serializedTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(n == 0) return NULL;
        vector<int> treeNodeValue;
        int i=0;
        while(i<n){
            int j = i;
            while(data[j] != '/'){
                j++;
            }
            treeNodeValue.push_back(stoi(data.substr(i, j-i)));
            i = j+1;
        }

        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(treeNodeValue[0]);
        q.push(root);
        i = 1;
        /*
        * since tree is not a complete binary tree we can not use 2*i`th and 2*i+1`th element to get left and right child
        * we will use index i to keep track of next child to be added
        */
        while(!q.empty()){
            TreeNode *topNode = q.front();
            q.pop();
            int leftChildValue = treeNodeValue[i], rightChildValue = treeNodeValue[i+1];
            i+=2;
            if(leftChildValue != -1001){
                topNode->left = new TreeNode(leftChildValue);
                q.push(topNode->left);
            }else{
                topNode->left = NULL;
            }

            if(rightChildValue != -1001){
                topNode->right = new TreeNode(rightChildValue);
                q.push(topNode->right);
            }else{
                topNode->right = NULL;
            }
        }
        return root;
    }
};