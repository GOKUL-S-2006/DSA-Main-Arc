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
    void helper(TreeNode* root,vector<int>&arr){
        if(root==nullptr){
            arr.push_back(INT_MAX);
            return;
        }
        arr.push_back(root->val);
        helper(root->left,arr);
        helper(root->right,arr);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int>v1;
        vector<int>v2;
        helper(root,v1);
        helper(subRoot,v2);
        auto it = search(v1.begin(), v1.end(), v2.begin(), v2.end());
        return it!=v1.end();
    }
};
