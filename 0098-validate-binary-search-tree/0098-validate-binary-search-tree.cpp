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
    bool check(TreeNode* root , long long maxVal , long long minVal){
        if(root == nullptr){
            return true;
        }
        if(root->val <= minVal || root->val >= maxVal){
            return false;
        }

        return check(root->left , root->val , minVal) && check(root->right , maxVal , root->val);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root , LLONG_MAX , LLONG_MIN);
    }
};