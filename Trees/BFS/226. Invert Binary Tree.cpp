class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL)
            return NULL;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            // swap children
            swap(curr->left, curr->right);

            // push left child
            if(curr->left)
                q.push(curr->left);

            // push right child
            if(curr->right)
                q.push(curr->right);
        }

        return root;
    }
};


Complexity

Time:

O(n)

Every node visited once.

Space:

O(w)

where:

w = maximum width of tree (queue size)
