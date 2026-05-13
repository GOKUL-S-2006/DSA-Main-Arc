#include <iostream>
#include <algorithm>
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

class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Diameter through current node
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};

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

    Solution obj;

    cout << "Diameter = "
         << obj.diameterOfBinaryTree(root);

    return 0;
}


Time Complexity
O(n)

Each node is visited only once.

Space Complexity
O(h)

Where:

h = height of tree
Due to recursion call stack
Worst Case

(skewed tree)

O(n)
Best / Balanced Tree
O(log n)
