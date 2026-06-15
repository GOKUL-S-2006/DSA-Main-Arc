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
    TreeNode* helper(vector<long long int>arr,int i,int j){
          if(i>j){
            return nullptr;
          }
          long long int mid=i+(j-i)/2;
          TreeNode *node=new TreeNode(arr[mid]);
          node->left=helper(arr,i,mid-1);
          node->right=helper(arr,mid+1,j);
          return node;

    }
    void inorder(TreeNode* root,vector<long long int>&arr){
        if(root==nullptr){
            return;
        }
       
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root==nullptr) return root;
        vector<long long int>arr;
        inorder(root,arr);
       long long  int n=arr.size();
        root=helper(arr,0,n-1);
        return root;
    }
};
