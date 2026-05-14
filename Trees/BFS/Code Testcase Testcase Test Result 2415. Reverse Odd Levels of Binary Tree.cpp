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
    TreeNode* reverseOddLevels(TreeNode* root) {
         if (root == nullptr) {
            
            return root; 
        }
        
        
        queue<TreeNode*> q; 
        
        q.push(root); 
        int i=0;

        while (!q.empty()) {
           
            int size = q.size(); 
            
            vector<TreeNode*> level; 

            for (int i = 0; i < size; i++) {
                
                TreeNode* node = q.front(); 
                
                q.pop(); 
                
                level.push_back(node); 

               
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if(i%2!=0){
            int n=level.size();
            for(int i=0;i<n/2;i++){
                swap(level[i]->val,level[n-i-1]->val);
            }
            }
            i++;
            
           // ans.push_back(level); 
        }
        
    
        return root; 
    }
};
