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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&mpp){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }

        TreeNode* root=new TreeNode(preorder[preStart]);
        int rootIndex=mpp[root->val];
        int numsLeft=rootIndex-inStart;
        root->left=buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,rootIndex-1,mpp);
        root->right=buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,rootIndex+1,inEnd,mpp);
        return root;



    }
};


TC:O(N)
SC:O(N)
