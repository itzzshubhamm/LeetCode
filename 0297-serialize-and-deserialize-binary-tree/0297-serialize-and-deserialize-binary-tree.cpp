/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializerHelper(TreeNode* root, string& answer){
        if(root == nullptr){
           answer+= "null,";
           return;
        }

        answer += to_string(root->val);
        answer += ",";
        serializerHelper(root->left, answer);
        serializerHelper(root->right, answer);
        
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string answer;
        serializerHelper(root, answer);
        return answer;
    }

    TreeNode* deserializerHelper(stringstream& ss){
        string word;
        getline(ss, word, ',');
        if(word == "null"){
            return nullptr;
        }
          
        TreeNode* root = new TreeNode(stoi(word));

        root->left = deserializerHelper(ss);
        root->right = deserializerHelper(ss);

        return root;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializerHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));