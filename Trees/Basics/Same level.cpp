bool areAtSameLevel(TreeNode* root, int x, int y) {
    if (!root) return false;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        bool foundX = false, foundY = false;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == x) foundX = true;
            if (node->val == y) foundY = true;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // If both found at same level
        if (foundX && foundY) return true;

        // If only one found at this level
        if (foundX || foundY) return false;
    }

    return false; // Not found
}

Time: O(n) – visit all nodes at worst

Space: O(w) – max width of tree (queue size)


int getLevel(TreeNode* root, int target, int level) {
    if (!root) return 0;
    if (root->val == target) return level;

    int left = getLevel(root->left, target, level + 1);
    if (left != 0) return left;

    return getLevel(root->right, target, level + 1);
}

bool areAtSameLevel(TreeNode* root, int x, int y) {
    int levelX = getLevel(root, x, 1);
    int levelY = getLevel(root, y, 1);
    return levelX != 0 && levelX == levelY;
}


Time Complexity: O(n)
(each node is visited once while searching for x and y)

Space Complexity: O(h)
(due to recursive call stack, where h is tree height)

