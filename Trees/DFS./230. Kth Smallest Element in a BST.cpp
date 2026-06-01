BRUTE FORCE:

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
     void inorder(TreeNode*  root,vector<int>&arr){
        if(root==nullptr){
            return;
        }
           inorder(root->left,arr);
           arr.push_back(root->val);
           inorder(root->right,arr);
     }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,arr);
        return arr[k-1];


    }
};

Time: O(n)
Space: O(n)

2. Better Solution


class Solution {
public:
    int cnt = 0;
    int ans = -1;

    void inorder(TreeNode* root, int k) {
        if (!root) return;

        inorder(root->left, k);

        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};


Time: O(n)
Space: O(h)

3. Optimized (Inorder)

  void inorder(TreeNode* root, int k) {
    if (!root || cnt >= k) return;

    inorder(root->left, k);

    cnt++;
    if (cnt == k) {
        ans = root->val;
        return;
    }

    inorder(root->right, k);
}

Time: O(h + k) with early stopping.
Space: O(h) recursion stack.
