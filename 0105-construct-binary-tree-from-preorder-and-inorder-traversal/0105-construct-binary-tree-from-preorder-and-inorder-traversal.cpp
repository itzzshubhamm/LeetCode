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

   TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart , int inEnd, unordered_map<int , int>& hashMap){

    if(inStart > inEnd){
        return nullptr;
    }

    int rootValue = preorder[preIndex];
    preIndex++;

    TreeNode* root = new TreeNode(rootValue);
    int inIndex = hashMap[rootValue];

    root->left = build(preorder, inorder, inStart, inIndex-1, hashMap);
    root->right = build(preorder, inorder, inIndex+1, inEnd, hashMap);

    return root;

   }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int> hashMap;
        for(int i=0; i<inorder.size(); i++){
           hashMap[inorder[i]] =  i;
        }

        return build(preorder, inorder, 0, inorder.size()-1, hashMap);
    }
};