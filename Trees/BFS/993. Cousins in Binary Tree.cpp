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
    bool isCousins(TreeNode* root, int x, int y) {
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

                // Check if x and y are children of the same parent
                if (node->left && node->right) {
                    int l = node->left->val;
                    int r = node->right->val;
                    if ((l == x && r == y) || (l == y && r == x)) {
                        return false; // Same parent => not cousins
                    }
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // If both found at same level and not siblings
            if (foundX && foundY) return true;

            // If only one found => not cousins
            if (foundX || foundY) return false;
        }

        return false; // Not found
    }
};



class Solution {
public:
    // Get level of a node with given value
    int getLevel(TreeNode* root, int val, int level) {
        if (!root) return 0;
        if (root->val == val) return level;

        int left = getLevel(root->left, val, level + 1);
        if (left != 0) return left;

        return getLevel(root->right, val, level + 1);
    }

    // Check if two nodes are siblings
    bool areSiblings(TreeNode* root, int x, int y) {
        if (!root) return false;

        if (root->left && root->right) {
            int l = root->left->val;
            int r = root->right->val;
            if ((l == x && r == y) || (l == y && r == x)) {
                return true;
            }
        }

        // Check recursively in left and right subtree
        return areSiblings(root->left, x, y) || areSiblings(root->right, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int levelX = getLevel(root, x, 1);
        int levelY = getLevel(root, y, 1);

        // Same level but not siblings
        return (levelX == levelY) && !areSiblings(root, x, y);
    }
};
