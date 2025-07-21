bool areSiblings(TreeNode* root, int x, int y) {
    if (root == nullptr) return false;

    // Check if current node has both children
    if (root->left && root->right) {
        int leftVal = root->left->val;
        int rightVal = root->right->val;

        if ((leftVal == x && rightVal == y) || (leftVal == y && rightVal == x)) {
            return true;
        }
    }

    // Recur for left and right subtrees
    return areSiblings(root->left, x, y) || areSiblings(root->right, x, y);
}

Time Complexity: O(n) – You may have to check all nodes.

Space Complexity:

Worst case: O(n) (skewed tree)

Average case: O(h) (height of the tree due to recursion stack)
