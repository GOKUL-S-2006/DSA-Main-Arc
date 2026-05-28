BFS SOLUTION:(OPTIMAL)
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
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int depth=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
            TreeNode* cnode=q.front();
            q.pop();
            if(cnode->left==nullptr && cnode->right==nullptr){
                return depth;
            }
           
            if(cnode->left!=nullptr){
                q.push(cnode->left);
            }
            if(cnode->right!=nullptr){
                q.push(cnode->right);
            }
            }
             depth++;
        }
        return depth;
        
    }
};

TC:O(N)
SC:O(N)



DFS Code


class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        // if left subtree doesn't exist
        if (root->left == nullptr) {
            return 1 + right;
        }

        // if right subtree doesn't exist
        if (root->right == nullptr) {
            return 1 + left;
        }

        // both children exist
        return 1 + min(left, right);
    }
};


Complexity	Value
Time	O(n)
Space	O(h) recursion stack

Where:

n = number of nodes
h = height of tree
