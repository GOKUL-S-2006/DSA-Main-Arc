// C++ code of print all paths from root node
// to leaf node using recursion.
#include <iostream>
#include <vector>
using namespace std;

class Node{
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

void collectPaths(Node *node, vector<int> &path, vector<vector<int>> &paths)
{
    if (node == nullptr)
        return;

    // Append this node to the path
    path.push_back(node->data);

    // If it's a leaf node, store the path
    if (node->left == nullptr && node->right == nullptr)
    {
        paths.push_back(path);
    }
    else
    {

        // Otherwise, try both subtrees
        collectPaths(node->left, path, paths);
        collectPaths(node->right, path, paths);
    }

    // Backtrack: remove the last element
    // from the path
    path.pop_back();
}

// Function to get all paths from root to leaf
vector<vector<int>> Paths(Node *root)
{
    vector<vector<int>> paths;
    vector<int> path;
    collectPaths(root, path, paths);
    return paths;
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> res = Paths(root);
    for (auto &row : res){
        
        for (int val : row){
        
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
