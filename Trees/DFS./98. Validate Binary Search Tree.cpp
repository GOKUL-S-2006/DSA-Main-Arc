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
    void inorder(TreeNode* root,vector<int>&arr){
        if(root==nullptr){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                continue;
            }
            return false;
        }
        return 1;
    }
};


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
      bool helper(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high)
            return false;

        return helper(root->left, low, root->val) &&
               helper(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
