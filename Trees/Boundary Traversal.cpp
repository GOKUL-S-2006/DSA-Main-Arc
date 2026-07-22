class Solution {
public:

    // Add left boundary
    void addLeftBoundary(TreeNode* root, vector<int>& ans) {

        TreeNode* curr = root->left;

        while (curr) {

            // Don't add leaf nodes
            if (curr->left || curr->right) {
                ans.push_back(curr->val);
            }

            // Prefer left child
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    // Add all leaf nodes
    void addLeaves(TreeNode* root, vector<int>& ans) {

        if (!root) {
            return;
        }

        // If leaf node
        if (!root->left && !root->right) {
            ans.push_back(root->val);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    // Add right boundary
    void addRightBoundary(TreeNode* root, vector<int>& ans) {

        vector<int> temp;

        TreeNode* curr = root->right;

        while (curr) {

            // Don't add leaf nodes
            if (curr->left || curr->right) {
                temp.push_back(curr->val);
            }

            // Prefer right child
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        // Add right boundary in reverse order
        reverse(temp.begin(), temp.end());

        for (int x : temp) {
            ans.push_back(x);
        }
    }

    vector<int> boundaryTraversal(TreeNode* root) {

        vector<int> ans;

        if (!root) {
            return ans;
        }

        // Add root
        if (root->left || root->right) {
            ans.push_back(root->val);
        }

        // Left boundary
        addLeftBoundary(root, ans);

        // Leaf nodes
        addLeaves(root, ans);

        // Right boundary
        addRightBoundary(root, ans);

        return ans;
    }
};
