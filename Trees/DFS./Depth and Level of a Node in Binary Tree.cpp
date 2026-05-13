#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Function to find depth
int findDepth(TreeNode* root, int target, int depth = 0) {

    if (root == NULL) {
        return -1;
    }

    // Target found
    if (root->val == target) {
        return depth;
    }

    // Search left
    int left = findDepth(root->left, target, depth + 1);

    if (left != -1) {
        return left;
    }

    // Search right
    return findDepth(root->right, target, depth + 1);
}

int main() {

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int target = 5;

    int depth = findDepth(root, target);

    if (depth != -1) {

        int level = depth + 1;

        cout << "Depth of node " << target
             << " = " << depth << endl;

        cout << "Level of node " << target
             << " = " << level << endl;
    }
    else {
        cout << "Node not found";
    }

    return 0;
}


Using DFS recursion:

Time  : O(n)
Space : O(h)



