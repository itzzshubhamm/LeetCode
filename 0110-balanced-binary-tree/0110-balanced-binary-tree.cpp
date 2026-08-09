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
    int heightBalance(TreeNode* root){ 
        if(root == NULL){
           return 0; 
        }

        int leftSide = heightBalance(root->left);

        if(leftSide == -1){
            return -1;
        }

        int rightSide = heightBalance(root->right);

        if(rightSide == -1){
            return -1;
        }

        if(abs(leftSide - rightSide) > 1){
            return -1;
        }

        return 1 + max(leftSide , rightSide);


    }


    bool isBalanced(TreeNode* root) {
        return heightBalance(root) != -1;
    }
};