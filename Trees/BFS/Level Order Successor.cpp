#include <iostream>
#include <queue>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find level order successor
TreeNode* findLevelOrderSuccessor(TreeNode* root, int key) {
    if (!root) return nullptr;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // Push children before checking for successor
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);

        if (current->val == key) {
            return q.empty() ? nullptr : q.front();
        }
    }

    return nullptr;
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int key = 3;
    TreeNode* successor = findLevelOrderSuccessor(root, key);

    if (successor)
        cout << "Level Order Successor of " << key << " is " << successor->val << endl;
    else
        cout << "No Level Order Successor found for " << key << endl;

    return 0;
}



Complexity	Value
Time	O(N)
Space (Aux)	O(N)
