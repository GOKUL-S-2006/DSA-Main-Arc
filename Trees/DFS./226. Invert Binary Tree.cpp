class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL) {
            return NULL;
        }

        TreeNode* l = invertTree(root->left);
        TreeNode* r = invertTree(root->right);

        root->left = r;
        root->right = l;

        return root;
    }
};

Complexity
Time → O(n)

Because every node visited once.

Space → O(h)

Recursive stack height.

Formula:

T(n)=T(left)+T(right)+O(1)
