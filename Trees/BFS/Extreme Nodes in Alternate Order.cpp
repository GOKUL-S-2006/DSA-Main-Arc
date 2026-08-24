/* Structure of a binary tree Node
 class Node {
public:
    int data;
    Node* left;
    Node* right; 
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> extremeNodes(Node* root) {
        // code here
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        int l=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            if(l%2==0){
                ans.push_back(q.back()->data);
            }
            else{
                ans.push_back(q.front()->data);
            }
            
            int ls=q.size();
            for(int i=0;i<ls;i++){
              Node* node=q.front();
              q.pop();
              if(node->left){
                  q.push(node->left);
              }
              if(node->right){
                  q.push(node->right);
              }
            }
            l++;
        }
        return ans;
    }

TC: O(N)
SC: O(N)
};
