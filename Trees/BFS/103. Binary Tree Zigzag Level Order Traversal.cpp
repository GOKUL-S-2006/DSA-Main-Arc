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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         
        vector<vector<int>> ans;
        int i=0; 
        if (root == nullptr) {
            
            return ans; 
        }
        
        
        queue<TreeNode*> q; 
        
        q.push(root); 

        while (!q.empty()) {
           
            int size = q.size(); 
            
            vector<int> level; 

            for (int i = 0; i < size; i++) {
                
                TreeNode* node = q.front(); 
                
                q.pop(); 
                
                level.push_back(node->val); 

               
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if(i%2!=0){
            reverse(level.begin(),level.end());
            ans.push_back(level); 
            }
            else{
                ans.push_back(level);
            }
            i++;

        }
        
      
        return ans; 
    }
};

APPROCACH 2:
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();

                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;  // toggle direction
        }

        return ans;
    }
};

Time Complexity:
O(n)

Space Complexity:
O(n)
