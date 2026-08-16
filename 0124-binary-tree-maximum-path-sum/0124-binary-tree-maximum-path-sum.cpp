class Solution {
public:

    int dfs(TreeNode* root, int& ans) {

        if (root == nullptr)
            return 0;

        int left = max(0, dfs(root->left, ans));
        int right = max(0, dfs(root->right, ans));

        // Best path passing through this node
        int current = root->val + left + right;

        // Update global maximum
        ans = max(ans, current);

        // Return the best single branch to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;

        dfs(root, ans);

        return ans;
    }
};