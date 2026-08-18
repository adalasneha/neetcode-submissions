class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if (root == nullptr)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (i == levelSize - 1) {
                    ans.push_back(curr->val);
                }
                
                if (curr->left)
                    q.push(curr->left);
                
                if (curr->right)
                    q.push(curr->right);
            }
        }
        
        return ans;
    }
};