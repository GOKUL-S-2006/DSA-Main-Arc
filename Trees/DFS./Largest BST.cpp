Brute Force:

Code:
/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
      int maxc=0;
      bool inorder(Node* root, int &prev,int &c) {
	    if (!root) 
	      	return true;

	    // Recursively check the left subtree
	    if (!inorder(root->left, prev,c)) 
	      	return false;

	    // Check the current node value 
	    // against the previous value
	    if (prev >= root->data) 
	      	return false;

	    prev = root->data;
	    c++;

	    // Recursively check the right subtree
	    return inorder(root->right, prev,c);
	}

      int largestBst(Node *root) {
          if(root == nullptr)
              return 0;

    
          int prev = INT_MIN;
          int c=0;
          if(inorder(root, prev,c)) {
              maxc = max(maxc, c);
          }

          largestBst(root->left);
          largestBst(root->right);

          return maxc;
      }
};

|                    | Complexity          |
| ------------------ | ------------------- |
| **Time**           | **O(n²)**           |
| **Space**          | **O(n)** worst case |
| Balanced tree time | **O(n log n)**      |


