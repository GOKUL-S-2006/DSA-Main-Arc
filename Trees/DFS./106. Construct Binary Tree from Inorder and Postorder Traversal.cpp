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
    
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd,
                     vector<int>& postorder, int postStart, int postEnd,
                     unordered_map<int, int>& mp) {
        
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        // Last element in postorder is the root
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int rootIndex = mp[root->val];

        // Number of nodes in left subtree
        int leftSize = rootIndex - inStart;

        // Build left subtree
        root->left = helper(
            inorder, inStart, rootIndex - 1,
            postorder, postStart, postStart + leftSize - 1,
            mp
        );

        // Build right subtree
        root->right = helper(
            inorder, rootIndex + 1, inEnd,
            postorder, postStart + leftSize, postEnd - 1,
            mp
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return helper(
            inorder, 0, inorder.size() - 1,
            postorder, 0, postorder.size() - 1,
            mp
        );
    }
};
