/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    int helper(Node* root,vector<bool>&arr){
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            arr.push_back(true);
            return root->data;
        }
        int lv=helper(root->left,arr);
        int rv=helper(root->right,arr);
        if(lv+rv==root->data){
            arr.push_back(true);
        }
        else{
            arr.push_back(false);
            
        }
        return root->data;
    }
    bool isSumProperty(Node *root) {
        // code here
        vector<bool>arr;
        helper(root,arr);
        for(auto x:arr){
            if(x==false){
                return false;
            }
        }
        return true;
        
        
    }
};


optimized

/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    
    bool isSumProperty(Node *root) {
        // code here
       
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;
        }

        int leftVal = (root->left) ? root->left->data : 0;
        int rightVal = (root->right) ? root->right->data : 0;

        if (root->data == leftVal + rightVal) {
            return isSumProperty(root->left) && isSumProperty(root->right);
        }

        return false;
    }
};


