// User function Template for C++

/* Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
  public:
    bool helper(Node* root,int &c){
        if(root==nullptr){
            return true;
        }
        bool left=helper(root->left,c);
        bool right=helper(root->right,c);
        
        if (left == false || right == false)
                return false;
        
        if(root->left && root->data!=root->left->data){
            return false;
        }
        if(root->right && root->data!=root->right->data){
            return false;
        }
        
       
        c++;
        
        return true;
    }
    int singlevalued(Node *root) {
        // code here
        int c=0;
        helper(root,c);
        return c;
    }
};
