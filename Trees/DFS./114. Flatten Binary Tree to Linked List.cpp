BRUTE FORCE

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
    void preorder(TreeNode*root ,vector<TreeNode*>&arr){
        if(root==nullptr){
            return;
        }
        arr.push_back(root);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*>arr;
        preorder(root,arr);
        if(arr.empty()) return;
        for(int i=1;i<arr.size();i++){
            arr[i-1]->left=nullptr;
            arr[i-1]->right=arr[i];
        }
        int n=arr.size();
        arr[n-1]->right=nullptr;
        arr[n-1]->left=nullptr;
        

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

OPTIMAL
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        TreeNode* cur=root;
        while(cur!=nullptr){
              if(cur->left!=nullptr){
                TreeNode* temp=cur->left;
                while(temp->right!=nullptr){
                    temp=temp->right;
                }
                temp->right=cur->right;
                cur->right=cur->left;
                cur->left=nullptr;
              }
            cur=cur->right;

        }
    }
};
