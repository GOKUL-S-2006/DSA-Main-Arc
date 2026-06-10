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
      void helper(TreeNode* root,int &c,int maxv,int el ){
        if(root==nullptr){
            return;
        }
        maxv=max(maxv,root->val);
        if(maxv<=root->val){
            c++;
        }

        helper(root->left,c,maxv,el);
        helper(root->right,c,maxv,el);


      }
    int goodNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int c=0;
        int el=root->val;
        int maxv=INT_MIN;
        helper(root,c,maxv,el);
        return c;
    }
};
