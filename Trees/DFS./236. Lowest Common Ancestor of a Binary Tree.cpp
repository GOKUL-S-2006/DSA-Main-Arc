/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

BACKTRACKING


class Solution {
public:
      bool search(TreeNode* root, TreeNode* key, vector<TreeNode*>& arr) {
    if (root == nullptr) return false;

    arr.push_back(root);

    if (root == key)
        return true;

    if (search(root->left, key, arr))
        return true;

    if (search(root->right, key, arr))
        return true;

    arr.pop_back();  // backtrack
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return root;
        }
        vector<TreeNode*>arr1;
        vector<TreeNode*>arr2;
        search(root,p,arr1);
        search(root,q,arr2);
        int i=0;
        int j=0;
        TreeNode* anc;
        while(i<arr1.size() && j<arr2.size()){
             if(arr1[i]==arr2[j]){
                anc=arr1[i];
             }
             i++;
             j++;
        }
        return anc;

    }
};


✅ TC = O(n)

DFS

  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return nullptr;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left && right){
            return root;
        }
        return left==nullptr?right:left;
    }
};

  
