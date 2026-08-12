/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root , int maxTillNow){
        if(root == nullptr){
            return 0;
        }
        int goodNodes=0;
        
        if(root->val >= maxTillNow)goodNodes++;

        maxTillNow = max( maxTillNow , root->val );

        goodNodes += solve(root->left , maxTillNow);
        goodNodes += solve(root->right , maxTillNow);

        return goodNodes ;

    }

    int goodNodes(TreeNode* root) {
          return solve(root , INT_MIN);  
    }
};