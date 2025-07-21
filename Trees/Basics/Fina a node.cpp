 Recursive DFS 

TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr) return nullptr;

    if (root->val == val) return root;

    TreeNode* leftSearch = findNode(root->left, val);
    if (leftSearch) return leftSearch;

    return findNode(root->right, val);
}

✅ Time Complexity: O(n)
Visits each node at most once (in worst case, if value is at the bottom or not present).

✅ Space Complexity:
Worst case (skewed tree): O(n) stack depth

Best case (balanced): O(h) where h is tree height



  
Iterative BFS (Using Queue):


TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node->val == val) return node;

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return nullptr; // Not found
}

Time Complexity: O(n)
Every node is enqueued and dequeued once.

✅ Space Complexity: O(w)
Queue holds up to one level → max width of tree w
