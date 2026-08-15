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
   int preIndex = 0;

   TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart , int inEnd){

    if(inStart > inEnd){
        return nullptr;
    }

    int rootValue = preorder[preIndex];
    preIndex++;

    TreeNode* root = new TreeNode(rootValue);
    int inIndex;
    for(inIndex = inStart ; inIndex <= inEnd ; inIndex++){
        if(inorder[inIndex] == rootValue)break;
    }

    root->left = build(preorder, inorder, inStart, inIndex-1);
    root->right = build(preorder, inorder, inIndex+1, inEnd);

    return root;

   }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};