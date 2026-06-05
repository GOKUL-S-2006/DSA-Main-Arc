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
    vector<int>arr;
    void helper(TreeNode* root,string s){
        if(root==nullptr){
            return;
        }
        s+=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr){
            arr.push_back(stoi(s));
        }
        helper(root->left,s);
        helper(root->right,s);

    }
    int sumNumbers(TreeNode* root) {
        //string s=""
        helper(root,"");
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return sum;
    }
};


class Solution {
public:
    int dfs(TreeNode* root, int num) {
        if (!root) return 0;

        num = num * 10 + root->val;

        if (!root->left && !root->right)
            return num;

        return dfs(root->left, num) +
               dfs(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};





