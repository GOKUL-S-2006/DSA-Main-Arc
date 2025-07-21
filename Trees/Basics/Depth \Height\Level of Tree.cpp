int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

Time Complexity: O(n)

Space Complexity: O(h) (recursion stack)
