#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right, *nextRight;
    Node(int val) {
        data = val;
        left = right = nextRight = nullptr;
    }
};

// Return the first node on the right
// side of q and at the next level
Node *getNextRight(Node *p) {

    Node *temp = p->nextRight;

    // Keep moving to next sibling until
    // you find a sibling that has at least
    // one children
    while (temp != nullptr) {
        if (temp->left != nullptr)
            return temp->left;
        if (temp->right != nullptr)
            return temp->right;
        temp = temp->nextRight;
    }

    return nullptr;
}

// Function to connect nodes at the same level
Node* connect(Node *root) {

    Node *temp;
    if (!root)
        return nullptr ;

    root->nextRight = nullptr;
    
    while (root != nullptr) {
        Node *q = root;

        // Traverse all nodes at the current level
        while (q != nullptr) {
            if (q->left) {

                if (q->right)
                    q->left->nextRight = q->right;
                else
                    q->left->nextRight = getNextRight(q);
            }

            if (q->right)
                q->right->nextRight = getNextRight(q);
            q = q->nextRight;
        }

        // Move to the next level starting with the leftmost node
        if (root->left)
            root = root->left;
        else if (root->right)
            root = root->right;
        else
            root = getNextRight(root);
    }
    
    return root;
}

// Print level order using nextRight pointers
void printLevels(Node* root) {
    Node* levelStart = root;

    while (levelStart != nullptr) {
        Node* curr = levelStart;

        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->nextRight;
        }

        cout << "# ";

        // Find the first node of the next level
        if (levelStart->left != nullptr)
            levelStart = levelStart->left;
        else if (levelStart->right != nullptr)
            levelStart = levelStart->right;
        else
            break;
    }
}

int main() {

    // Constructed binary tree
    //       10
    //      /  \
    //    8     2
    //   /     /      
    //  3     4     

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->left = new Node(4);

    connect(root);
    printLevels(root);
    return 0;
}

 O(n) Time 
O(1) Space 


