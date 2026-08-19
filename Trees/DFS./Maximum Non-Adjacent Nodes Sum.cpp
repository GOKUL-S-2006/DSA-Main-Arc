Brute Force:

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
    int getMaxSum(Node *root) {
        // code here
        if(root==nullptr) return 0;
        
        int include_node=root->data;
        if(root->left){
            include_node+=getMaxSum(root->left->left);
            include_node+=getMaxSum(root->left->right);
        }
        if(root->right){
            include_node+=getMaxSum(root->right->left);
            include_node+=getMaxSum(root->right->right);
        }
        
        int exclude_node=getMaxSum(root->left)+getMaxSum(root->right);
        return max(include_node,exclude_node);
    }
};

Complexity	Brute Force
Time	O(2ⁿ)
Space	O(h) → worst O(n)



Optimized:

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
   unordered_map<Node*,int>mpp;
  
    int getMaxSum(Node *root) {
        // code here
        if(root==nullptr) return 0;
        if(mpp[root]) return mpp[root];
        
        int include_node=root->data;
        if(root->left){
            include_node+=getMaxSum(root->left->left);
            include_node+=getMaxSum(root->left->right);
        }
        if(root->right){
            include_node+=getMaxSum(root->right->left);
            include_node+=getMaxSum(root->right->right);
        }
        
        int exclude_node=getMaxSum(root->left)+getMaxSum(root->right);
        return mpp[root]=max(include_node,exclude_node);
    }
};


|                 | Complexity       |
| --------------- | ---------------- |
| **Time**        | **O(n)** average |
| **Space**       | **O(n)**         |
| HashMap         | O(n)             |
| Recursion stack | O(h), worst O(n) |

