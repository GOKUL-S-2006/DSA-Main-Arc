#include <iostream>
#include <queue>
using namespace std;

// Tree Node Structure
class Node {
public:
    int data;
    Node *left, *right;
    Node(int item) {
        data = item;
        left = right = NULL;
    }
};

// Deep-check: Verifies if EVERY node in the subtree matches 'val'
bool isUnivalue(Node* node, int val) {
  
  if (node == NULL) return true;
  if (node->data != val) return false;
    return isUnivalue(node->left, val) && isUnivalue(node->right, val);
}

int countSingle(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    queue<Node*> q;
    q.push(root);

    // BFS Traversal: Visit every node in the tree
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Independent Audit: Check the entire subtree of the current node
        if (isUnivalue(curr, curr->data)) {
            count++;
        }

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return count;
}

int main() {
    
    /* Constructing the specific tree:
              5
             / \
            4   5
           / \   \
          4   4   5
    */
    Node* tree = new Node(5);
    tree->left = new Node(4);
    tree->right = new Node(5);
    
    tree->left->left = new Node(4);
    tree->left->right = new Node(4);
    
    tree->right->right = new Node(5);

    cout << "The count of single valued subtrees is: " << countSingle(tree) << endl;

    return 0;
}
