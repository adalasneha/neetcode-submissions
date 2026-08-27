class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (node == nullptr || k == 0)
                return;

            inorder(node->left);

            k--;

            if (k == 0) {
                result = node->val;
                return;
            }

            inorder(node->right);
        };

        inorder(root);
        return result;
    }
};