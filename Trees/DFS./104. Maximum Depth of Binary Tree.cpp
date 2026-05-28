#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepthDFS(TreeNode* root) {
    if (root == NULL) return 0;

    int leftDepth = maxDepthDFS(root->left);
    int rightDepth = maxDepthDFS(root->right);

    return 1 + max(leftDepth, rightDepth);
}
