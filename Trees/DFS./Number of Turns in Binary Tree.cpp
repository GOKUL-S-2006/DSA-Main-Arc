/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
   
  Node* lca(Node* root, int p, int q) {
         if (root == nullptr) return nullptr;

         if (root->data == p || root->data == q)
             return root;

         Node* left = lca(root->left, p, q);
         Node* right = lca(root->right, p, q);

         if (left && right) return root;

         return left ? left : right;
     }

    
    bool trav(Node* start,int &v,vector<int>&arr){
        if(start==nullptr){
            return false;
        }
        arr.push_back(start->data);
        if (start->data == v) return true;
        
       if (trav(start->left, v, arr)) {
            return true;
        }

        if (trav(start->right, v, arr)) {
            return true;
        }

        arr.pop_back();
        return false;
        
        
        
        
    }
    void init(Node* root,map<int,char>&mpp){
        if(root==nullptr){
            return;
        }
        init(root->left,mpp);
        if(root->left!=nullptr){
            mpp[root->left->data]='L';
        }
         if(root->right!=nullptr){
            mpp[root->right->data]='R';
            
        }
        init(root->right,mpp);
        
    }
    
    int numberOfTurns(Node* root, int p, int q) {
       
        
        map<int, char> mpp;
            init(root, mpp);

            Node* start = lca(root, p, q);

            vector<int> arr1, arr2;
            trav(start, p, arr1);
            trav(start, q, arr2);
            string path = "";

            // Climbing from p up to LCA: label each edge by the child's side
            for (int i = arr1.size() - 1; i >= 1; i--) {
                path += mpp[arr1[i]];
            }

            // Descending from LCA to q: label each edge by the child's side
            for (int i = 1; i < arr2.size(); i++) {
                path += mpp[arr2[i]];
            }
            int turns = 0;

            for (int i = 1; i < path.size(); i++) {
                if (path[i] != path[i - 1]) {
                    turns++;
                }
            }

            return turns==0?-1:turns;
        
        
        
        
        
    }
};
